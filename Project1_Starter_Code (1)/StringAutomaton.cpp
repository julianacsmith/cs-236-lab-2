#include "StringAutomaton.h"

void StringAutomaton::S0(const std::string &input) {
    int i = 0;
    char firstChar = input.at(i);
    if(firstChar == '\'') {
        i++;
        char first = input.at(i);
        while (i != input.size()){
            if(input.at(i) == '\''){
                char second = input.at(i+1);
                if(i+1 <= input.size() && input.at(i+1) == '\''){
                    inputRead+=2;
                    i+=2;
                    continue;
                } else {
                    inputRead+=2;
                    break;
                }
            }
            if(input.at(i) == '\n'){
                newLines++;
            }
            inputRead++;
            i++;
        }
    } else{
        Serr();
    }
}

