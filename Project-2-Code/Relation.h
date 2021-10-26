//
// Created by Juliana Smith on 10/25/21.
//

#ifndef CS_236_LAB_1_RELATION_H
#define CS_236_LAB_1_RELATION_H
#include "Header.h"
#include "Tuple.h"
#include <iostream>
#include <set>

using namespace std;

class Relation {
private:
    string name;
    Header header;
    set<Tuple> rows;
public:
    Relation(){}
    Relation(string n){
        name = n;
        header = Header();
    }
    Relation(string n, Header h){
        name = n;
        header = h;
    }
    Header GetHeader(){
        return header;
    }
    void AddAttribute(string a){ header.AddAttribute(a);}
    string GetName(){ return name; }
    Relation select (int index, string value);
    Relation select (int index1, int index2);
    Relation project (vector<int> indices);
    Relation rename (vector<string>attributes);
    void addTuple(Tuple t){ rows.insert(t);}
    string toString();

};

#endif //CS_236_LAB_1_RELATION_H
