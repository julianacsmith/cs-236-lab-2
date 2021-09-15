#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include "Automaton.h"
#include "Token.h"

class Lexer
{
private:
    std::vector<Automaton*> automata;
    std::vector<Token*> tokens;

    void CreateAutomata();

    // TODO: add any other private methods here (if needed)

public:
    Lexer();
    //tokens = new std::vector<Token*>();
    //automata = new std::vector<Automaton*>();
    // colonAutomata = new std::vector<Colon*>();

    //Add all other automaton instances
    //automata.push_back(colon automaton);
    //automata.push_back( colon dash automatan);
    ~Lexer();

    void Run(std::string& input);
    
    // TODO: add other public methods here
    std::string toString();
};

#endif // LEXER_H

