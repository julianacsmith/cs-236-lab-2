#include "FactsAutomaton.h"

void FactsAutomaton::S0(const std::string &input) {
    std::string newInput = input.substr(index, index+5);
    if (newInput == "Facts") {
        inputRead = 5;
    }
    else {
        Serr();
    }
}
