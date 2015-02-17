#include "Parser.h"

Parser::Parser()
{
    //ctor
}

Parser::~Parser()
{
    //dtor
}

Parser::Parser(Lexer myLexer)
{

}


void Parser::parse() {
    parse(lexer, token);
}

void Parser::parse(string lexer, TokenCode token) {

}
