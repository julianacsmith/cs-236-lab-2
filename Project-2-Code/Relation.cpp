//
// Created by Juliana Smith on 10/25/21.
//
#include "Relation.h"
#include <iostream>
#include <string>
using namespace std;

Relation Relation::select(int index, string value){
    string newName (1, name.at(index)); // Sets the new name of the relation
    Header h = Header();
    h.AddAttribute(header.GetAttribute(index));
    Relation r = Relation(newName, h); // Creates a blank new relation
    for(Tuple t : rows){ // Goes through all the tuples
        if(t.GetValue(index) == value){ // If the current value in the tuple at the index matches the specified value
            r.addTuple(t); // add the entire tuple to the relation
        }
    }
    return r; // return the relation
}

Relation Relation::select(int index1, int index2) {
    string newName (1, name.at(index1)); // Sets the new name of the relation
    newName += name.at(index2);
    Header h = Header();
    h.AddAttribute(header.GetAttribute(index1));
    h.AddAttribute(header.GetAttribute(index2));
    Relation r = Relation(newName, h); // Creates a blank new relation
    for(Tuple t : rows){ // Goes through all the tuples
        if(t.GetValue(index1) == t.GetValue(index2)){ // Of the two values within the tuple match
            r.addTuple(t); // add the entire tuple to the relation
        }
    }
    return r;
}

Relation Relation::project(vector<int> indices) {
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
    string newName = "";
    for(string index : attributes){
        newName += index;
    }
    Header h = Header();
    for(unsigned int i = 0; i < newName.size(); i++){
        string s(1, newName.at(i));
        h.AddAttribute(s);
    }
    Relation r = Relation(newName, h); // Creates a blank new relation
    for(Tuple t : rows){
        r.addTuple(t);
    }
    return r;
}

string Relation::toString() {
    string output = "";
    for(Tuple t : rows){
        for(int i = 0; i < t.GetSize()-1; i++){
            output += header.GetAttribute(i) + "='" + t.GetValue(i);
            if(i != t.GetSize()-1){
                output += ", ";
            }
        }
        output += "\n";
    }
    return output;
}
