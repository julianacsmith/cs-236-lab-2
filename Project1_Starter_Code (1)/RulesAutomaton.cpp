#include "RulesAutomaton.h"

void RulesAutomaton::S0(const std::string &input) {
    std::string newInput = input.substr(index, index+5);
    if (newInput == "Rules") {
        inputRead = 5;
    }
    else {
        Serr();
    }
}

