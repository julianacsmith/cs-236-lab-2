//
// Created by Juliana Smith on 9/14/21.
//

#ifndef CS_236_LAB_1_QMARKAUTOMATON_H
#define CS_236_LAB_1_QMARKAUTOMATON_H

#include "Automaton.h"

class QMarkAutomaton : public Automaton
{
public:
    void S0(const std::string& input);

    QMarkAutomaton() : Automaton(TokenType::Q_MARK) {}
};

#endif //CS_236_LAB_1_QMARKAUTOMATON_H
