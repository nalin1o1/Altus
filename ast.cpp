#include "Tokenizer.hpp"
#include <string.h>
#include "asTree.hpp"
#include "lexicalanalysis.hpp"
#include <iostream>
#include <vector>
#include "Error.hpp"
#define pb push_back

tkn splitterobject;
using namespace std;

class ASTCreation

{


public:

//block lang = {block || statement}
BlockNode* block(int id,BlockNode* current,vector<string> tokenized, int* streampointer)
{	
	string current_token = tokenized[*streampointer];
	BlockNode* BNode = CreateBlockNode(id+1,current,NULL);
	while(current_token != "}")
	{
		string symbol = get_classified(current_token);
		if(symbol == "OPERAND")
		{
			
			AstNode* operandNode = CreateNode("OPERAND",tokenized[*streampointer],"var",NULL);
			*streampointer += 1;
			BNode->pointers.push_back(statement(tokenized,streampointer,operandNode));
		}
		else if(tokenized[*streampointer] == "{")
		{
			*streampointer +=1;
			BNode->subBlocks.pb(block(BNode->id,BNode,tokenized,streampointer));
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
	
	if(tokenized[*streampointer] == "=")
	{	//creates an ast node for =. makes the left child = the LHS of the expression and the right child = the RHS of the expression.
		struct AstNode* newnode = CreateNode("ASSIGNMENT","=","null",NULL);
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
	if(get_classified(tokenized[*streampointer]) == "OPERAND")
	{
		
		AstNode* operandNode = CreateNode("OPERAND","a","var",NULL);
		*streampointer +=1;
		if(*streampointer == tokenized.size())
		{
			Error("Out of Bounds");
		}
		string symbol = get_classified(tokenized[*streampointer]);
		if(symbol == "OPERATOR")	//handles operand operator E.
		{
			AstNode* operatorNode = CreateNode("OPERATOR","OPERATOR","OPERATOR",current);
			operandNode->before = operatorNode; //setting the parent of the operand equal to theoperator.		
			operatorNode->before = current;
			operatorNode->left = operandNode;
			*streampointer+=1;
			operatorNode->right = expression(tokenized,streampointer,operatorNode);
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

};

int main()
{
	cout << "Enter the input string. \n";
	string input;
	cout << "\n";
	getline(cin,input);
	cout << "\n";
	vector<string>output = splitterobject.splitter(input);
	output.erase(output.begin());
	for(int i = 0;i < output.size();i++)
	{	
		if(output[i] == "")
		{
			output.erase(output.begin() + i);
			i-=1;
		}
	}
	ASTCreation obj;
	int streampointer = 0;
	obj.block(0,NULL,output,&streampointer);
	
	
	
	return(0);
}

