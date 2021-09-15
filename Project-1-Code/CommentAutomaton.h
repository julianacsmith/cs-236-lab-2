//
// Created by Juliana Smith on 9/14/21.
//

#ifndef CS_236_LAB_1_COMMENTAUTOMATON_H
#define CS_236_LAB_1_COMMENTAUTOMATON_H
#include "Automaton.h"

class CommentAutomaton : public Automaton
{
public:
    void S0(const std::string& input);
    CommentAutomaton() : Automaton(TokenType::COMMENT) {}  // Call the base constructor
};

#endif //CS_236_LAB_1_COMMENTAUTOMATON_H
