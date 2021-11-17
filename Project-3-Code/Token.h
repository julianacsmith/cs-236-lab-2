#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <string>

enum class TokenType {
    COLON,
    COLON_DASH,
    // TODO: add the other types of tokens
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    E_OF,
    UNDEFINED
};

class Token
{
private:
    // TODO: add member variables for information needed by Token
    std::string value;
    int lineNumber;
    TokenType tType;

public:
    Token(TokenType type, std::string description, int line);

    // TODO: add other needed methods
    std::string toString();

    std::string typeToString(TokenType type){
        switch (type) {
            case TokenType::COLON:
                return "COLON";
                break;
            case TokenType::COLON_DASH:
                return "COLON_DASH";
                break;
            case TokenType::COMMA:
                return "COMMA";
                break;
            case TokenType::PERIOD:
                return "PERIOD";
                break;
            case TokenType::Q_MARK:
                return "Q_MARK";
                break;
            case TokenType::LEFT_PAREN:
                return "LEFT_PAREN";
                break;
            case TokenType::RIGHT_PAREN:
                return "RIGHT_PAREN";
                break;
            case TokenType::MULTIPLY:
                return "MULTIPLY";
                break;
            case TokenType::ADD:
                return "ADD";
                break;
            case TokenType::SCHEMES:
                return "SCHEMES";
                break;
            case TokenType::FACTS:
                return "FACTS";
                break;
            case TokenType::RULES:
                return "RULES";
                break;
            case TokenType::QUERIES:
                return "QUERIES";
                break;
            case TokenType::ID:
                return "ID";
                break;
            case TokenType::STRING:
                return "STRING";
                break;
            case TokenType::COMMENT:
                return "COMMENT";
                break;
            case TokenType::UNDEFINED:
                return "UNDEFINED";
                break;
            case TokenType::E_OF:
                return "EOF";
                break;
        }
        return "ERROR";
    }

    TokenType getType(){ return tType; };
    std::string getValue(){ return value; };
};

#endif // TOKEN_H

