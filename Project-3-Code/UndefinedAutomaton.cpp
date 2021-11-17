#include "UndefinedAutomaton.h"

void UndefinedAutomaton::S0(const std::string &input) {
    int unsigned i = 0;
    char currChar = input.at(i);
    if (currChar == '\'' || currChar == '#') { // Just checking basics again, because if String or comment, then it would've caught
        //I automatically know that these are invalid cases
        while(i != input.size()){
            if(input.at(i) == '\n'){
                newLines++;
            }
            inputRead++;
            i++;
        }
    } else {
        inputRead = 1;
    }
}