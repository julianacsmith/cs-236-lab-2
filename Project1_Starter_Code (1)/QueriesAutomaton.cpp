#include "QueriesAutomaton.h"

void QueriesAutomaton::S0(const std::string &input) {
    std::string newInput = input.substr(index, index+7);
    if (newInput == "Queries") {
        inputRead = 7;
    }
    else {
        Serr();
    }
}


