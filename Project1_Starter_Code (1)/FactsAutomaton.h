//
// Created by Juliana Smith on 9/14/21.
//

#ifndef CS_236_LAB_1_FACTSAUTOMATON_H
#define CS_236_LAB_1_FACTSAUTOMATON_H
#include "Automaton.h"

class FactsAutomaton : public Automaton
{
public:
    void S0(const std::string& input);
    FactsAutomaton() : Automaton(TokenType::FACTS) {}  // Call the base constructor
};

#endif //CS_236_LAB_1_FACTSAUTOMATON_H
