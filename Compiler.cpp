#include <iostream>
#include <string>
#include <fstream>
#include "Lexer.h"
#include "Parser.h"
#include "Token.h"

using namespace std;	// has to be included so "string" variable works.

int main() {

    Lexer myLexer = Lexer();

   //open file
	ifstream inFile("test.txt");

	char c;
	string result;
	while (inFile >> c) {
        result.push_back(c);
	}
	cout << result << endl;

    while (!result.empty()) {
        myLexer.nextToken(result);
    }


	//Parser myParser = new Parser(myLexer);
	//myParser.parse();


	return 0;
}
