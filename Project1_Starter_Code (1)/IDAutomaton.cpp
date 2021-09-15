#include "IDAutomaton.h"

void IDAutomaton::S0(const std::string &input) {
    int i = 0;
    char currChar = input.at(i);

    if(!std::isdigit(currChar) && currChar != '\'' && currChar != '#'){
        /**if(input.find('\n') < input.find(' ')){
            inputRead = input.find('\n');
        } else {
            inputRead = input.find(' ');
        }
         **/
         while(isdigit(currChar) || (currChar > 64 && currChar < 91) || (currChar > 96 && currChar < 123)){
             inputRead++;
             i++;
             currChar = input.at(i);
         }
    } else {
        Serr();
    }
}

