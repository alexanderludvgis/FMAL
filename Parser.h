#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include "Lexer.h"

using namespace std;	// has to be included so "string" variable works.


class Parser
{
    public:
        Parser();
        //call by reference?
        Parser(Lexer);
        virtual ~Parser();

        void parse();

    protected:
    private:
        void parse(string, TokenCode);
        string lexer;
        TokenCode token;
};

#endif // PARSER_H
