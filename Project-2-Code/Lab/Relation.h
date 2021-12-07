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
    bool firstPass = true;
    string commonVar;
    set<Tuple> originals;
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
    set<Tuple> GetTuples(){return rows;}
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
    void SetName(string n) {name = n;}
    Relation select (size_t index, string value);
    Relation select (size_t index1, size_t index2);
    Relation project (vector<int> indices);
    Relation rename (vector<string>attributes);
    Relation Join (Relation r2, vector<int> matches);
    Relation Unity(Relation r2, bool& addedTuple);
    Header CombineHeaders(Header h1, Header h2);
    bool isJoinable(Tuple t1, Tuple t2, vector<int> match);
    Tuple combineTuples(Tuple t1, Tuple t2);
    vector<int> FindMatch(Relation r2);
    bool addTuple(Tuple t){ return rows.insert(t).second;}
    string toString(map<string, int> variables);
    string ToLower(string a);
    string ToUpper(string a);
    void ResetPass(){ firstPass = false; }
};

#endif //CS_236_LAB_1_RELATION_H
