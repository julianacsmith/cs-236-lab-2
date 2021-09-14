#include "SchemesAutomaton.h"
#include <string>

void SchemesAutomaton::S0(const std::string &input) {
    std::string newInput = input.substr(index, index+7);
    if (newInput == "Schemes") {
        inputRead = 7;
    }
    else {
        Serr();
    }
}

