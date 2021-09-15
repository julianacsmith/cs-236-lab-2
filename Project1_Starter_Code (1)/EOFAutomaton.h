//
// Created by Juliana Smith on 9/14/21.
//

#ifndef CS_236_LAB_1_EOFAUTOMATON_H
#define CS_236_LAB_1_EOFAUTOMATON_H
#include "Automaton.h"

class EOFAutomaton : public Automaton
{
public:
    void S0(const std::string& input);
    EOFAutomaton() : Automaton(TokenType::E_OF) {}  // Call the base constructor
};

#endif //CS_236_LAB_1_EOFAUTOMATON_H
