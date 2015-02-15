#include "Lexer.h"

Lexer::Lexer()
{
    //ctor
}

Lexer::~Lexer()
{
    //dtor
}

Token Lexer::nextToken()
{
	ifstream inFile("test.txt");

	char c;
	string result;
	while (inFile >> c) {
        result.push_back(c);
	}

	cout << result << endl;


    Token myToken;


	if (result.at(0) == 'e') {
        if (result.at(1) == 'n') {
            if (result.at(2) == 'd') {
                myToken.lexeme = "end";
                myToken.tCode = END;
                result.erase(0,3);
            }
        }
	}

    if (result.at(0) == 'p') {
        if (result.at(1) == 'r') {
            if (result.at(2) == 'i') {
                if (result.at(3) == 'n') {
                    if (result.at(4) == 't') {
                        myToken.lexeme = "print";
                        myToken.tCode = PRINT;
                        result.erase(0,5);
                    }
                }
            }
        }
	}

	int i = 0;
	string tala = "";
	while (isdigit(result[i])) {
        tala.push_back(result[i]);
        i++;
	}
	myToken.lexeme = tala;
	myToken.tCode = INT;


/*
	for (int i = 0; i < result.size(); i++) {

        if(result[i] == "e") {

        }
    }
*/
	return myToken;
}

