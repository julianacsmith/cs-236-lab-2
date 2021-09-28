//
// Created by Juliana Smith on 9/20/21.
//

#ifndef CS_236_LAB_1_PARSER_H
#define CS_236_LAB_1_PARSER_H
#include <vector>
#include <iostream>
#include "Token.h"

using namespace std;

class Parser{
private:
    vector<Token*> tokens;
    vector<Token*> schemes;
    vector<Token*> facts;
    vector<Token*> rules;
    vector<Token*> queries;
    unsigned int itr;
public:
    Parser(vector<Token*> t){ tokens = t; itr = 0;};
    void ParseDatalog();
    void ParseColon();
    void ParseScheme();
    void ParseSchemeList();
    void ParseFacts();
    void ParseFact();
    void ParseFactList();
    void ParseRules();
    void ParseRule();
    void ParseRuleList();
    void ParseQueries();
    void ParseQuery();
    void ParseQueryList();
    void ParseEOF();
    void ParseID();
    void ParseLeftParen();
    void ParseIDList();
    void ParseRightParen();
    void ParseStringList();
    void ParseHeadPredicate();
    void ParsePredicate();
    void ParsePeriod();
    void ParseColonDash();
    void ParsePredicateList();
    void ParseQMark();
    void ParseParameter();
    void ParseParameterList();
    void ParseComma();
    void ParseString();
    void Fail();
    void CheckComment();


    std::string toString();
};

#endif //CS_236_LAB_1_PARSER_H
