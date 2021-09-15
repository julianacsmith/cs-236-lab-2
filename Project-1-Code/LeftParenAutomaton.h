//
// Created by Juliana Smith on 9/14/21.
//

#ifndef CS_236_LAB_1_LEFTPARENAUTOMATON_H
#define CS_236_LAB_1_LEFTPARENAUTOMATON_H
#include "Automaton.h"

class LeftParenAutomaton : public Automaton
{
public:
    void S0(const std::string& input);
    LeftParenAutomaton() : Automaton(TokenType::LEFT_PAREN) {}
};

#endif //CS_236_LAB_1_LEFTPARENAUTOMATON_H
