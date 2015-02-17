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

//    string str = "";
//
//    cout << "fyrsta stakid: " << result.at(0) << endl;
//    while (isalpha(result.at(0))) {
//        cout << "fyrsta stakid: " << result.at(0) << endl;
//        str.push_back(result.at(0));
//        result.erase(0,1);
//        cout << "Result eftir eydslu: " << result << endl;
//        cout << "Str: " << str << endl;
//    }
//    cout << "Result eftir while " << result << endl;


	//Parser myParser = new Parser(myLexer);
	//myParser.parse();


	return 0;
}
