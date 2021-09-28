//
// Created by Juliana Smith on 9/14/21.
//

#ifndef CS_236_LAB_1_STRINGAUTOMATON_H
#define CS_236_LAB_1_STRINGAUTOMATON_H
#include "Automaton.h"

class StringAutomaton : public Automaton
{
public:
    void S0(const std::string& input);
    StringAutomaton() : Automaton(TokenType::STRING) {}  // Call the base constructor
};

#endif //CS_236_LAB_1_STRINGAUTOMATON_H
