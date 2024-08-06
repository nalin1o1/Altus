/*

#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;


	vector<string>de_limiters{ "=","!","%","^","&","*",";","-","+","/","." };
	vector<int>de_limiters_input;//stores the indices of the de_limiters in the input vector.
	vector<string>types_tokens{ "string","operator","integer","float" };
	vector<string>tokens; // stores the tokens inside the input.
	vector<string>token_type; // stores the types of the tokens

	vector<string> tokenizer(vector<string> input) 
	{
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
				}
			}
			finalv.push_back(temp);
		}
		return(finalv);
	}


	vector<string> splitter(string val)
	{
		val += ";";
		int length = val.length();
		vector<string> input ;
		
		for (int x = 0; x < length;x++)
		{
			string temp; 
			temp += val[x];
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
			cout << "inside the loop" << endl;
			int start_ind = de_limiters_input.at(x);
			int last_ind = de_limiters_input.at(x+1);
			tokens.push_back(input.at(start_ind));
			string tk;
			for (int y = start_ind + 1; y < last_ind; y++)
			{
				tk = tk + input.at(y);
			}
			tokens.push_back(tk);
			x++;
		}

		for (int x = 0; x < tokens.size(); x++)
		{
			cout << tokens.at(x) << endl;
		}

		vector<string>finalized_tokens = tokenizer(tokens);
		int len = finalized_tokens.size();
		cout << "len : " << len << endl;
		for (int x = 0; x < len; x++)
		{
			cout << "inside the final for loop" << endl;
			cout << finalized_tokens.at(x) << endl;
		}
		return(finalized_tokens);

	}


	vector<string> input()
	{

		string in;
		cin >> in;
		
		
		vector<string> input = splitter("int a = b + c");
		return(input);
	}

	int main()
	{
		input();
		return(0);
	}

	
	*/
