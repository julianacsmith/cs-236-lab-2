//
// Created by Juliana Smith on 9/14/21.
//

#ifndef CS_236_LAB_1_IDAUTOMATON_H
#define CS_236_LAB_1_IDAUTOMATON_H
#include "Automaton.h"

class IDAutomaton : public Automaton
{
public:
    void S0(const std::string& input);
    IDAutomaton() : Automaton(TokenType::ID) {}  // Call the base constructor
};

#endif //CS_236_LAB_1_IDAUTOMATON_H
