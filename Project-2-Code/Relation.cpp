//
// Created by Juliana Smith on 10/25/21.
//
#include "Relation.h"
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

Relation Relation::select(size_t index, string value){
    Relation r = Relation(name, header); // Creates a blank new relation
    for(Tuple t : rows){ // Goes through all the tuples
        if(t.GetValue(index) == value){ // If the current value in the tuple at the index matches the specified value
            r.addTuple(t); // add the entire tuple to the relation
        }
    }
    return r; // return the relation
}

Relation Relation::select(size_t index1, size_t index2) {
    Relation r = Relation(name, header); // Creates a blank new relation
    for(Tuple t : rows){ // Goes through all the tuples
        if(t.GetValue(index1) == t.GetValue(index2)){ // Of the two values within the tuple match
            r.addTuple(t); // add the entire tuple to the relation
        }
    }
    return r;
}

Relation Relation::project(vector<size_t> indices) {
    string newName = "";
    for(int index : indices){
        newName += name.at(index);
    }
    Header h = Header();
    for(unsigned int i = 0; i < newName.size(); i++){
        string s(1, newName.at(i));
        h.AddAttribute(s);
    }
    Relation r = Relation(newName, h); // Creates a blank new relation
    for(Tuple t : rows){ // Goes through all the tuples
        Tuple tup = Tuple();
        for(int index : indices){
            tup.SetValue(t.GetValue(index));
        }
        r.addTuple(tup);
    }
    return r;
}

Relation Relation::rename(vector<string> attributes) {
    Header h = header;
    for(unsigned int i = 0; i < attributes.size(); i++){
        h.SetAttribute(i, attributes.at(i));
    }
    Relation r = Relation(name, h);
    r.SetTuples(rows);
    return r;
}

string Relation::toString(map<string, int> variables) {
    string output = ""; // String to build final output
    string line; // Keeps track of the current line
    int itr = 0; // iterator to help keep track of the loops (for newline)
    for(Tuple t : rows){ // For each tuple
        output += "  "; // Indent accordingly
        for(int i = 0; i < t.GetSize(); i++) { // Loop through all values in tuple
            if(parsedHeader.find(header.GetAttribute(i)) == parsedHeader.end()) { // If we haven't addressed this header
                map<string, int>::iterator it = variables.find(header.GetAttribute(i)); // Set iterator to the index in variables
                if (it != variables.end()) { // If it exists
                    string equals = header.GetAttribute(i) + "=" + t.GetValue(i); // Make a string with the potential added output
                    string check = output.substr(output.size() -2, output.size() -1); // Gets a substring
                    if ((check.find(' ') == string::npos || output.find(line) == string::npos) ) { // If the substring is valid or line doesn't already exist within the output
                        output += ", "; // Add a comma
                    }
                    if (line.find(equals) == string::npos) { // If line doesn't contain equals
                        output += equals; // Add output to equals
                        line = equals; // Set line equal to what we;ve just added
                    }
                }
                parsedHeader.insert(header.GetAttribute(i)); // Add this current header to parsedHeader (keeps track of what we've touched already
            }
        }
        if(itr < Size() && output != "  ") { // While were still within the size limit and output isn't a "blank output"
            output += "\n"; // Make a new line
            line = ""; // Reset line variable
            parsedHeader.clear(); // clear parsedHeader
        }
        itr++;
    }
    if(output == "  "){ // If a "blank output"
        return "";
    }
    return output;
}

Header Relation::CombineHeaders(Header h1, Header h2) {
    Header newh;
    for(int i = 0; i < h1.Size(); i++){ // Goes through the entirety of the first header
        string a = h1.GetAttribute(i); // Gets the current attribute
        if(!newh.AttributeExists(a)){ // If attribute doesnt exist in newh
            newh.AddAttribute(a); // Add new attribute
        }
    }
    for(int i = 0; i < h2.Size(); i++){ // Goes through all of h2
        string a = h2.GetAttribute(i); // Gets the current attribute
        if(!newh.AttributeExists(a)){ // If attribute doesnt exist in newh
            newh.AddAttribute(a); // Add new attribute
        }
    }
    return newh; // return the new header
}

bool Relation::isJoinable(Tuple t1, Tuple t2, vector<string> match) {
    bool canJoin = true;
    for(int i = 0; i < t1.GetSize(); i++){
        if(find(match.begin(), match.end(), t1.GetValue(i)) != match.end()){
            int pos2 = t2.FindValPos(t1.GetValue(i));
            if(t1.GetValue(i) != t2.GetValue(pos2)){
                canJoin = false;
            }
        }
    }
    return canJoin;
}

Tuple Relation::combineTuples(Tuple t1, Tuple t2) {
    Tuple newT;
    for(int i = 0; i < t1.GetSize(); i++){
        string v = t1.GetValue(i);
        if(!newT.ValExists(v)){
            newT.SetValue(v);
        }
    }
    for(int i = 0; i < t2.GetSize(); i++){
        string v = t2.GetValue(i);
        if(!newT.ValExists(v)){
            newT.SetValue(v);
        }
    }
    return newT;
}

Relation Relation::Join(Relation r2) {
    Header newHeader = CombineHeaders(header, r2.header); // Combines the headers
    Relation newRelation; // Creates a blank new relation
    newRelation.header = newHeader; // Sets the new header
    vector<string> matching = FindMatch(r2);
    for(Tuple t1 : rows){ // For every tuple in r1
        for(Tuple t2 : r2.rows){ // For every tuple in r2
            if(isJoinable(t1, t2, matching)) {
                Tuple newT = combineTuples(t1, t2); // Combine the tuples (This calls isJoinable)
                newRelation.addTuple(newT); // Add new tuple to the relation
            }
        }
    }
    return newRelation; // Return the filled relation
}

vector<std::string> Relation::FindMatch(Relation r2) {
    vector<string> matches;
    for(int i = 0; i < header.Size(); i++){
        if(r2.header.FindAttribute(header.GetAttribute(i)) != -1){
            matches.push_back(header.GetAttribute(i));
        }
    }
    return matches;
}

Relation Relation::Unity(Relation r2) {
    Relation r;
    r.header = header;
    for(Tuple t: r2.rows){
        if(rows.insert(t).second){
            r.addTuple(t);
        }
    }
    return r;
}
