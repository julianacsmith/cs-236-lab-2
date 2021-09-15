#include "UndefinedAutomaton.h"

void UndefinedAutomaton::S0(const std::string &input) {
    if (input[index] == '$' || input[index] == '&' || input[index] == '^') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}