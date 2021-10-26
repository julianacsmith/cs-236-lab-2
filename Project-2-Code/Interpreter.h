//
// Created by Juliana Smith on 10/25/21.
//

#ifndef CS_236_LAB_1_INTERPRETER_H
#define CS_236_LAB_1_INTERPRETER_H
#include "Parser.h"
#include "Database.h"

class Interpreter{
private:
    Datalog datalogProgram;
    Database database;
public:
    Interpreter(Datalog d){
       datalogProgram = d;
    };
    void SchemeToRelation();
    void FactToTuple();
    Relation EvaluatePredicate(Parameter p);
    Relation EvaluateQueries();
    string toString(){return "";};
};

#endif //CS_236_LAB_1_INTERPRETER_H
