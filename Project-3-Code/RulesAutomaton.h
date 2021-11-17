//
// Created by Juliana Smith on 9/14/21.
//

#ifndef CS_236_LAB_1_RULESAUTOMATON_H
#define CS_236_LAB_1_RULESAUTOMATON_H
#include "Automaton.h"

class RulesAutomaton : public Automaton
{
public:
    void S0(const std::string& input);
    RulesAutomaton() : Automaton(TokenType::RULES) {}  // Call the base constructor
};

#endif //CS_236_LAB_1_RULESAUTOMATON_H
