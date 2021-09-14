#include "Lexer.h"
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

    cout << "file " << filename << " read successfully!" << endl;
    string line;
    cout << "About to enter while" << endl;
    while(getline(input, line)){
        istringstream iss(line);
        lexer->Run(line);
        cout << "Entered run by now :))" << endl;
        string output = lexer->toString();
        cout << output << endl;
    }

    delete lexer;

    return 0;
}