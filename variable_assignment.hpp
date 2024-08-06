//handles variable assignment.
#pragma once

#include <iostream>
#include<string>
#include<vector>
#include "var_type_identifier.hpp"
using namespace std;

	 class initializer
{
		 public:
			 type obj;
			
			 struct Node
			 {
				 Node* nd_before;
				 string value;
				 string name;
				 string type;
				 Node* after;

				 Node(string nme, string val)
				 {
					 nd_before = NULL;
					 value = val;
					 name = nme;
					 after = NULL;
				 }
			 };

		int counter = 0; 
		Node* front = new Node("","");
		Node* ptr = front; // temporary variable to store the address of "front".
		Node* rear;
		void old_variable_modifier(string name, string value)
		{
			Node* ptr = front;
			while (ptr != NULL)
			{
				if (ptr->name == name)
				{
					ptr->value = value;
					string type;
					//obj.check(type);
					//ptr->type = type;
				}
				ptr = ptr->after;
			}
		}


		void new_variable_handle(string name, string value)
		{
		
			string type = obj.check(value);
			
			ptr->name = name;
			ptr->value = value;
			ptr->type = type;
			Node* new_ptr = new Node("","");
			ptr->after = new_ptr;

			if (counter == 0)
			{
				front = ptr;
			}
			ptr = new_ptr;
			
			counter++;
			back_pedal(front);
		}
																																																												
		
		void back_pedal(Node* front) // converts the before of all variables to match the addresses of the variables that came before them.
		{
			Node* ptr = front++;
			for (int x = 1; x < counter; x++)
			{
				ptr->nd_before = ptr - 1;
				ptr++;
			}
		}

		 int variable_cycle(string names) // checks if variable exists or not.
		{
			Node* ptr = front;
			int check = 0;
			while (ptr != NULL)
			{
			
				if (ptr->name == names)
				{
					check = 1;
				}
				ptr = ptr->after;
			}
			return(check);
		}

		 string return_value(string name)
		 {
			 Node* ptr = front;
			 while (ptr != NULL)
			 {
				 if (ptr->name == name)
				 {
					 return(ptr->value);
				 }
				 ptr = ptr->after;
			 }
			 return("undefined");
		 }

		 void print()
		 {
			 Node* ptr = front;
			 while (ptr != NULL)
			 {
				 cout << "var name : " << ptr->name << endl;
				 cout << "var value : " << ptr->value << endl;
				 ptr = ptr->after;
			 }
		 }



		void modifier(string name, string value) // checks if the variable already exists in the chain, if there it calls necessary fns to modify its value else it calls fns to create new variable.
		{
			
			
			int check = variable_cycle(name);
			
			if (check == 1)
			{
			old_variable_modifier(name, value);

			}
			else
			{
				new_variable_handle(name, value);
			}
			print();
			
		}
	
		

};
