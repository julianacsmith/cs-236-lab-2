//
// Created by Juliana Smith on 10/25/21.
//

#ifndef CS_236_LAB_1_DATABASE_H
#define CS_236_LAB_1_DATABASE_H
#include <map>
#include "Relation.h"
#include "Header.h"
#include "Tuple.h"

class Database{
private:
    map<string, Relation> relation;
public:
    Database(){}
    Database(std::string n){
        Relation r = Relation(n);
        relation.insert(std::pair<string, Relation>(n, r));
    }
    bool FindRelation(std::string n){
        if(relation.find(n) != relation.end()){
            return true;
        }
        return false;
    }
    void AddRelation(Relation r){
        relation.insert(std::pair<string, Relation>(r.GetName(), r));
    }
    void RemoveRelation(std::string n){
        relation.erase(n);
    }
    void AddTuple(std::string n, Tuple t){
        relation.at(n).addTuple(t);
    }
    Relation GetRelation(std::string name){
        return relation.at(name);
    }
};

#endif //CS_236_LAB_1_DATABASE_H
