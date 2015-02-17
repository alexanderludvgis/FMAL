#include "Lexer.h"

Lexer::Lexer()
{
    //ctor
}

Lexer::~Lexer()
{
    //dtor
}

Token Lexer::nextToken(string& result)
{
  /*
    //open file
	ifstream inFile("test.txt");

	char c;
	string result;
	while (inFile >> c) {
        result.push_back(c);

	}

	cout << result << endl;
*/

    Token myToken = Token();

    //if END
	if (result.at(0) == 'e') {
        if (result.at(1) == 'n') {
            if (result.at(2) == 'd') {
                myToken.lexeme = "end";
                myToken.tCode = END;
                result.erase(0,3);
            }
        }
	}
    //if PRINT
    else if (result.at(0) == 'p') {
        if (result.at(1) == 'r') {
            if (result.at(2) == 'i') {
                if (result.at(3) == 'n') {
                    if (result.at(4) == 't') {
                        myToken.lexeme = "print";
                        myToken.tCode = PRINT;
                        result.erase(0,5);
                    }
                }
            }
        }
	}
    // if INT
    else if (isdigit(result.at(0))) {
        int i = 0;
        string tala = "";
        while (isdigit(result.at(i))) {
            tala.push_back(result.at(i));
            result.erase(0,1);
        }
        myToken.lexeme = tala;
        myToken.tCode = INT;
    }
    //if ASSIGN
    else if (result.at(0) == '=') {

        myToken.lexeme = "=";
        myToken.tCode = ASSIGN;
        result.erase(0,1);
    }
    //if SEMICOL
    else if (result.at(0) == ';') {
        myToken.lexeme = ";";
        myToken.tCode = SEMICOL;
        result.erase(0,1);
    }
    //if PLUS
    else if (result.at(0) == '+') {
        myToken.lexeme = "+";
        myToken.tCode = PLUS;
        result.erase(0,1);
    }
    //if MINUS
    else if (result.at(0) == '-') {
        myToken.lexeme = "-";
        myToken.tCode = MINUS;
        result.erase(0,1);
    }
    //if MULT
    else if (result.at(0) == '*') {
        myToken.lexeme = "*";
        myToken.tCode = MULT;
        result.erase(0,1);
    }
    //if LPAREN
    else if (result.at(0) == '(') {
        myToken.lexeme = "(";
        myToken.tCode = LPAREN;
        result.erase(0,1);
    }

    //if RPAREN
    else if (result.at(0) == ')') {
        myToken.lexeme = ")";
        myToken.tCode = RPAREN;
        result.erase(0,1);
    }

    //if ID
    else if (isalpha(result.at(0))) {
        string str = "";

        // while alpha
        while (isalpha(result.at(0))) {
            str.push_back(result.at(0));
            result.erase(0,1);
        }
        myToken.lexeme = str;
        myToken.tCode = ID;
    }
    else {
        myToken.lexeme = result.at(0);
        myToken.tCode = ERROR;
    }

    cout << "lexeme: " << myToken.lexeme << " tCode: " << myToken.tCode << endl;
	return myToken;
}

