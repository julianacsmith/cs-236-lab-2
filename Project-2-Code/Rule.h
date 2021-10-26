//
// Created by Juliana Smith on 10/26/21.
//

#ifndef CS_236_LAB_1_RULE_H
#define CS_236_LAB_1_RULE_H
#include <iostream>
#include <vector>
#include "Predicate.h"

class Rule{
private:
    Predicate head;
    std::vector<Predicate> body;
public:
    Rule(Predicate h, std::vector<Predicate> b) : head(h), body(b){}
    std::string toString(){
        std::string output = head.toString() + " :- ";
        for(unsigned int i = 0; i < body.size(); i++){
            output += body.at(i).toString();
            if(i != body.size()-1){
                output += ",";
            }
        }
        output += ".";
        return output;
    }

};

#endif //CS_236_LAB_1_RULE_H
