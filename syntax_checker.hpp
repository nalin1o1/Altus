#include <iostream>
#include <string>
#include <vector>
#include"token_identifier.hpp"
#include "variable_assignment.hpp"
using namespace std;
//checks grammatical correctness.

#pragma once
class synt_check
{


public:
	//this function checks if each token is correct python syntax wise. 
	//this function takes a vector of strings containing all the tokens as arguments.
	//this function calls the function error_met() if the token has incorrect syntax.
		int token_check(vector <string> tokens)
	{
		identify obj;
		vector <string> type = obj.classify(tokens);
		int length = tokens.size();
		for (int x = 0; x < length; x++)
		{
			string word = tokens.at(x); // stores the token.
			string word_type = type.at(x); // stores the type of the token.

			if (word_type == "variable") // checks syntax for variables.
			{
				string first_letter;
				first_letter.assign(1, word[0]);
				if (obj.character_classification(first_letter) != "letter") // makes sure the first letter of the variable name is a letter.
				{
					return(1);
				}

				for (int x = 0; x < word.length(); x++) // makes sure the variable name does not have anything other than letters or underscore.
				{
					string characters;
					characters.assign(1, word[x]);
					if (!(obj.character_classification(characters) == "letter" || obj.character_classification(characters) == "underscore" || obj.character_classification(characters) == "number"))
					{
						return(1);
					}
				}

			}

			if (word_type == "number") // makes sure that all the characters in a "number" are really numbers.
			{
				for (int x = 0; x < word.length(); x++)
				{
					string charac(1,word[x]);
					if (obj.character_classification(charac) != "number")
					{
						return(1);
					}
					
				}
			}

			if (word_type == "string") // makes sure the string is complete.
			{
				
				if (word[word.length() - 1] != '"')
				{
					return(1);
				}
			}


		}
	return(0);

	}

	int sentence_logic_check(vector<string> tokens)
	{
		identify obj;
		vector <string> token_types = obj.classify(tokens);

		//make sure all brackets are closed.
		vector <string> opening_bracket{"(","[","{"};
		vector <string> closing_bracket{")","]","}"};
		vector<int> o_counter;
		vector<int>c_counter;
		int ocounter = 0; // stores the number of opening brackets of each type.
		int ccounter=  0; // stores the number of closing brackets of each type.
		
		for(int x = 0; x <3;x++)
		{
			
			for (int y = 0; y < token_types.size(); y++)
			{
				
				string word;
				word = token_types.at(y);
				// check if all the variables have been previously defined.
				if (word == "undefined")
				{
					error_met();
				}
				
				if(word == opening_bracket.at(x))
				{
					ocounter++;
				}
				if (word == closing_bracket.at(x))
				{
					ccounter++;
				}
				
			}
			o_counter.push_back(ocounter);
			c_counter.push_back(ccounter);
			ocounter = 0;
			ccounter = 0;
		}
		for (int x = 0; x < 3; x++) // checks if all the brackets are closed.
		{
			if (o_counter.at(x) != c_counter.at(x))
			{
				cout << "brackets not closed" << endl;
				return(1);
			}
		}
		// two tokens cannot exist without a seperator or an operator between them.
			//for(int x = 0; x < ) requires the type of the symbol (operator, seperator etc.)

		// make sure that all the operators have the allowed and necessary operands. (bool operators cannot have arithmeic operands)
		for (int x = 0;x < token_types.size();x++)
		{
			if (token_types.at(x) == "operator") //for an operation the types of both the operands must be the same.
			{
				string op1;
				string op2;
				op1 = token_types.at(x - 1);
				op2 = token_types.at(x + 1);
				if (op1 != op2)
				{
					cout << "\n" << endl;
					cout << "operand types dont match" << endl;
					return(1);
				}
			}

			// check if assignment is being done to a constant.
			// make sure there are no illegal assignments (a = 34 + 56 = b)
			if (tokens.at(x) == "=")
			{
				if (token_types.at(x - 1) == "number" || token_types.at(x - 1) == "string")
				{
					cout << "\n" << endl;
					cout << "assignment being done to a constant" << endl;
					return(1);
				}
			}

			// check if number is being divided by zero
			if (tokens.at(x) == "/")
			{
				string word = tokens.at(x + 1);
				if (word == "0")
				{
					cout << "\n" << endl;
					cout << "division by zero" << endl;
					return(1);
				}
			}
		}
		
		cout << "no errors" << endl;
		
		return(0);
		
		// make sure for loops and if statements have the correct syntax
		// no incorrect operator placements. (a = 435 / 345  // 234)
	}
	// stores the variable values instead of the variable names.

	vector <string> replaced(vector <string> tokens, initializer &object)
	{
		vector <string> rep;
		vector <string> err{ "null" }; // the error signal.
		int check = 0; // holds the position of assignment operator.
		for (int x = 0; x < tokens.size();x++)
		{
			if (tokens.at(x) == "=")
			{
				check = x;
				break;
			}
		}
		int assignment  = 0;
		if (check != 0)
		{
			assignment = check+1;
			check++;
			while (check < tokens.size()) // has all the elements of the vector beyond the =.
			{
				rep.push_back(tokens.at(check));
				check++;
			}
			
		}
		else
		{
			rep = tokens;
		}
		
		
		identify obj;
		vector<string>tokens_type = obj.classify(rep);
		for (int x = 0; x < rep.size(); x++)
		{
			if (tokens_type.at(x) == "variable")
			{
				string name = rep.at(x);
				
				string value = object.return_value(name);

				if (value == "undefined")
				{
					cout << "variable undefined" << endl;
					
					return(err);
					
				}
				else
				{
					rep.at(x) = value;
				}
			}
		}
		
		for (int x = 0; x < rep.size(); x++)
		{
			
			tokens.at(assignment) = rep.at(x);
			assignment++;
		}
		
		int check2 = token_check(tokens); // checks the syntax of the new vector.
		int check1 = sentence_logic_check(tokens);// checks the syntax of the sentence formed by the new vector.
		if (check1 == 1 || check2 == 1)
		{
			return(err);
		}
		return(tokens);
	}


	void error_met()
	{
		cout << "error! ** invalid syntax" << endl;
		exit(0);
	}
	/*
	vector <string> syntax_central(vector <string> input, initializer &obj)
	{
		token_check(input);
		vector <string> new_vec = replaced(input, obj);
		sentence_logic_check(new_vec);
		return(new_vec);
	}
	*/
};
