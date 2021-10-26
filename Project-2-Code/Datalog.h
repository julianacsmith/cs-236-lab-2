//
// Created by Juliana Smith on 10/26/21.
//

#ifndef CS_236_LAB_1_DATALOG_H
#define CS_236_LAB_1_DATALOG_H
#include "Parameter.h"
#include "Rule.h"
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Datalog {
private:
    vector<Predicate> schemes;
    vector<Predicate> facts;
    vector<Predicate> queries;
    vector<Rule> rules;
    set<string> domain;
public:
    Datalog(){}
    ~Datalog(){}
    void AddScheme(Predicate s){
        schemes.push_back(s);
    }
    void AddFacts(Predicate f){
        facts.push_back(f);
    }
    void AddQueries(Predicate q){
        queries.push_back(q);
    }
    void AddRules(Rule r){
        rules.push_back(r);
    }
    void SetDatalog(set<string> d){
        domain = d;
    }
    vector<Predicate> GetSchemes(){
        return schemes;
    }
    vector<Predicate> GetFacts(){
        return facts;
    }
    vector<Predicate> GetQueries(){
        return queries;
    }
};

#endif //CS_236_LAB_1_DATALOG_H
