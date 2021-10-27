#include "Parser.h"
#include <vector>
#include <algorithm>
#include "Predicate.h"
#include "Parameter.h"
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
        datalog.SetDatalog(domains);
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
    string name;
    vector<Parameter> para;
    CheckComment();
    name = ParseID();
    ParseLeftParen();
    string p = ParseID();
    para.push_back(Parameter(p));
    ParseIDList(para);
    ParseRightParen();
    Predicate scheme = Predicate(name, para);
    datalog.AddScheme(scheme);
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
    string name;
    vector<Parameter> para;
    CheckComment();
    name = ParseID();
    ParseLeftParen();
    para.push_back(ParseString());
    ParseStringList(para);
    ParseRightParen();
    ParsePeriod();
    datalog.AddFacts(Predicate(name, para));
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
    vector<Predicate> pred;
    CheckComment();
    Predicate head = ParseHeadPredicate();
    ParseColonDash();
    pred.push_back(ParsePredicate());
    ParsePredicateList(pred);
    ParsePeriod();
    Rule rule = Rule(head, pred);
    datalog.AddRules(rule);
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
    datalog.AddQueries(ParsePredicate());
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

string Parser::ParseID(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType == "ID" && !failure){
        string tw = currToken->getValue();
        tokenWord += tw;
        itr++;
        return tw;
    } else {
        Fail();
    }
    return "";
}

void Parser::ParseLeftParen(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType == "LEFT_PAREN" && !failure){
        //tokenWord += currToken->getValue();
        itr++;
        return;
    } else {
        Fail();
    }
}

void Parser::ParseIDList(vector<Parameter>& para){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType != "RIGHT_PAREN" && !failure){
        ParseComma();
        string p = ParseID();
        para.push_back(Parameter(p));
        ParseIDList(para);
    }
}

void Parser::ParseRightParen(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType == "RIGHT_PAREN" && !failure){
        //tokenWord += currToken->getValue();
        itr++;
        return;
    } else {
        Fail();
    }
}

void Parser::ParseStringList(vector<Parameter>& para){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType != "RIGHT_PAREN" && !failure){
        ParseComma();
        para.push_back(ParseString());
        ParseStringList(para);
    }
}

Predicate Parser::ParseHeadPredicate() {
    string name;
    vector<Parameter> para;
    CheckComment();
    string p = ParseID();
    para.push_back(Parameter(p));
    ParseLeftParen();
    p = ParseID();
    para.push_back(Parameter(p));
    ParseIDList(para);
    ParseRightParen();
    return Predicate (name, para);
}

Predicate Parser::ParsePredicate(){
    string name;
    vector<Parameter> para;
    CheckComment();
    name = ParseID();
    ParseLeftParen();
    para.push_back(ParseParameter());
    ParseParameterList(para);
    ParseRightParen();
    return Predicate(name, para);
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

void Parser::ParsePredicateList(vector<Predicate>& pred){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType != "PERIOD" && !failure){
        ParseComma();
        ParsePredicate();
        ParsePredicateList(pred);
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

Parameter Parser::ParseParameter(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType == "STRING" && !failure){
        Parameter p = Parameter(ParseString());
        p.SetConstant(true);
        return p;
    } else if (currTokenType == "ID" && !failure){
        Parameter p = Parameter(ParseID());
        p.SetConstant(false);
        return p;
    } else {
        Fail();
    }
    return Parameter("");
}

void Parser::ParseParameterList(vector<Parameter>& para){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType != "RIGHT_PAREN" && !failure){
        ParseComma();
        para.push_back(ParseParameter());
        ParseParameterList(para);
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

string Parser::ParseString(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType == "STRING" && !failure){
        tokenWord += currToken->getValue();
        if(isFacts){ // If I'm checking facts, then I'll add it to my domains vector
            domains.insert(currToken->getValue());
        }
        itr++;
        return currToken->getValue();
    } else {
        Fail();
    }
    return "";
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

