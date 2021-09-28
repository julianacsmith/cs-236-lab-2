#include "Parser.h"

using namespace std;

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
        ParseRules();
        ParseColon();
        ParseRuleList();
        ParseQueries();
        ParseColon();
        ParseQuery();
        ParseQueryList();
        ParseEOF();
        cout << "Success!" << endl;
    } else {
        Fail();
    }
}

void Parser::ParseColon(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType == "COLON"){
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
}

void Parser::ParseSchemeList(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType != "FACTS"){
        CheckComment();
        ParseScheme();
        ParseSchemeList();
    }
}

void Parser::ParseFacts() {
    CheckComment();
    Token *currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if (currTokenType == "FACTS") {
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
}

void Parser::ParseFactList(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType != "RULES"){
        CheckComment();
        ParseFact();
        ParseFactList();
    }
}

void Parser::ParseRules(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType == "RULES"){
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
}

void Parser::ParseRuleList(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType != "QUERIES"){
        CheckComment();
        ParseRule();
        ParseRuleList();
    }
}

void Parser::ParseQueries(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType == "QUERIES"){
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
}

void Parser::ParseQueryList(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType != "EOF"){
        CheckComment();
        ParseQuery();
        ParseQueryList();
    }
}

void Parser::ParseEOF(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType == "EOF"){
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
    if(currTokenType == "ID"){
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
    if(currTokenType == "LEFT_PAREN"){
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
    if(currTokenType != "RIGHT_PAREN"){
        ParseComma();
        ParseID();
        ParseIDList();
    }
}

void Parser::ParseRightParen(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType == "RIGHT_PAREN"){
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
    if(currTokenType != "RIGHT_PAREN"){
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
    if(currTokenType == "PERIOD"){
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
    if(currTokenType == "COLON_DASH"){
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
    if(currTokenType != "PERIOD"){
        ParseComma();
        ParsePredicate();
        ParsePredicateList();
    }
}

void Parser::ParseQMark(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType == "Q_MARK"){
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
    if(currTokenType == "STRING"){
        ParseString();
    } else if (currTokenType == "ID"){
        ParseID();
    } else {
        Fail();
    }
}

void Parser::ParseParameterList(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType != "RIGHT_PAREN"){
        ParseComma();
        ParseParameter();
        ParseParameterList();
    }
}

void Parser::ParseComma(){
    CheckComment();
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    if(currTokenType == "COMMA"){
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
    if(currTokenType == "STRING"){
        itr++;
        return;
    } else {
        Fail();
    }
}

string Parser::toString(){
    string output;
    for (Token* token : tokens){
        output += token->toString() + "\n";
    }
    output += "Total Tokens = ";
    output += to_string(tokens.size());
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
    cout << "Failure!" << endl;
    Token* currToken = tokens.at(itr);
    string currTokenType = currToken->typeToString(currToken->getType());
    throw invalid_argument(currToken->toString());
}

