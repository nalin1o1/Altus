// This file contains
// Author

#include <string>
#include <vector>
#include <iostream>
#include "tokenizer.hpp"
#include "operation.hpp"
#include "variable_assignment.hpp"
#include "input.hpp"
#include "syntax_checker.hpp"
#include "token_identifier.hpp"

using namespace std;

// This class implements the entire python interpreter state.

// Usage:
//   myobj = control()
//   myobj.contrl()
class control
{
	synt_check syntax_check_object;
	operation operation_handler;
	initializer init_obj; // initializes the objects.
	tkn tokenizer;
	input_acc obj;
	string input = "";
	identify object;
public:


	void contrl()
	{	
		input_acc obj;
			
			
		
		string input = "";

		// The function exits when user enters specific keyword /0

		while(input != "/0")
		{
			jump:
			string input = obj.input();
			vector <string> tokenized = tokenizer.call_fn(input);
			int one_check = syntax_check_object.token_check(tokenized);
			tokenized = syntax_check_object.replaced(tokenized, init_obj);
			if (tokenized.at(0) == "null")
			{
				goto jump;
			}
			int two_check = syntax_check_object.sentence_logic_check(tokenized);
			
			if (one_check == 1 || two_check == 1)
			{
				goto jump;
			}
			
			//initializer* ptr = &init_obj;

			int result = operation_handler.super_oper(tokenized, init_obj);
			init_obj.print(); // prints the values of the variables.
			cout << result << endl;
			//input = obj.input();
			tokenized.clear();
		}
		
			cout << "done" << endl;
			exit(0);
		
	}
};

// this file handles the operations of the interpreter