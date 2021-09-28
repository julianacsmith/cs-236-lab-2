//
// Created by Juliana Smith on 9/14/21.
//

#ifndef CS_236_LAB_1_MULTIPLYAUTOMATON_H
#define CS_236_LAB_1_MULTIPLYAUTOMATON_H
#include "Automaton.h"

class MultiplyAutomaton : public Automaton
{
public:
    void S0(const std::string& input);
    MultiplyAutomaton() : Automaton(TokenType::MULTIPLY) {}  // Call the base constructor

};

#endif //CS_236_LAB_1_MULTIPLYAUTOMATON_H
