#include <iostream>
#include <string>
#include "Lexer.h"
#include "Parser.h"
#include "Token.h"

using namespace std;	// has to be included so "string" variable works.

int main() {

	/*
	ifstream inFile("test.txt");

	char c;
	string result;
	while (inFile >> c)
		result.push_back(c);

	cout << result << endl;
	*/

	Lexer myLexer = Lexer();
	myLexer.nextToken();

	//Parser myParser = new Parser(myLexer);
	//myParser.parse();


	return 0;
}
