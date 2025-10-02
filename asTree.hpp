#include <iostream>
#include <vector>
#include <string>
#define pb push_back 

struct AstNode
{
	
	string token;
	string value;
	string type;
	AstNode *before;
	AstNode *left;
	AstNode *right;
};


struct BlockNode
{
	int id;
	vector <AstNode*>pointers;
	blockNode* before;
	blockNode* after;
	
};

AstNode* CreateNode(string token, string value, string type, AstNode *current)
{
	AstNode* newnode = new AstNode;
	newnode->token = token;
	newnode->value = value;
	newnode->type = type;
	newnode->before = current;
	return(newnode);
	
}

BlockNode* CreateBlockNode(int id, BlockNode* before, BlockNode* after)
{
	BlockNode* newnode = new BlockNode;
	newnode->before = before;
	newnode->after = after;
	newnode->id = id;
	return(newnode);
}


