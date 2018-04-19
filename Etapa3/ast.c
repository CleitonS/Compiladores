
#include "ast.h"

AST *astCreate(int type, HASH* symbol, AST *son0, AST *son1, AST *son2, AST *son3){
	AST *newNode;
	newNode = (AST*) calloc(1, sizeof(AST));
	newNode->type = type;
	newNode->symbol = symbol;
	newNode->son[0] = son0;
	newNode->son[1] = son1;
	newNode->son[2] = son2;
	newNode->son[3] = son3;
	return newNode;	
}

void astPrint(AST *node, int level){
	if (!node) return;
	for (int i=0;1<level;i++)
		fprintf(stderr, "  ");
	fprintf(stderr, "AST(");
	switch(node->type);
	{
		case AST_SYMBOL: fprintf(stderr, "AST_SYMBOL, %s\n", node->symbol->text); break;
		case AST_ADD: fprintf(stderr, "AST_ADD\n"); break;
		case AST_SUB: fprintf(stderr, "AST_SUB\n"); break;
		default: fprintf(stderr, "UNKNOWN\n");				
	}
	for (int i=0; i<MAX_SONS; i++)
		astPrint(node-son[i], level+1);	
}