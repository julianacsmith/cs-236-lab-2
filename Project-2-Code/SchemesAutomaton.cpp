#include "SchemesAutomaton.h"
#include <string>

void SchemesAutomaton::S0(const std::string &input) {
    if(index+7 <= input.size()) {
        std::string newInput = input.substr(index, index + 7);
        if (newInput == "Schemes") {
            int idx = input.at(0);
            //if(input.at(newInput.size()) == ' ' || input.at(newInput.size()) == '\n' || input.at(newInput.size()) == '\''){
            if ((idx < 65 || (idx > 90 && idx < 97) || idx > 123)) {
                Serr();
            } else {
                inputRead = 7;
            }
        } else {
            Serr();
        }
    } else {
        Serr();
    }
}

