#include "IDAutomaton.h"

void IDAutomaton::S0(const std::string &input) {
    char firstChar = input.at(0);
    if(!std::isdigit(firstChar) && firstChar != '\'' && firstChar != '#'){
        inputRead = input.size();
    } else {
        Serr();
    }
}

