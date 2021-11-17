//
// Created by Juliana Smith on 10/25/21.
//

#ifndef CS_236_LAB_1_INTERPRETER_H
#define CS_236_LAB_1_INTERPRETER_H
#include "Parser.h"
#include "Database.h"
#include <map>

class Interpreter{
private:
    Datalog datalogProgram;
    Database database;
    map <std::string, int> variables;
public:
    Interpreter(Datalog d){
       datalogProgram = d;
    };
    void SchemeToRelation();
    void FactToTuple();
    Relation EvaluatePredicate(Relation* r, Predicate p);
    Relation EvaluateQueries();
    string QueryToString(Predicate p, Relation* r);
};


#endif //CS_236_LAB_1_INTERPRETER_H
