
#pragma once

#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;

class tkn
{
public : 
	vector<string>de_limiters{ "=","!","%","^","&","*",";","-","+","/"," ",".","==","+=","-=",">=","<=","<<","(",")"};
	vector<int>de_limiters_input;//stores the indices of the de_limiters in the input vector.
	vector<string>types_tokens{ "string","operator","integer","float" };
	vector<string>tokens; // stores the tokens inside the input.
	vector<string>token_type; // stores the types of the tokens

	vector<string> tokenizer(vector<string> input)
	{		//
		vector<string> finalv;
		int length = input.size();
		for (int x = 0; x < length; x++)
		{
			string temp;
			for (int y = 0; y < input.at(x).length(); y++)
			{
				string word = input.at(x);
				if (word[y] != ' ')
				{

					temp += word[y];
					if (word[y + 1] == ' ')
					{
						goto jump;
					}
				}
			}
		jump:
			finalv.push_back(temp);
		}
		return(finalv);
	}
	int index_storage(vector<string>input)
	{
		int length1 = input.size();
		for (int x = 0; x < length1; x++) // stores the indices of the operators in the input vector.
		{
			for (int y = 0; y < de_limiters.size(); y++)
			{
				if (input.at(x) == de_limiters.at(y))
				{
					
					de_limiters_input.push_back(x);
				}
			}
		}
		return(0);
	}

	vector <string> modifi(vector <string> input) // removes duplicate operators and replaces them with a single one.
	{
		vector <string> output;
		int x = 0;
		while (x < input.size())
		{
			output.push_back(input.at(x));
			for (int y = 0; y < de_limiters_input.size();y++)
			{
				if (x == de_limiters_input.at(y))
				{
					if (de_limiters_input.at(y + 1) - de_limiters_input.at(y) == 1) // means that x and x+1 both have operators.
					{
						int id1 = de_limiters_input.at(y);
						int id2 = de_limiters_input.at(y + 1);
						string word = input.at(id1) + input.at(id2);
						output.insert(output.begin() + x, word);
						x++;
						goto jump;
					}


				}
			}
		jump:
			x++;
		}
		for (int x = 0; x < output.size(); x++)
		{
			
		}
		return(output);
	}


	vector<string> splitter(string val)
	{
		//
		string f_val = ";" + val + ";";
		int length = f_val.length();
		vector<string> input;

		for (int x = 0; x < length;x++)
		{
			string temp;
			temp += f_val[x];
			input.push_back(temp);
		}

		int length1 = input.size();

		for (int x = 0; x < length1; x++) // stores the indices of the operators in the input vector.
		{
			for (int y = 0; y < de_limiters.size(); y++)
			{
				if (input.at(x) == de_limiters.at(y))
				{
					de_limiters_input.push_back(x);
				}
			}
		}





		int x = 0;
		int limit = de_limiters_input.size() - 2;
		while (x <= limit) // cycles till the second last element.
		{
			
			int start_ind = de_limiters_input.at(x);
			int last_ind = de_limiters_input.at(x + 1);
			tokens.push_back(input.at(start_ind));
			string tk;
			for (int y = start_ind + 1; y < last_ind; y++)
			{
				tk = tk + input.at(y);
			}
			tokens.push_back(tk);
			x++;
		}

		

		vector<string>finalized_tokens = tokenizer(tokens);
		int len = finalized_tokens.size();
		
		
		return(finalized_tokens);

	}

	int op_verify(string input)
	{
		for (int x = 0; x < de_limiters.size();x++)
		{
			 
			if (input == de_limiters.at(x))
			{
				return(1);

			}
			
		}
		return(0);
	}

	

	vector<string> input(string user_input)
	{




		vector<string> input = splitter(user_input);
		vector <string> output;
		int length = input.size();
		for (int x = 0; x < length; x++)
		{
			string ss = input.at(x);
			if ((ss != ""))
			{
				output.push_back(input.at(x));

			}
		}



		// fixes operators.

		int counter = 0;
		for (int x = 0; x < output.size() - 1; x++)
		{
			
			int o1 = op_verify(output.at(x));
			int o2 = op_verify(output.at(x + 1));
			
			if (o1 == o2)
			{
			
				string word;
				word += output.at(x) + output.at(x + 1);
			
				if (op_verify(word) == 1)
				{
				
					output.insert(output.begin() + x, word);
					output.erase(output.begin() + (x + 1));
					output.erase(output.begin() + (x + 1));
				}
			}
		}
		output.erase(output.begin());
		
		return(output);
	}


	





	public:
		vector <string>	call_fn(string input_string)
		{
			vector <string> tokenized;
			tokenized = input(input_string);
			tokens.clear();
			de_limiters_input.clear();
			return(tokenized);

	}
};











