#include <iostream>
#include <string>
#include <fstream>
#include "Lexer.h"
#include "Parser.h"
#include "Token.h"

using namespace std;	// has to be included so "string" variable works.

int main() {

    Lexer myLexer = Lexer();
    Parser myParser = Parser(myLexer);
	myParser.parse();


	return 0;
}
