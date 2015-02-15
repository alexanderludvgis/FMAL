#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Token.h"

class Lexer
{
    public:
        Lexer();
        virtual ~Lexer();

        // scans stdin and looks for a match of tokens in TokenCode
        TokenCode nextToken();

    protected:
    private:
};

#endif // LEXER_H
