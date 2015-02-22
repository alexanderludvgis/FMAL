#include <cstdlib>
#include <stack>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <unordered_map>
#include <iterator>

using namespace std;

int main()
{
    string input, str, op, tmp, tmp2, tmp3;
    int pos = 0;
	int num1 = 0;
	int num2 = 0;
	bool in_map = false;
	bool in_map2 = false;
	unordered_map<string, int> the_map;
	stack<string> the_stack;

	//str = "PUSH a PUSH 2 ASSIGN PUSH a PRINT";

    // read in the input and set to str
    while (!cin.eof()) {
        getline(cin, input);
        if (cin.fail())
            break;
        str += input + " ";
	}

    while (!str.empty()) {

        //PUSH op:
        if (str.substr(0, 4) == "PUSH") {
            //remove PUSH + whitespace from str
            str.erase(0, 5);
            //find the whitespace after op
            pos = str.find(" ");
            //declare the operand
            op = str.substr(0, pos);
            //push op to on stack
            the_stack.push(op);
            //remove op + whitespace
            str.erase(0, pos + 1);
        }
        //ADD:
        else if (str.substr(0, 3) == "ADD") {
            str.erase(0, 4);
            //get the top element on the stack
            tmp = the_stack.top();
            //and remove it from the stack
            the_stack.pop();
            tmp2 = the_stack.top();
            the_stack.pop();

            for (auto i = the_map.begin(); i != the_map.end(); i++) {
				if (i->first == tmp) {
					num1 = i->second;
					in_map = true;
				}
			}
			if (!in_map)
			{
				istringstream(tmp) >> num1;
			}

			for (auto i = the_map.begin(); i != the_map.end(); i++) {
				if (i->first == tmp2) {
					in_map2 = false;
					num2 = i->second;
				}
			}
			if (!in_map2){
				istringstream(tmp2) >> num2;
			}

            //Add the numbers together and push to stack
            num1 = num1 + num2;
            tmp3 = to_string(static_cast<long long>(num1));
            the_stack.push(tmp3);
        }
        //SUB:
        else if (str.substr(0, 3) == "SUB") {
            str.erase(0, 4);
            tmp = the_stack.top();
            the_stack.pop();
            tmp2 = the_stack.top();
            the_stack.pop();

            for (auto i = the_map.begin(); i != the_map.end(); i++) {
				if (i->first == tmp) {
					num1 = i->second;
					in_map = true;
				}
			}
			if (!in_map)
			{
				istringstream(tmp) >> num1;
			}

			for (auto i = the_map.begin(); i != the_map.end(); i++) {
				if (i->first == tmp2) {
					in_map2 = false;
					num2 = i->second;
				}
			}
			if (!in_map2){
				istringstream(tmp2) >> num2;
			}

            //Sub the numbers together and push to stack
            num1 = num2 - num1;
            tmp3 = to_string(static_cast<long long>(num1));
            the_stack.push(tmp3);
        }
        //MULT:
        else if (str.substr(0, 4) == "MULT") {
            str.erase(0, 5);
            tmp = the_stack.top();
            the_stack.pop();
            tmp2 = the_stack.top();
            the_stack.pop();

            for (auto i = the_map.begin(); i != the_map.end(); i++) {
                if (i->first == tmp) {
                    num1 = i->second;
                    in_map = true;
                }
            }
            if (!in_map)
            {
                istringstream(tmp) >> num1;
            }

            for (auto i = the_map.begin(); i != the_map.end(); i++) {
                if (i->first == tmp2) {
                    in_map2 = false;
                    num2 = i->second;
                }
            }
            if (!in_map2){
                istringstream(tmp2) >> num2;
            }

            //Multiply the numbers together and push to stack
            num1 = num1 * num2;
            tmp3 = to_string(static_cast<long long>(num1));
            the_stack.push(tmp3);
        }
        //ASSIGN:
        else if (str.substr(0, 6) == "ASSIGN") {
            str.erase(0, 7);
            tmp = the_stack.top();
            the_stack.pop();
            tmp2 = the_stack.top();
            the_stack.pop();

            istringstream(tmp) >> num1;
            num1 = stoi(tmp);

            //assigns the first element (a value)
            //to the second element (a variable)
            the_map[tmp2] = num1;
        }
        //PRINT:
        else if (str.substr(0, 5) == "PRINT") {
            tmp = the_stack.top();

            for (auto i = the_map.begin(); i != the_map.end(); i++) {
                if (i->first == tmp) {
                    in_map = true;
                    cout << i->second << endl;
                }
            }
            str.erase(0, 6);
            //Exit the While loop on top
            return 0;
        }

        else {
            cout << "Syntax error!" << endl;
        }

    }

    return 0;
}
