#include "FactsAutomaton.h"

void FactsAutomaton::S0(const std::string &input) {
    std::string newInput = input.substr(index, index+5);
    if (newInput == "Facts") {
        int idx = (int)input.at(newInput.size());
        if((idx < 65 || (idx > 90 && idx < 97) || idx > 123)) {
            inputRead = 5;
        }
    }
    else {
        Serr();
    }
}
