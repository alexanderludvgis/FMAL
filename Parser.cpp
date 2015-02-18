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
        return;
    }
    else {
        statement();
        if(the_token.tCode == SEMICOL) {
            the_token = the_lexer.nextToken();
            statements();
        }
        else if (the_token.tCode == ERROR){
            error();
        }
    }
}

void Parser::statement() {
    if (the_token.tCode == ID) {
        cout << "PUSH " << the_token.lexeme << endl;
        the_token = the_lexer.nextToken();
        if (the_token.tCode == ASSIGN) {
            the_token = the_lexer.nextToken();
            expr();
            cout << "ASSIGN" << endl;
        }
    }
    else if (the_token.tCode == PRINT){
        the_token = the_lexer.nextToken();
        if (the_token.tCode == ID) {
            cout << "PUSH " << the_token.lexeme << endl;
        }
        cout << "PRINT" << endl;
    }
    else if (the_token.tCode == ERROR) {
        error();
    }
 }

void Parser::expr() {
    term();

    if (the_token.tCode == PLUS) {
        the_token = the_lexer.nextToken();
        expr();
        cout << "ADD" << endl;
    }
    else if (the_token.tCode == MINUS) {
        the_token = the_lexer.nextToken();
        expr();
        cout << "SUB" << endl;
    }
    else if (the_token.tCode == ERROR) {
        error();
    }
}

void Parser::term() {
    factor();

    if (the_token.tCode == MULT) {
        the_token = the_lexer.nextToken();
        term();
        cout << "MULT" << endl;
    }
    else if (the_token.tCode == ERROR) {
        error();
    }
}

void Parser::factor() {
    if (the_token.tCode == INT) {
        cout << "PUSH " << the_token.lexeme << endl;
        the_token = the_lexer.nextToken();
    }
    else if (the_token.tCode == ID) {
        cout << "PUSH " << the_token.lexeme << endl;
        the_token = the_lexer.nextToken();
    }
    else if (the_token.tCode == LPAREN) {
        the_token = the_lexer.nextToken();
        expr();
        if (the_token.tCode == RPAREN) {
            the_token = the_lexer.nextToken();
        }
        else {
            error();
        }
    }
    else if (the_token.tCode == ERROR) {
        error();
    }
    else {
        error();
    }
}

void Parser::error() {
	cout << "Syntax error!" << endl;
	exit(1);
}
