//
// Created by Juliana Smith on 9/14/21.
//

#ifndef CS_236_LAB_1_ADDAUTOMATON_H
#define CS_236_LAB_1_ADDAUTOMATON_H
#include "Automaton.h"

class AddAutomaton : public Automaton
{
public:
    void S0(const std::string& input);
    AddAutomaton() : Automaton(TokenType::ADD) {}  // Call the base constructor

};

#endif //CS_236_LAB_1_ADDAUTOMATON_H
