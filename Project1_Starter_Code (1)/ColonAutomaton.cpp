#include "ColonAutomaton.h"

void ColonAutomaton::S0(const std::string& input) {
    if(index+1 <= input.size()) {
        if (input[index] == ':' && input[index + 1] != '-') {
            inputRead = 1;
        } else {
            Serr();
        }
    } else {
        Serr();
    }
}