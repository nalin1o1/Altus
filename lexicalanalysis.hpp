#include<iostream>
#include<vector>
#include<string.h>

string get_classified(string token)
{
	vector<string> operators = {"+","-","/","*","%","!","=","<="};
	for(int i =0; i < operators.size();i++)
	{
		if (token == operators[i])
		{
			return("OPERATOR");
		}

		
		else
		{
			return("OPERAND");
		}
	}
}

int main()
{
	
}
