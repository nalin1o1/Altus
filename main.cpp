
//Author : Nalin
//		   python interpreter using c++, for the shakti microprocessor.
#include "Central_control.hpp"	// importing the central control file.
#include "variable_assignment.hpp" // importing the header file handling the variable assignment.
#include"tokenizer.hpp"  // importing the tokenizer.
#include "syntax_checker.hpp" // imprting the syntax checker.
#include <iostream>
#include <assert.h>
#include <vector>
#include "token_identifier.hpp" // importing the token identifier.

//#include "operation.hpp"
#include <exception>
using namespace std;




int main()
{
	control contrl_obj;
	contrl_obj.contrl();
	
	
}

