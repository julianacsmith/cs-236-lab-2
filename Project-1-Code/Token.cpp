#include "Token.h"

Token::Token(TokenType type, std::string description, int line) {
    // TODO: initialize all member variables
    tType = type;
    value = description;
    lineNumber = line;
}

std::string Token::toString() {
    std::string output = "(" + typeToString((tType)) + ",\"" + value + "\",";
    output += std::to_string(lineNumber);
    output += ")";
    return output;
    //std::cout << "(" << typeToString(tType) << ",\"" << value << "\"," << lineNumber << ")" << std::endl;
}
