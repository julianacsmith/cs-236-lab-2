#include "StringAutomaton.h"

void StringAutomaton::S0(const std::string &input) {
    int unsigned i = 0;
    char firstChar = input.at(i);
    if(firstChar == '\'') {
        i++;
        while (i != input.size()){
            char currChar = input.at(i);
            if(currChar == '\''){
                if(i+1 <= input.size() && input.at(i+1) == '\''){
                    inputRead+=2;
                    i+=2;
                    continue;
                } else {
                    inputRead+=2;
                    break;
                }
            } else if(input.at(i) == '\n'){
                newLines++;
            }
            inputRead++;
            i++;
        }
        if (i == input.size()){
            Serr();
        }
    } else{
        Serr();
    }
}

