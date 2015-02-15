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

        // scans stdin and looks for a match of tokens in TokenCode
        Token nextToken();


    protected:
    private:
};

#endif // LEXER_H
