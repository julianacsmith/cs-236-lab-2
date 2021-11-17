#include "IDAutomaton.h"

void IDAutomaton::S0(const std::string &input) {
    int unsigned i = 0;
    if(input.size() < 1){
        Serr();
    }else {
        char currChar = input.at(i);
        if (!std::isdigit(currChar) && currChar != '\'' && currChar != '#') {
            while (i < input.size() && (isdigit(currChar) || (currChar > 64 && currChar < 91) || (currChar > 96 && currChar < 123))) {
                inputRead++;
                i++;
                currChar = input.at(i);
            }
        } else {
            Serr();
        }
    }
}

