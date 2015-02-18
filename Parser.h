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
        void statements();
        void statement();
        void expr();
        void term();
        void factor();


        Lexer the_lexer;
        Token the_token;

};

#endif // PARSER_H
