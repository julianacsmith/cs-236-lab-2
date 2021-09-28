//
// Created by Juliana Smith on 9/14/21.
//

#ifndef CS_236_LAB_1_UNDEFINEDAUTOMATON_H
#define CS_236_LAB_1_UNDEFINEDAUTOMATON_H
#include "Automaton.h"

class UndefinedAutomaton : public Automaton
{
public:
    void S0(const std::string& input);
    UndefinedAutomaton() : Automaton(TokenType::UNDEFINED) {}  // Call the base constructor
};

#endif //CS_236_LAB_1_UNDEFINEDAUTOMATON_H
