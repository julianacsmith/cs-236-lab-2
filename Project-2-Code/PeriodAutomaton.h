//
// Created by Juliana Smith on 9/14/21.
//

#ifndef CS_236_LAB_1_PERIODAUTOMATON_H
#define CS_236_LAB_1_PERIODAUTOMATON_H
#include "Automaton.h"

class PeriodAutomaton : public Automaton
{
public:
    void S0(const std::string& input);
    PeriodAutomaton() : Automaton(TokenType::PERIOD) {}  // Call the base constructor

};

#endif //CS_236_LAB_1_PERIODAUTOMATON_H
