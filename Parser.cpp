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

void Parser::statements(TokenCode token) {

}

void Parser::statement(TokenCode token) {

}

void Parser::expr(TokenCode token) {

}

void Parser::term(TokenCode token) {

}

void Parser::factor(TokenCode token) {

}
