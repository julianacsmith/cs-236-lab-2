//
// Created by Juliana Smith on 10/25/21.
//
#include "Relation.h"
#include <stdio.h>
#include <ctype.h>
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

Relation Relation::project(vector<int> indices) {
    string newName = "";
    Header h = Header();
    for(unsigned int i = 0; i < indices.size(); i++){
        string att = header.GetAttribute(indices.at(i));
        //string s(1, newName.at(i));
        h.AddAttribute(att);
    }
    Relation r = Relation(newName, h);
    int i = 0;// Creates a blank new relation
    for(Tuple t : rows){ // Goes through all the tuples
        Tuple tup = Tuple();
        for(int index : indices){
            int size = t.GetSize();
            if(index >= size){
                tup.SetValue(t.GetValue(i));
            } else {
                tup.SetValue(t.GetValue(index));
            }
            i++;
        }
        i=0;
        r.addTuple(tup);
    }
    return r;
}

Relation Relation::rename(vector<string> attributes) {
    /**Header h = header;
    for(unsigned int i = 0; i < attributes.size(); i++){
        h.SetAttribute(i, attributes.at(i));
    } **/
    Relation r = Relation(name, attributes);
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
            if (i < header.Size()){
                if(parsedHeader.find(header.GetAttribute(i)) == parsedHeader.end()) {
                    string attChecker = header.GetAttribute(i);// If we haven't addressed this header
                    map<string, int>::iterator it = variables.find(attChecker); // Set iterator to the index in variables
                    if (it != variables.end()) { // If it exists
                        string equals = header.GetAttribute(i) + "=" + t.GetValue(i); // Make a string with the potential added output
                        string check = output.substr(output.size() - 2, output.size() - 1); // Gets a substring
                        if ((check.find(' ') == string::npos || output.find(line) == string::npos)) { // If the substring is valid or line doesn't already exist within the output
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
    Header newh; // Create a new header
    for(int i = 0; i < h1.Size(); i++){ // Goes through the entirety of the first header
        string a = h1.GetAttribute(i); // Gets the current attribute
        ToLower(a);
        newh.AddAttribute(a); // Add new attribute
    }
    for(int i = 0; i < h2.Size(); i++){ // Goes through all of h2
        string a = h2.GetAttribute(i); // Gets the current attribute
        ToLower(a);
        if(!newh.AttributeExists(a)){ // If attribute doesnt exist in newh
            newh.AddAttribute(a); // Add new attribute
        }
    }
    return newh; // return the new header
}

bool Relation::isJoinable(Tuple t1, Tuple t2, vector<int> match) {
    if(match.size() == 0){ // If there are no matches
        return true; // Automatically return true
    } else { // Otherwise
        string val1;
        string val2;
        if(match.at(0) < t1.GetSize() && match.at(1) < t2.GetSize()) {
            val1 = t1.GetValue(match.at(0)); // Get the value from t1
            val2 = t2.GetValue(match.at(1)); // Get the value from t2
        } else if (match.at(0) < t1.GetSize()){
            val1 = t1.GetValue(match.at(0)); // Get the value from t1
            val2 = t2.GetValue(0);
        } else if (match.at(1) < t2.GetSize()){
            val1 = t1.GetValue(0); // Get the value from t1
            val2 = t2.GetValue(match.at(1));
        }
        if (val1 == val2) { // If the values in match are the same
            commonVar = val1; // Set the common Variable to val1
            return true; // Return true
        }
    }
    return false; // Nothing matches when there are supposed to be matches, then return false
}

Tuple Relation::combineTuples(Tuple t1, Tuple t2) {
    Tuple newT; // Create a new tuple
        for (int i = 0; i < t1.GetSize(); i++) { // Add all the elements from the first tuple
            string v = t1.GetValue(i); // Gets the value of the current position in tuple
            newT.SetValue(v); // Sets the value in newT
        }
        for (int i = 0; i < t2.GetSize(); i++) { // Goes through each element in t2
            string v = t2.GetValue(i); // Gets the value of the current element in tuple
            if(v != commonVar) { // If it's not the common variable (set in matching in Interpreter)
                newT.SetValue(v); // Set the value in the new tuple
            }
        }
    return newT; // return new tuple
}

Relation Relation::Join(Relation r2, vector<int> matches) {
    Relation r = Relation(); // New Relation
    r.SetHeader(CombineHeaders(this->header, r2.GetHeader())); // Set r's header to combine headers
    for (Tuple t1: rows) { // For every tuple in r1
        for (Tuple t2: r2.rows) { // For every tuple in r2
            if (isJoinable(t1, t2, matches)) { // If they are joinable
                Tuple newT = combineTuples(t1, t2); // Combine the tuples
                r.addTuple(newT); // Add new tuple to r
            }
        }
    }
    return r; // return r
}

bool Relation::Unity(Relation r2) {
    bool returnVal = false;
    unsigned int ogSize = rows.size();
    for (Tuple t : r2.rows){ // For every tuple in r2
        this->addTuple(t); // add tuple from r2 to this
    }
    if(this->rows.size() != ogSize){
        returnVal = true;
    }
    return returnVal;
}

string Relation::ToLower(string a) { // Sets the given string to lowercase. Helps when combining headers
    int i = 0;
    char c;
    while(a[i]){
        c = a[i];
        putchar(tolower(c));
        i++;
    }
    return a;
}