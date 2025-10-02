#include "Tokenizer.hpp"
#include <string.h>
#include "lexicalanalysis.hpp"
#include <iostream>
#include <vector>
#define pb push_back

tkn splitterobject;
using namespace std;

int main()
{
	cout << "Enter the input string. \n";
	string input;
	cout << "\n";
	getline(cin,input);
	cout << "\n";
	vector<string>output = splitterobject.splitter(input);
	output.erase(output.begin());
	
	
	
	
	
	return(0);
}


//block lang = {block || statement}
BlockNode* block(int id,BlockNode* current,vector<string> tokenized, int streampointer)
{	
	current_token = tokenized[streampointer];
	BlockNode* BNode = CreateBlockNode(id+1,current,after);
	while(current_token != "}")
	{
		string symbol = get_classified(current_token);
		if(symbol == "OPERAND")
		{
			streampointer += 1;
			AstNode* operatorNode = createNode("OPERATOR",tokenized[streampointer],"var");
			BNode->pointers.pb(statement(tokenized,&streampointer,operatorNode));
		}
		else if(tokenized[streampointer] == "{")
		{
			streampointer +=1;
			BNode->pointers.pb(block(BNode->id,BNode,tokenized,&streampointer));
		}
		else
		{
			Error("Invalid Syntax");
		}
	}
	return(BNode);
}




//For function calls and assignments.
//returns a pointer to the astblock to link to higher nodes in the AST.
AstNode* statement(vector<string> tokenized, int* streampointer, AstNode* current)
{
	
	if(tokenized[streampointer] == "=")
	{	//creates an ast node for =. makes the left child = the LHS of the expression and the right child = the RHS of the expression.
		AstNode *newnode = CreateNode("ASSIGNMENT","=","null",null);
		newnode->left = current;
		*streampointer +=1;
		newnode->right = expression(tokenized,streampointer,newnode);
		return(newnode);
		
	}
	else
	{
		Error("Invalid Syntax");
	}
	
}





// Expression -> operand | operand operator Expression;
AstNode* expression(vector<string> tokenized, int* streampointer,AstNode* current)
{
	if(get_classified(tokenized[streampointer]) == "OPERAND")
	{
		
		AstNode* operandNode = CreateNode("OPERAND","a","var",null);
		*streampointer +=1;
		string symbol = get_classified(tokenized[streampointer]);
		if(symbol == "OPERATOR")	//handles operand operator E.
		{
			AstNode* operatorNode = CreateNode("OPERATOR","OPERATOR","OPERATOR",current);
			operandNode->before = operatorNode; //setting the parent of the operand equal to the operator.
			operatorNode->left = operandNode;
			operatorNode->right = expression(tokenized,streampointer);
			return(operatorNode);
		}
		else if(symbol == ";") //end of line
		{
			operandNode->before = current;
			return(operandNode);
		}
		else
		{
			Error("Invalid Syntax");
			
		}
		
	}
	else
	{
		Error("Invalid Syntax");
		return(0);
	}
	return(0);
}


