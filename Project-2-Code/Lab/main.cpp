#include "Lexer.h"
#include "Parser.h"
#include "Interpreter.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {

    Lexer* lexer = new Lexer();

    // TODO
    if (argc != 2){
        cout << "usage: " << argv[0] << " input_file" << endl;
        return 1;
    }

    string filename = argv[1];
    ifstream input(filename);
    input.open("test.txt");
    if(!input.is_open()){
        cout << "file " << filename << " could not be found or opened." << endl;
        return 1;
    }
 
    string fullFile; // if not work, rename to line
    ostringstream sstr;
    sstr << input.rdbuf();
    fullFile = sstr.str();
    lexer->Run(fullFile);

    Parser* parser = new Parser(lexer->ReturnTokens());
    parser->ParseDatalog();
    /**if(parser->Failed()){
        cout << "Failure!" << endl;
        cout << "\t" << parser->FailedTokenString();
        return 0;
    } else {
        cout << "Success!" << endl;
        parser->toString();
    }
    **/
    //string output = parser->toString();
    //cout << output;
    Interpreter *interpreter = new Interpreter(parser->GetDatalog());
    interpreter->SchemeToRelation();
    interpreter->FactToTuple();
    interpreter->EvaluateRules();
    interpreter->EvaluateQueries();

    delete lexer;
    delete parser;
    delete interpreter;

    return 0;
}