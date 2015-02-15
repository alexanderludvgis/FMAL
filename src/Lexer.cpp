#include "Lexer.h"

Lexer::Lexer()
{
    //ctor
}

Lexer::~Lexer()
{
    //dtor
}

TokenCode nextToken()
{

	ifstream inFile("text.txt");

	char c;
	string result;
	while (inFile >> c)
		result.push_back(c);

	cout << result << endl;

	return ERROR;
}
