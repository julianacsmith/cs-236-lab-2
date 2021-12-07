//
// Created by Juliana Smith on 9/13/21.
//

#ifndef CS_236_LAB_1_COMMAAUTOMATON_H
#define CS_236_LAB_1_COMMAAUTOMATON_H
#include "Automaton.h"

class CommaAutomaton : public Automaton
{
public:
    CommaAutomaton() : Automaton(TokenType::COMMA) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif //CS_236_LAB_1_COMMAAUTOMATON_H
