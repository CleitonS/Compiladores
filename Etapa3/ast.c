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
											
		case AST_IFE:
			fprintf(TreeToFile,"if ( ");
			printAST_NODE(node->son[0]);				
			fprintf(TreeToFile,") then\n");
			printAST_NODE(node->son[1]);				
			fprintf(TreeToFile,"else \n");
			printAST_NODE(node->son[2]);				
			break;                      
											
		case AST_WHI:
			fprintf(TreeToFile,"while ( ");
			printAST_NODE(node->son[0]);				
			fprintf(TreeToFile,") \n");
			printAST_NODE(node->son[1]);				
			break; 
		
		
		case AST_ADD:
			printAST_NODE(node->son[0]);		
			fprintf(TreeFile,"+ ");
			printAST_NODE(node->son[1]);		
			break;             
											
		case AST_SUB:
			printAST_NODE(node->son[0]);		
			fprintf(TreeFile,"- ");
			printAST_NODE(node->son[1]);		
			break;             
											
		case AST_MUL:
			printAST_NODE(node->son[0]);		
			fprintf(TreeFile,"* ");
			printAST_NODE(node->son[1]);		
			break;                         
											
		case AST_LES:
			printAST_NODE(node->son[0]);		
			fprintf(TreeFile,"< ");
			printAST_NODE(node->son[1]);		
			break;             
											
		case AST_GRE:
			printAST_NODE(node->son[0]);		
			fprintf(TreeFile,"> ");
			printAST_NODE(node->son[1]);		
			break;             
											
		case AST_NOT:
			printAST_NODE(node->son[0]);		
			fprintf(TreeFile,"! ");
			break;             
											
		case AST_DIV:
			printAST_NODE(node->son[0]);		
			fprintf(TreeFile,"/ ");
			printAST_NODE(node->son[1]);		
			break;             
											
		case AST_LEQ:
			printAST_NODE(node->son[0]);		
			fprintf(TreeFile,"<= ");
			printAST_NODE(node->son[1]);		
			break;             
											
		case AST_GEQ:
			printAST_NODE(node->son[0]);		
			fprintf(TreeFile,">= ");
			printAST_NODE(node->son[1]);		
			break;             
											
		case AST_EQU:
			printAST_NODE(node->son[0]);		
			fprintf(TreeFile,"== ");
			printAST_NODE(node->son[1]);		
			break;             
											
		case AST_NEQ:
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
			
		case AST_POI:
			fprintf(TreeFile,"#");
			printAST_NODE(node->son[0]);			
			break;			
		
		case AST_ADR:
			fprintf(TreeFile,"&");
			printAST_NODE(node->son[0]);		
			break;	
		
		case AST_VEC:
			fprintf(TreeToFile,"%s",node->symbol->text);
			fprintf(TreeFile,"[");
			printAST_NODE(node->son[0]);
			fprintf(TreeFile,"]");		
			break;
		
		case AST_FUN:
			fprintf(TreeToFile,"%s",node->symbol->text);
			fprintf(TreeFile,"(");
			printAST_NODE(node->son[0]);
			fprintf(TreeFile,")");			
			break;
		
		case AST_FOR:
			fprintf(TreeFile,"FOR (");
			fprintf(TreeToFile,"%s",node->symbol->text);
			fprintf(TreeFile," = ");
			printAST_NODE(node->son[0]);
			fprintf(TreeFile," TO ");
			printAST_NODE(node->son[1]);			
			fprintf(TreeFile,") ");
			printAST_NODE(node->son[2]);
			fprintf(TreeFile,"\n");		
			break;
		
		case AST_LINILIT:
			printAST_NODE(node->son[0]);
			fprintf(TreeFile," ");
			printAST_NODE(node->son[1]);
			break;
		
		case AST_REST:
			fprintf(TreeFile,", ");
			printAST_NODE(node->son[0]);
			printAST_NODE(node->son[1]);
			break;
		
		case AST_SYMBOLPAR:
			fprintf(TreeFile,"( ");
			fprintf(TreeToFile,"%s",node->symbol->text);		
			fprintf(TreeFile," )");
			break;
		
		case AST_LIST:
			printAST_NODE(node->son[0]);
			fprintf(TreeFile," ");
			printAST_NODE(node->son[1]);		
			break;
		
		case AST_ATR:
			fprintf(TreeToFile,"%s",node->symbol->text);
			fprintf(TreeFile," = ");
			printAST_NODE(node->son[0]);
			break;
		
		case AST_ATRVEC:
			fprintf(TreeToFile,"%s",node->symbol->text);
			fprintf(TreeFile," [ ");
			printAST_NODE(node->son[0]);			
			fprintf(TreeFile," ] ");
			fprintf(TreeFile," = ");
			printAST_NODE(node->son[0]);			
			break;
		
		case AST_PRI:
			fprintf(TreeFile," PRINT ");
			printAST_NODE(node->son[0]);
			break;
		
		case AST_FUND:
			printAST_NODE(node->son[0]);
			fprintf(TreeFile," ");
			fprintf(TreeToFile,"%s",node->symbol->text);
			fprintf(TreeFile," ( ");
			printAST_NODE(node->son[1]);
			fprintf(TreeFile," ) ");
			printAST_NODE(node->son[2]);
			break;
		
		case AST_PARAM:
			printAST_NODE(node->son[0]);
			fprintf(TreeFile," ");
			fprintf(TreeToFile,"%s",node->symbol->text);		
			break;
		
		case AST_BLCOM:
			fprintf(TreeFile,"{ ");
			printAST_NODE(node->son[0]);
			fprintf(TreeFile," {");
			break;
		
		case AST_LISTLINE:
			printAST_NODE(node->son[0]);
			fprintf(TreeFile," ");
			printAST_NODE(node->son[1]);	
			break;
		
		case AST_RESTLINE:
			fprintf(TreeFile,"; ");
			printAST_NODE(node->son[0]);
			fprintf(TreeFile," ");
			printAST_NODE(node->son[1]);			
			break;
		
		case AST_COMPARE:
			fprintf(TreeToFile,"%s",node->symbol->text);
			fprintf(TreeFile," ");
			fprintf(TreeFile," == ");
			printAST_NODE(node->son[0]);
			break;
		
		case AST_DECINIT:
			fprintf(TreeToFile,"%s",node->symbol->text);
			fprintf(TreeFile," = ");
			printAST_NODE(node->son[0]);
			fprintf(TreeFile,";\n");
			break;
		
		case AST_DECVEC:
			printAST_NODE(node->son[0]);
			fprintf(TreeFile," ");
			fprintf(TreeToFile,"%s",node->symbol->text);
			fprintf(TreeFile," [ ");
			printAST_NODE(node->son[1]);	
			fprintf(TreeFile," ];\n ");						
			break;
		
		case AST_DECVECLI:
			printAST_NODE(node->son[0]);
			fprintf(TreeFile," ");
			fprintf(TreeToFile,"%s",node->symbol->text);
			fprintf(TreeFile," [ ");
			printAST_NODE(node->son[1]);	
			fprintf(TreeFile," ] : ");
			printAST_NODE(node->son[2]);
			fprintf(TreeFile,";\n");
			break;
		
		case AST_DECPOIT:
			printAST_NODE(node->son[0]);
			fprintf(TreeFile," #");
			fprintf(TreeToFile,"%s",node->symbol->text);
			fprintf(TreeFile," = ");
			printAST_NODE(node->son[1]);	
			break;
			
		case AST_READ:
			fprintf(TreeFile,"READ ");
			printAST_NODE(node->son[0]);	
			break;			


			
		default: fprintf(stderr, "UNKNOWN\n");				
	}
	for (int i=0; i<MAX_SONS; i++)
		astPrint(node-son[i], level+1);	
}