//
// Created by Juliana Smith on 9/14/21.
//

#ifndef CS_236_LAB_1_QUERIESAUTOMATON_H
#define CS_236_LAB_1_QUERIESAUTOMATON_H
#include "Automaton.h"

class QueriesAutomaton : public Automaton
{
public:
    void S0(const std::string& input);
    QueriesAutomaton() : Automaton(TokenType::QUERIES) {}  // Call the base constructor
};

#endif //CS_236_LAB_1_QUERIESAUTOMATON_H
