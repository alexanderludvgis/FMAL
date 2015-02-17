#ifndef TOKEN_H_INCLUDED
#define TOKEN_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;	// has to be included so "string" variable works.

//ID = 0, ..., ERROR = 10
enum TokenCode {
	ID, ASSIGN, SEMICOL, INT, PLUS, MINUS,
	MULT, LPAREN, RPAREN, PRINT, END, ERROR
};


class Token
{
    public:
        string lexeme;
        TokenCode tCode;

        Token()
        {
            lexeme = "";
            tCode = END;
        }

        ~Token()
        {
        }

};


#endif // TOKEN_H_INCLUDED
