#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

string get_classified(string token)
{
	vector<string> operators = {"+","-","/","*","%","!","=","<="};
	for(int i =0; i < operators.size();i++)
	{
		if (token == operators[i])
		{
			return("OPERATOR");
		}

		else if(token == ";")
		{
			return(";");
		}
		else
		{
			return("OPERAND");
		}
	}
	return("");
}


