#include "CommentAutomaton.h"

 void CommentAutomaton::S0(const std::string &input) {
    if(input.size() >= 2) {
        char firstChar = input.at(0);
        char secondChar = input.at(1);
        if(firstChar == '#' && secondChar == '|'){
            //Block Comment
            int unsigned i;
            inputRead+=2; // accounts for the 2 already read
            for(i = 2; i < input.size(); i++){
                char currChar = input.at(i);
                if(currChar == '\n'){
                    newLines++;
                } else if(currChar == '|'){
                    if(i+1 <= input.size() && input.at(i+1) == '#') { // reached a valid end
                        inputRead+=2;
                        break;
                    }
                }
                inputRead++;
            }
            if (i == input.size()){
                Serr();
            }
        } else if (firstChar == '#') {
            //Normal Comment
            inputRead = input.find('\n');
        } else {
            //Not a comment
            Serr();
        }
    } else {
        Serr();
    }
}
