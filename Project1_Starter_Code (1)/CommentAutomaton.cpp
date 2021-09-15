#include "CommentAutomaton.h"

 void CommentAutomaton::S0(const std::string &input) {
    char currChar = input.at(0);
    if(currChar == '#'){
        currChar = input.at(1);
        int i = 1;
        inputRead++;
        if(currChar == '|'){
            i++;
            inputRead++;
            currChar = input.at(i);
            while (currChar != '|') {
                if(currChar == '\n'){
                    newLines++;
                }
                i++;
                if(i == input.size()){
                    break;
                } else {
                    inputRead++;
                    currChar = input.at(i);
                }
            }
            inputRead+=2;
        } else {
            while (currChar != '\n' ) {
                inputRead++;
                i++;
                if(i == input.size()){
                    break;
                }
                currChar = input.at(i);
            }
            inputRead++;
            newLines++;
        }
    } else {
        Serr();
    }
}
