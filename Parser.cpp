#include "Parser.h"

Parser::Parser()
{
    //ctor
}

Parser::Parser(Lexer myLexer)
{
    the_lexer = myLexer;

}

Parser::~Parser()
{
    //dtor
}


void Parser::parse() {
    the_token = the_lexer.nextToken();
    statements();
}

void Parser::statements() {
    if (the_token.tCode == END) {
        cout << the_token.lexeme << endl;
    }
    else {
        statement();
        the_token = the_lexer.nextToken();
        if(the_token.tCode == SEMICOL) {
            statements();
        }
        else {
            cout << "Syntax error!" << endl;
        }
    }
}

void Parser::statement() {
    if (the_token.tCode == ID) {
        the_token = the_lexer.nextToken();
        if (the_token.tCode == ASSIGN) {
            expr();
        }
    }
    else if (the_token.tCode == PRINT){
        the_token = the_lexer.nextToken();
        if (the_token.tCode == ID) {


        }
    }
}

void Parser::expr() {

}

void Parser::term() {

}

void Parser::factor() {

}
