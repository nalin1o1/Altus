
#pragma once
#include "variable_assignment.hpp"
#include <string>
#include <vector>
#include <iostream>
#include "token_identifier.hpp"
using namespace std;

class operation
{

	
	//initializer* assign_pointer;
	vector<string> operand_types{ "int","float","string","long","double","bool" };

	int addition(int a, int b)
	{
		return(a + b);

	}
	int sub(int a, int b)
	{
		return(a - b);
	}

	int mult(int a, int b)
	{
		return(a * b);
	}
	float division(int a, int b)
	{
		return(a / b);
	}
	int post_inc(int a)
	{
		return(++a);
	}
	void assignment(string name, string value, initializer &initializer_object)
	{
		initializer_object.modifier(name, value);

	}
	string sym(string a, string b)
	{
		if (a == b)
		{
			return("+");
		}
		else
		{
			return("-");
		}
	}
	// removes any consecutive symbols.
	vector <string> corrector(vector <string> input)
	{
		vector <string> full_input = input; // stores a copy of the input vector with the "=".
		int check = 0;
		int equals_index = 0;
		for (int x = 0; x < input.size();x++)
		{
			if (input.at(x) == "=")
			{
				check = 1;
			}
				
		}
		
	/*		if (check == 1)
			{
				while (input.at(0) != "=") // eliminates the "=" in the input statement.
				{
					input.erase(input.begin());
				}
				input.erase(input.begin());
			}
		*/	
			

		vector <string> corrected;
		int length = input.size();
		string new_element;
		for (int x = length - 1; x >= 0; x--)
		{
			
			string	operator_ele = input.at(x);
			if (operator_ele == "+" || operator_ele == "-")
			{
				for (int i = 0; i < x; i++)
				{
					
					if (i == x - 1)
					{
						
						string	prev_operator_ele = input.at(i);

						if (prev_operator_ele == "+" || prev_operator_ele == "-")
						{
							
							new_element = sym(operator_ele, prev_operator_ele);
							corrected.push_back(new_element);
							x -= 1;
						}
						else
						{
							corrected.push_back(operator_ele);
						}

					}
				}

			}
			else
			{
				corrected.push_back(operator_ele);
			}
		}

		vector <string> inverted;
		int length1 = corrected.size();

		for (int x = length1 - 1; x >= 0; x--)
		{
			inverted.push_back(corrected.at(x));

		}
		return(inverted);
	}

	int index_finder(vector <string> input)
	{
		//() is looked for using a special if case.
		vector <string> p1{ "(", " )" };
		//p2 looks for values in array elements.
		vector<string>p2{ "","" };
		vector<string>p3{ "await" };
		vector<string>p4{ "**" };
		//unary +,- and bitwise NOT.
		vector<string>p5{ "~" };
		vector<string>p6{ "*","@","/","//","%" };
		//addition and subtraction.
		vector<string>p7{ "+","-" };
		vector<string>p8{ "<<",">>" };
		//bitwise and.
		vector<string>p9{ "&" };
		vector<string>p10{ "^" };
		vector<string>p11{ "|" };
		vector<string>p12{ "in","not in", "is","is not","<","<=",">",">=","!=","==" };
		vector<string>p13{ "not" };
		vector<string>p14{ "and" };
		vector<string>p15{ "or" };
		vector<string>p16{ "=" }; // assignment happens at the end.
		//no if else yet.
		vector <vector<string>> operators{ p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16 };
		int index = 0;
		//iterates through the operator table.
		for (int x = 0; x < operators.size(); x++)
		{
			vector <string> temp_vec = operators.at(x);
			//iterates through each precedence element.
			for (int y = 0; y < input.size(); y++)
			{
				for (int i = 0; i < temp_vec.size(); i++)
				{
					if (temp_vec.at(i) == input.at(y))
					{
						index = y;
						return(y);
					}
				}
			}
		}

	}
	string parenthesis_operation(vector<string> input, initializer &initializer_object)
	{
		
		if (input.size() == 1)
		{
			return(input.at(0));
		}
		string output = to_string(opera(input, initializer_object));
		return(output);
	}

