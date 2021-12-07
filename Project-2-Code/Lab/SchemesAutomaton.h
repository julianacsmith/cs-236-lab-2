//
// Created by Juliana Smith on 9/14/21.
//

#ifndef CS_236_LAB_1_SCHEMESAUTOMATON_H
#define CS_236_LAB_1_SCHEMESAUTOMATON_H
#include "Automaton.h"

class SchemesAutomaton : public Automaton
{
public:
    void S0(const std::string& input);
    SchemesAutomaton() : Automaton(TokenType::SCHEMES) {}  // Call the base constructor
};

#endif //CS_236_LAB_1_SCHEMESAUTOMATON_H
