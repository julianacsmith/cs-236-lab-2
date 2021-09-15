#include "StringAutomaton.h"

void StringAutomaton::S0(const std::string &input) {
    char firstChar = input.at(0);
    if(firstChar == '\'') {
        if(input.find('\'')){
            int i = 1;
            inputRead = 1;
            if(input.at(i) == '\''){
                inputRead++;
                i++;
            }
            while (input.at(i) != '\'') {
                i++;
                if(i == input.size()){
                    Serr();
                    break;
                } else if(input.at(i) == '\''){
                    if(i+1 != input.size() && input.at(i+1) == '\'') {
                        inputRead+=2;
                        i+=2;
                    } else {
                        inputRead++;
                    }
                }else {
                    inputRead++;
                }
            }
            inputRead++;
        }
    } else{
        Serr();
    }
}

