//
// Created by Juliana Smith on 10/25/21.
//

#ifndef CS_236_LAB_1_RELATION_H
#define CS_236_LAB_1_RELATION_H
#include "Header.h"
#include "Tuple.h"
#include <iostream>
#include <set>
#include <map>

using namespace std;

class Relation {
private:
    string name;
    Header header;
    set<Tuple> rows;
    bool hasConst = false;
    set<string> parsedHeader;
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
    Header GetHeader(){ return header; }
    string GetAttribute(int pos) { return header.GetAttribute(pos); }
    void SetAttribute(int pos, string val) {header.SetAttribute(pos, val); }
    void SetHeader (Header h){ header = h; }
    void SetTuples (set<Tuple> r){ rows = r;}
    bool IsEmpty(){
        if(rows.empty()){
            return true;
        }
        return false;
    }
    int Size(){ return rows.size();}
    void SetConst(bool c){ hasConst = c; }
    bool HasConst(){ return hasConst; }
    void AddAttribute(string a){ header.AddAttribute(a);}
    string GetName(){ return name; }
    Relation select (size_t index, string value);
    Relation select (size_t index1, size_t index2);
    Relation project (vector<size_t> indices);
    Relation rename (vector<string>attributes);
    void addTuple(Tuple t){ rows.insert(t);}
    string toString(map<string, int> variables);

};

#endif //CS_236_LAB_1_RELATION_H
