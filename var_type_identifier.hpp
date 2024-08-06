#include <iostream>
#include<vector>
#include<string>

using namespace std;

class type 
{
public:
	string check(string value)
	{
		
		//checking for string.
		
		if (value[0] == '"')
		{
			return("string");
		}
		//checking for float.
		if (value.find(".") != string::npos)
		{
			return("float");
		}
		// checking for integers.
		if (value == "_")
		{
			return("underscore");
		}
		if (stoi(value) != 0)
		{
			return("int");
		}
		else
		{
			return("unknown");
		}
		
	}
};