//
// Created by Juliana Smith on 9/20/21.
//

#ifndef CS_236_LAB_1_PARSER_H
#define CS_236_LAB_1_PARSER_H
#include <vector>
#include <iostream>
#include "Token.h"
#include <set>
#include "Predicate.h"
#include "Parameter.h"
#include "Datalog.h"

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
    bool failure = false;
    Token* failedToken;
    unsigned int itr;
    Datalog datalog = Datalog();
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
    string ParseID();
    void ParseLeftParen();
    void ParseIDList(vector<Parameter>& para);
    void ParseRightParen();
    void ParseStringList(vector<Parameter>& para);
    Predicate ParseHeadPredicate();
    Predicate ParsePredicate();
    void ParsePeriod();
    void ParseColonDash();
    void ParsePredicateList(vector<Predicate>& pred);
    void ParseQMark();
    Parameter ParseParameter();
    void ParseParameterList(vector<Parameter>& para);
    void ParseComma();
    string ParseString();
    void Fail();
    void CheckComment();
    bool Failed();
    std::string FailedTokenString();
    vector<string> GetSchemes(){
        return schemes;
    }
    vector<string> GetFacts(){
        return facts;
    }
    vector<string> GetRules(){
        return rules;
    }
    vector<string> GetQueries(){
        return queries;
    }
    Datalog GetDatalog(){
        return datalog;
    }
    std::string toString();
};

#endif //CS_236_LAB_1_PARSER_H
