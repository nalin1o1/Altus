#include <iostream>
#include<vector>
#include<string>
using namespace std;
//accepts user input.
class input_acc
{
public:
	string input()
	{
		cout << "keeps accepting input until you type /0" << endl;
		string input;
		getline(cin, input);

		return(input);
	}
};