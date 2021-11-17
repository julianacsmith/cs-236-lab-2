//
// Created by Juliana Smith on 10/25/21.
//
#include "Relation.h"
#include <iostream>
#include <string>
#include <map>
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
