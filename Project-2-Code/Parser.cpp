#include "Parser.h"
#include <vector>
#include <algorithm>

using namespace std;

Parser::~Parser() {
}

void Parser::ParseDatalog() {
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType == "SCHEMES"){
        itr++;
        ParseColon();
        ParseScheme();
        ParseSchemeList();
        ParseFacts();
        ParseColon();
        ParseFactList();
        isFacts = false; // A bool flag to tell me if I'm checking facts. Used for Domains
        ParseRules();
        ParseColon();
        ParseRuleList();
        ParseQueries();
        ParseColon();
        ParseQuery();
        ParseQueryList();
        ParseEOF();
    } else {
        Fail();
    }
}

void Parser::ParseColon(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType == "COLON" && !failure){
        itr++;
        return;
    } else {
        Fail();
    }
}

void Parser::ParseScheme(){
    CheckComment();
    ParseID();
    ParseLeftParen();
    ParseID();
    ParseIDList();
    ParseRightParen();
    schemes.push_back(tokenWord);
    tokenWord = "";
}

void Parser::ParseSchemeList(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType != "FACTS" && !failure){
        CheckComment();
        ParseScheme();
        ParseSchemeList();
    }
}

void Parser::ParseFacts() {
    CheckComment();
    Token *currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if (currTokenType == "FACTS" && !failure) {
        isFacts = true;
        itr++;
        return;
    } else {
        Fail();
    }
}

void Parser::ParseFact() {
    CheckComment();
    ParseID();
    ParseLeftParen();
    ParseString();
    ParseStringList();
    ParseRightParen();
    ParsePeriod();
    facts.push_back(tokenWord);
    tokenWord = "";
}

void Parser::ParseFactList(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType != "RULES" && !failure){
        CheckComment();
        ParseFact();
        ParseFactList();
    }
}

void Parser::ParseRules(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType == "RULES" && !failure){
        itr++;
        return;
    } else {
        Fail();
    }
}

void Parser::ParseRule(){
    CheckComment();
    ParseHeadPredicate();
    ParseColonDash();
    ParsePredicate();
    ParsePredicateList();
    ParsePeriod();
    rules.push_back(tokenWord);
    tokenWord = "";
}

void Parser::ParseRuleList(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType != "QUERIES" && !failure){
        CheckComment();
        ParseRule();
        ParseRuleList();
    }
}

void Parser::ParseQueries(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType == "QUERIES" && !failure){
        itr++;
        return;
    } else {
        Fail();
    }
}

void Parser::ParseQuery(){
    CheckComment();
    ParsePredicate();
    ParseQMark();
    queries.push_back(tokenWord);
    tokenWord = "";
}

void Parser::ParseQueryList(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType != "EOF" && !failure){
        CheckComment();
        ParseQuery();
        ParseQueryList();
    }
}

void Parser::ParseEOF(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType == "EOF" && !failure){
        itr++;
        return;
    } else {
        Fail();
    }
}

void Parser::ParseID(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType == "ID" && !failure){
        tokenWord += currToken->getValue();
        itr++;
        return;
    } else {
        Fail();
    }
}

void Parser::ParseLeftParen(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType == "LEFT_PAREN" && !failure){
        tokenWord += currToken->getValue();
        itr++;
        return;
    } else {
        Fail();
    }
}

void Parser::ParseIDList(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType != "RIGHT_PAREN" && !failure){
        ParseComma();
        ParseID();
        ParseIDList();
    }
}

void Parser::ParseRightParen(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType == "RIGHT_PAREN" && !failure){
        tokenWord += currToken->getValue();
        itr++;
        return;
    } else {
        Fail();
    }
}

void Parser::ParseStringList(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType != "RIGHT_PAREN" && !failure){
        ParseComma();
        ParseString();
        ParseStringList();
    }
}

void Parser::ParseHeadPredicate() {
    CheckComment();
    ParseID();
    ParseLeftParen();
    ParseID();
    ParseIDList();
    ParseRightParen();
}

void Parser::ParsePredicate(){
    CheckComment();
    ParseID();
    ParseLeftParen();
    ParseParameter();
    ParseParameterList();
    ParseRightParen();
}

void Parser::ParsePeriod(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType == "PERIOD" && !failure){
        tokenWord += currToken->getValue();
        itr++;
        return;
    } else {
        Fail();
    }
}

void Parser::ParseColonDash(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType == "COLON_DASH" && !failure){
        tokenWord += " " + currToken->getValue() + " ";
        itr++;
        return;
    } else {
        Fail();
    }
}

void Parser::ParsePredicateList(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType != "PERIOD" && !failure){
        ParseComma();
        ParsePredicate();
        ParsePredicateList();
    }
}

void Parser::ParseQMark(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType == "Q_MARK" && !failure){
        tokenWord += currToken->getValue();
        itr++;
        return;
    } else {
        Fail();
    }
}

void Parser::ParseParameter(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType == "STRING" && !failure){
        ParseString();
    } else if (currTokenType == "ID" && !failure){
        ParseID();
    } else {
        Fail();
    }
}

void Parser::ParseParameterList(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType != "RIGHT_PAREN" && !failure){
        ParseComma();
        ParseParameter();
        ParseParameterList();
    }
}

void Parser::ParseComma(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType == "COMMA" && !failure){
        tokenWord += currToken->getValue();
        itr++;
        return;
    } else {
        Fail();
    }
}

void Parser::ParseString(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType == "STRING" && !failure){
        tokenWord += currToken->getValue();
        if(isFacts){ // If I'm checking facts, then I'll add it to my domains vector
            domains.insert(currToken->getValue());
        }
        itr++;
        return;
    } else {
        Fail();
    }
}

string Parser::toString(){
    string output;
    cout << "Schemes(" << schemes.size() << "):" << endl;
    for(unsigned int i = 0; i < schemes.size(); i++){
        cout << "  " << schemes.at(i) << endl;
    }
    cout << "Facts(" << facts.size() << "):" << endl;
    for(unsigned int i = 0; i < facts.size(); i++){
        cout << "  " << facts.at(i) << endl;
    }
    cout << "Rules(" << rules.size() << "):" << endl;
    for(unsigned int i = 0; i < rules.size(); i++){
        cout << "  " << rules.at(i) << endl;
    }
    cout << "Queries(" << queries.size() << "):" << endl;
    for(unsigned int i = 0; i < queries.size(); i++){
        cout << "  " << queries.at(i) << endl;
    }
    set<string>:: iterator it;
    cout << "Domain(" << domains.size() << "):" << endl;
    for(it = domains.begin(); it != domains.end(); it++){
        string domain = *it;
        cout << "  " << domain << endl;
    }
    return output;
}

void Parser::CheckComment() {
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    while (currTokenType == "COMMENT" && itr < tokens.size()){
        itr++;
        currToken = tokens.at(itr);
        currTokenType = currToken->typeToString(currToken->getType());
    }
}

void Parser::Fail() {
    failure = true;
    failedToken = tokens.at(itr);
}

bool Parser::Failed(){
    return failure;
}

string Parser::FailedTokenString() {
    return failedToken->toString();
}

