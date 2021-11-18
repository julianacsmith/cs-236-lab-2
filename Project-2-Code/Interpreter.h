//
// Created by Juliana Smith on 10/25/21.
//

#ifndef CS_236_LAB_1_INTERPRETER_H
#define CS_236_LAB_1_INTERPRETER_H
#include "Parser.h"
#include "Database.h"
#include <map>
#include <vector>

class Interpreter{
private:
    Datalog datalogProgram;
    Database database;
    bool addedTuple;
    map <std::string, int> variables;
public:
    Interpreter(Datalog d){
       datalogProgram = d;
    };
    void SchemeToRelation();
    void FactToTuple();
    Relation EvaluatePredicate(Relation* r, Predicate p);
    Relation EvaluateQueries();
    void EvaluateRules();
    Relation EvaluateRule(Rule r);
    string QueryToString(Predicate p, Relation* r);
    string RuleToString(Rule rule, Relation r);
    std::vector<int> FindMatches(std::vector<Predicate> p);
    std::vector<int> FindCols(std::vector<std::string> att, std::vector<std::string> cols);
};


#endif //CS_236_LAB_1_INTERPRETER_H