	int opera(vector <string> input, initializer &initializer_object)
	{
		//function loops after performing each individual operation.
		vector <string> storage_vec = input;
		vector <string> operation_order;
		vector <string> p1{ "(", " )" };
		//p2 looks for values in array elements.
		vector<string>p2{ "","" };
		vector<string>p3{ "await" };
		vector<string>p4{ "**" };
		//unary +,- and bitwise NOT.
		vector<string>p5{ "~" };
		vector<string>p6{ "*","@","/","//","%" };
		//addition and subtraction.
		vector<string>p7{ "+","-" };
		vector<string>p8{ "<<",">>" };
		//bitwise and.
		vector<string>p9{ "&" };
		vector<string>p10{ "^" };
		vector<string>p11{ "|" };
		vector<string>p12{ "in","not in", "is","is not","<","<=",">",">=","!=","==" };
		vector<string>p13{ "not" };
		vector<string>p14{ "and" };
		vector<string>p15{ "or" };
		vector<string>p16{ "=" };
		float result;
		int p_opening = 0;
		int p_closing = 0;
		int operation_start_index;
		int operation_end_index;
		//no if else yet.
		vector <vector<string>> operators{ p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16 };

		int index;
		// loop identifies the first operation to be performed and stores the index of the operator.
	////////////////////////////////////////////////
		int counter = 0;
		//changes made here.
		index = index_finder(storage_vec);
		identify iden_obj;
		vector <string> tkn_types = iden_obj.classify(storage_vec);
		
		////////
		// 
		// 
		// 
		// 
		// 
		// 
		// to operate on parenthesis.
		if (storage_vec.at(index) == "(")
		{
			vector <int> parenthesis_idx_vec;
			int counter;

			int x = 0;
				while (storage_vec.at(x) != ")")
				{
					if (storage_vec.at(x) == "(")
					{
						parenthesis_idx_vec.push_back(x);
					}
					x++;
				}
				p_closing = x;
			

			p_opening = parenthesis_idx_vec.at(parenthesis_idx_vec.size() - 1);

			int end_p;
			vector <string> inside_p;
			for (int x = 1 + p_opening; x < p_closing; x++)
			{

				inside_p.push_back(storage_vec.at(x));
	
			}
			result = stoi(parenthesis_operation(inside_p, initializer_object));


			operation_start_index = p_opening - 1;
			operation_end_index = p_closing + 1;
			vector <string> vec1; // 3rd phase
			vector <string> vec2;
			vector <string> finvec; //stores the resultant vector;

			int storage_length = storage_vec.size();




			string res = to_string(result);
			if (operation_start_index != -1)
			{
				
				for (int x = 0; x <= operation_start_index; x++)
				{
					vec1.push_back(storage_vec.at(x));
					
				}
				vec1.push_back(res);
				// result of the operation is pushed to the back of vec1.
			}


			else
			{
				
				vec1.push_back(res);
			}

			

			

			
			int counter1 = 0;
			

			if ((operation_end_index >= storage_length) == false)
			{
			
				//for vec2.
				for (int x = operation_end_index;x < storage_length; x++)
				{
					
					vec2.push_back(storage_vec.at(x));

					
				}
				counter1++;
				
			}

			// this segment stores vec1 and vec2 inside final vector.
			// 
	/////////////////////////////////////////////
			
			// checking for vec2.

			/////
			finvec = vec1;

			for (int x = 0; x < vec2.size(); x++)
			{
				finvec.push_back(vec2.at(x));
			}
			//////////////////////////////////////////////
			
			//returns final result.
			vec1.clear();
			vec2.clear();
			if (finvec.capacity() == 1)
			{
				cout << "final value : " << finvec.at(0) << endl;
				return(stoi(finvec.at(0)));
			}

			return(opera(finvec, initializer_object));
		}
		// done.
				////////

		//////to operate if parenthesis does not exist
		else
		{

			vector <string> vec1; // 3rd phase
			vector <string> vec2;
			vector <string> finvec; //stores the resultant vector;

			int storage_length = storage_vec.size();

			int x = index;
			int index1 = x - 1;
			int index2 = x + 1;
			operation_start_index = index1 - 1;
			operation_end_index = index2 + 1;
			string operand1;
			/*
			if (storage_vec.at(x) != "=")
			{
			
			operand1 = stoi(storage_vec.at(index1));
			}
			
			int operand2 = stoi(storage_vec.at(index2)); // error is here
			*/
			string operand2;
			
				operand1 = storage_vec.at(index1);
			
			
			
				operand2 = storage_vec.at(index2);
			

			

			if (storage_vec.at(x) == "=")
			{
				assignment(operand1, operand2, initializer_object); // handles assignment.
				return(0);
			}
			if (storage_vec.at(x) == "+")
			{
				result = addition(stoi(operand1), stoi(operand2));
			}
			if (storage_vec.at(x) == "-")
			{
				result = sub(stoi(operand1), stoi(operand2));
			}
			if (storage_vec.at(x) == "*")
			{
				result = mult(stoi(operand1), stoi(operand2));
			}
			if (storage_vec.at(x) == "/")
			{
				result = division(stoi(operand1), stoi(operand2));
			}



			string res = to_string(result);
			if (operation_start_index != -1)
			{
				
				for (int x = 0; x <= operation_start_index; x++)
				{
					vec1.push_back(storage_vec.at(x));
					
				}
				vec1.push_back(res);
				// result of the operation is pushed to the back of vec1.
			}


			else
			{
				
				vec1.push_back(res);
			}

			

			
			
			int counter1 = 0;
			

			if ((operation_end_index >= storage_length) == false)
			{
				
				//for vec2.
				for (int x = operation_end_index;x < storage_length; x++)
				{
					
					vec2.push_back(storage_vec.at(x));

					
				}
				counter1++;
				
			}

			// this segment stores vec1 and vec2 inside final vector.
			// 
	/////////////////////////////////////////////
			
			// checking for vec2.

			/////
			for (int c = 0; c < vec1.size(); c++)
			{
				finvec.push_back(vec1.at(c));
				
			}
			for (int x = 0; x < vec2.size(); x++)
			{
				finvec.push_back(vec2.at(x));
			}
			//////////////////////////////////////////////
			
			//returns final result.
			vec1.clear();
			vec2.clear();
			if (finvec.capacity() == 1)
			{
				cout << "final value : " << finvec.at(0) << endl;
				int val = stoi(finvec.at(0));
				return(val);
			}

			return(opera(finvec, initializer_object));
		}
	}

	public:
	int super_oper(std::vector<std::string> input, initializer &pointer)
	{
		//assign_pointer = pointer;
		vector <string> storage_vec = corrector(input);
		int result = opera(storage_vec,pointer);
		
		return result;
	}
	operation()
	{
		cout << "Constructed";
	}
	~operation()
	{
		cout << "Destroyed";
	}
};


