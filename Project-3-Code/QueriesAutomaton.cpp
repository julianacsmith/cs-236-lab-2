#include "QueriesAutomaton.h"

void QueriesAutomaton::S0(const std::string &input) {
    std::string newInput = input.substr(index, index+7);
    if (newInput == "Queries") {
        int idx = (int)input.at(newInput.size());
        if((idx < 65 || (idx > 90 && idx < 97) || idx > 123)) {
            inputRead = 7;
        }
    }
    else {
        Serr();
    }
}


