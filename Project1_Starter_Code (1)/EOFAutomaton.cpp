#include "EOFAutomaton.h"

void EOFAutomaton::S0(const std::string &input) {
    if (input == "") {
        inputRead = 0;
    }
    else {
        Serr();
    }
}

