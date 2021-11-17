//
// Created by Juliana Smith on 10/25/21.
//

#ifndef CS_236_LAB_1_PARAMETER_H
#define CS_236_LAB_1_PARAMETER_H
#include "Token.h"

class Parameter{
private:
    bool isConstant;
    std::string value;
public:
    Parameter(){}
    Parameter(std::string t) {value = t; }
    bool isConst() { return isConstant;}
    void SetConstant(bool c){ isConstant = c; }
    std::string toString(){
        return value;
    }
};
#endif //CS_236_LAB_1_PARAMETER_H
