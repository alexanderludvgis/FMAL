#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Token.h"

using namespace std;

class Lexer : public Token
{
    public:
        Lexer();
        virtual ~Lexer();

        //scans stdin and looks for a match of tokens in TokenCode.
        //takes an input, ignores whitespaces and newlines and then trims it down.
        //has to be call by reference else we'll get a copy of the string
        //we are working with which we don't want
        Token nextToken(string&);


    protected:
    private:
};

#endif // LEXER_H
