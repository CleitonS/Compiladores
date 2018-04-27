#include <stdlib.h>
#include <stdio.h>
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
		case AST_SYMBOL:
			if(node->symbol)
				if(node->symbol->text)
					fprintf(TreeToFile,"%s",node->symbol->text);	
			break; 
		
		case AST_IF:
			fprintf(TreeToFile,"if ( ");
			printAST_NODE(node->son[0]);				
			fprintf(TreeToFile,") then\n");
			printAST_NODE(node->son[1]);				
			break;             
											
		case AST_ELSE:
			fprintf(TreeToFile,"if ( ");
			printAST_NODE(node->son[0]);				
			fprintf(TreeToFile,") then\n");
			printAST_NODE(node->son[1]);				
			fprintf(TreeToFile,"else \n");
			printAST_NODE(node->son[2]);				
			break;                      
											
		case AST_WHIL:
			fprintf(TreeToFile,"while ( ");
			printAST_NODE(node->son[0]);				
			fprintf(TreeToFile,") \n");
			printAST_NODE(node->son[1]);				
			break; 
		
		
		case AST_SOMA:
			printAST_NODE(node->son[0]);		
			fprintf(TreeFile,"+ ");
			printAST_NODE(node->son[1]);		
			break;             
											
		case AST_SUBT:
			printAST_NODE(node->son[0]);		
			fprintf(TreeFile,"- ");
			printAST_NODE(node->son[1]);		
			break;             
											
		case AST_MULT:
			printAST_NODE(node->son[0]);		
			fprintf(TreeFile,"* ");
			printAST_NODE(node->son[1]);		
			break;                         
											
		case AST_MENO:
			printAST_NODE(node->son[0]);		
			fprintf(TreeFile,"< ");
			printAST_NODE(node->son[1]);		
			break;             
											
		case AST_MAIO:
			printAST_NODE(node->son[0]);		
			fprintf(TreeFile,"> ");
			printAST_NODE(node->son[1]);		
			break;             
											
		case AST_NEGA:
			printAST_NODE(node->son[0]);		
			fprintf(TreeFile,"! ");
			break;             
											
		case AST_DIVI:
			printAST_NODE(node->son[0]);		
			fprintf(TreeFile,"/ ");
			printAST_NODE(node->son[1]);		
			break;             
											
		case AST_LEQU:
			printAST_NODE(node->son[0]);		
			fprintf(TreeFile,"<= ");
			printAST_NODE(node->son[1]);		
			break;             
											
		case AST_GEQU:
			printAST_NODE(node->son[0]);		
			fprintf(TreeFile,">= ");
			printAST_NODE(node->son[1]);		
			break;             
											
		case AST_EQUA:
			printAST_NODE(node->son[0]);		
			fprintf(TreeFile,"== ");
			printAST_NODE(node->son[1]);		
			break;             
											
		case AST_NEQU:
			printAST_NODE(node->son[0]);		
			fprintf(TreeFile,"!= ");
			printAST_NODE(node->son[1]);		
			break;             
											
		case AST_AND:
			printAST_NODE(node->son[0]);		
			fprintf(TreeFile,"&& ");
			printAST_NODE(node->son[1]);		
			break;             
											
		case AST_OR:
			printAST_NODE(node->son[0]);		
			fprintf(TreeFile,"|| ");
			printAST_NODE(node->son[1]);		
			break;    
		
		
		
		default: fprintf(stderr, "UNKNOWN\n");				
	}
	for (int i=0; i<MAX_SONS; i++)
		astPrint(node-son[i], level+1);	
}