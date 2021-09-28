//
// Created by Juliana Smith on 9/20/21.
//

#ifndef CS_236_LAB_1_PARSER_H
#define CS_236_LAB_1_PARSER_H
#include <vector>
#include <iostream>
#include "Token.h"
#include <set>

using namespace std;

class Parser{
private:
    vector<Token*> tokens;
    vector<string> schemes;
    vector<string> facts;
    vector<string> rules;
    vector<string> queries;
    set<string> domains;
    string tokenWord;
    bool isFacts = false;
    unsigned int itr;
public:
    Parser(vector<Token*> t){ tokens = t; itr = 0;};
    ~ Parser();
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
