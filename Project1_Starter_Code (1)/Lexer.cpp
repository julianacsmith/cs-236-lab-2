#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "CommaAutomaton.h"
#include "PeriodAutomaton.h"
#include "QMarkAutomaton.h"
#include "LeftParenAutomaton.h"
#include "RightParenAutomaton.h"
#include "MultiplyAutomaton.h"
#include "AddAutomaton.h"
#include "SchemesAutomaton.h"
#include "FactsAutomaton.h"
#include "RulesAutomaton.h"
#include "QueriesAutomaton.h"

using namespace std;
Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    // TODO: Add the other needed automata here
    automata.push_back(new CommaAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new QMarkAutomaton());
    automata.push_back(new LeftParenAutomaton());
    automata.push_back(new RightParenAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new QueriesAutomaton());
}

void Lexer::Run(std::string& input) {
    // TODO: convert this pseudo-code with the algorithm into actual C++ code
    /*
    set lineNumber to 1
    // While there are more characters to tokenize
    loop while input.size() > 0 {
        set maxRead to 0
        set maxAutomaton to the first automaton in automata

        // TODO: you need to handle whitespace inbetween tokens

        // Here is the "Parallel" part of the algorithm
        //   Each automaton runs with the same input
        foreach automaton in automata {
            inputRead = automaton.Start(input)
            if (inputRead > maxRead) {
                set maxRead to inputRead
                set maxAutomaton to automaton
            }
        }
        // Here is the "Max" part of the algorithm
        if maxRead > 0 {
            set newToken to maxAutomaton.CreateToken(...)
                increment lineNumber by maxAutomaton.NewLinesRead()
                add newToken to collection of all tokens
        }
        // No automaton accepted input
        // Create single character undefined token
        else {
            set maxRead to 1
                set newToken to a  new undefined Token
                (with first character of input)
                add newToken to collection of all tokens
        }
        // Update `input` by removing characters read to create Token
        remove maxRead characters from input
    }
    add end of file token to all tokens
    */

    //Actual Code Version

    int lineNumber = 1; // set lineNumber to 1
    while (!input.empty()){ // While there's more to tokenize
        int maxRead = 0; // set maxRead to 0
        Automaton* maxAutomaton = automata.at(0); //set maxAutomation tothe first automata
        //Handle whitespace
        while(input.at(maxRead) == ' '){
            maxRead++;
        }

        input.erase(0,maxRead);
        maxRead = 0;

        //Parallel Part
        for (Automaton* automaton : automata){
            int inputRead = automaton->Start(input);
            if(inputRead > maxRead){
                maxRead = inputRead;
                maxAutomaton = automaton;
            }
        }
        //Max part
        if (maxRead > 0){
            string newInput = input.substr(0,maxRead);
            Token *newToken = maxAutomaton->CreateToken(newInput, maxRead);
            lineNumber+=maxAutomaton->NewLinesRead();
            tokens.push_back(newToken);
        }
        else {
            maxRead = 1;
            Token* newToken = reinterpret_cast<Token *>(input.at(0));
            tokens.push_back(newToken);
            std::cout << newToken << std::endl;
        }
        input.erase(0,maxRead);
    }
}

string Lexer::toString(){
    string output;
    for (Token* token : tokens){
        output += token->toString() + "\n";
    }
    output += "TOKENS: ";
    output += to_string(tokens.size());
    return output;
};