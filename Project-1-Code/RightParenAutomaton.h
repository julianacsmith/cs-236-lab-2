//
// Created by Juliana Smith on 9/14/21.
//

#ifndef CS_236_LAB_1_RIGHTPARENAUTOMATON_H
#define CS_236_LAB_1_RIGHTPARENAUTOMATON_H
#include "Automaton.h"

class RightParenAutomaton : public Automaton
{
public:
    void S0(const std::string& input);
    RightParenAutomaton() : Automaton(TokenType::RIGHT_PAREN) {}  // Call the base constructor

};

#endif //CS_236_LAB_1_RIGHTPARENAUTOMATON_H
