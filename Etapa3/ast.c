#ifndef __ASTC__
#define __ASTC__

#include <stdlib.h>
#include <stdio.h>
#include "ast.h"
extern AST *astCreate(int type, hash* symbol, AST *son0, AST *son1, AST *son2, AST *son3);
extern void printAST_NODE(AST *node);
extern FILE *TreeFile;
extern AST *root;

AST *astCreate(int type, hash* symbol, AST *son0, AST *son1, AST *son2, AST *son3){
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

void printAST_NODE(AST *node){
	printf("p0\n");
	if (!node) return;
	/*
	for (int i=0;1<level;i++)
		fprintf(stderr, "  ");
	fprintf(stderr, "AST(");
	*/
	printf("p1\n");
	switch(node->type)
	{
		case AST_SYMBOL:
			if(node->symbol)
				if(node->symbol->yytext)
					fprintf(TreeFile,"%s",node->symbol->yytext);	
			break; 
		
		case AST_IF:
			fprintf(TreeFile,"if ( ");
			printAST_NODE(node->son[0]);				
			fprintf(TreeFile,") then\n");
			printAST_NODE(node->son[1]);				
			break;             
											
		case AST_IFE:
			fprintf(TreeFile,"if ( ");
			printAST_NODE(node->son[0]);				
			fprintf(TreeFile,") then\n");
			printAST_NODE(node->son[1]);				
			fprintf(TreeFile,"else \n");
			printAST_NODE(node->son[2]);				
			break;                      
											
		case AST_WHI:
			fprintf(TreeFile,"while ( ");
			printAST_NODE(node->son[0]);				
			fprintf(TreeFile,") \n");
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
			fprintf(TreeFile,"#"); //possível problema aqui
			printAST_NODE(node->son[0]);		
			break;			
		
		case AST_ADR:
			fprintf(TreeFile,"&"); //possível problema aqui
			printAST_NODE(node->son[0]);
			break;	
		
		case AST_VEC:
			fprintf(TreeFile,"%s",node->symbol->yytext);
			fprintf(TreeFile,"[");
			printAST_NODE(node->son[0]);
			fprintf(TreeFile,"]");		
			break;
		
		case AST_FUN:
			fprintf(TreeFile,"%s",node->symbol->yytext);
			fprintf(TreeFile,"(");
			printAST_NODE(node->son[0]);
			fprintf(TreeFile,")");			
			break;
		
		case AST_FOR:
			fprintf(TreeFile,"FOR (");
			fprintf(TreeFile,"%s",node->symbol->yytext);
			fprintf(TreeFile," = ");
			printAST_NODE(node->son[0]);
			fprintf(TreeFile," TO ");
			printAST_NODE(node->son[1]);			
			fprintf(TreeFile,") ");
			printAST_NODE(node->son[2]); //Possível problema aqui 
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
			printAST_NODE(node->son[0]);		
			fprintf(TreeFile," )");
			break;
		
		case AST_LIST:
			printAST_NODE(node->son[0]);
			fprintf(TreeFile," ");
			printAST_NODE(node->son[1]);		
			break;
		
		case AST_ATR:
			fprintf(TreeFile,"%s",node->symbol->yytext);
			fprintf(TreeFile," = ");
			printAST_NODE(node->son[0]);
			fprintf(TreeFile,";\n");
			break;
		
		case AST_ATRVEC:
			fprintf(TreeFile,"%s",node->symbol->yytext);
			fprintf(TreeFile," [ ");
			printAST_NODE(node->son[0]);			
			fprintf(TreeFile," ] ");
			fprintf(TreeFile," = ");
			printAST_NODE(node->son[1]);	
			fprintf(TreeFile,";\n");			
			break;
		
		case AST_PRI:
			fprintf(TreeFile," PRINT ");
			printAST_NODE(node->son[0]);
			break;
		
		case AST_FUND:
			printAST_NODE(node->son[0]);
			//fprintf(TreeFile," "); Isso gera um espaço indevido antes main em "INT main ()"
			fprintf(TreeFile,"%s",node->symbol->yytext);
			fprintf(TreeFile," ( ");
			printAST_NODE(node->son[1]);
			fprintf(TreeFile," ) ");
			printAST_NODE(node->son[2]);
			break;
		
		case AST_PARAM:
			printAST_NODE(node->son[0]);
			fprintf(TreeFile," ");
			fprintf(TreeFile,"%s",node->symbol->yytext);		
			break;
		
		case AST_BLCOM:
			fprintf(TreeFile,"{ ");
			fprintf(TreeFile,"\n");
			printAST_NODE(node->son[0]);
			fprintf(TreeFile," }");
			fprintf(TreeFile,"\n");
			break;
		
		case AST_LISTLINE:
			printAST_NODE(node->son[0]);
			//fprintf(TreeFile," "); Isso gera um espaço antes das atribuições
			printAST_NODE(node->son[1]);	
			break;
		
		case AST_RESTLINE:
			//fprintf(TreeFile,"; "); Isso gera um ponto e vírgula indevido no começo das linhas dentro de uma função
			printAST_NODE(node->son[0]);
			fprintf(TreeFile," ");
			printAST_NODE(node->son[1]);			
			break;
		
		case AST_COMPARE:
			fprintf(TreeFile,"%s",node->symbol->yytext);
			fprintf(TreeFile," ");
			fprintf(TreeFile," == ");
			printAST_NODE(node->son[0]);
			break;
		
		case AST_DECINIT:
			printAST_NODE(node->son[0]);
			fprintf(TreeFile,"%s",node->symbol->yytext);
			fprintf(TreeFile," = ");
			printAST_NODE(node->son[1]);
			fprintf(TreeFile,";\n");						
			
			break;
		
		case AST_DECVEC:
			printAST_NODE(node->son[0]);
			fprintf(TreeFile,"%s",node->symbol->yytext);
			fprintf(TreeFile," [ ");
			printAST_NODE(node->son[1]);	
			fprintf(TreeFile," ];\n");						
			break;
		
		case AST_DECVECLI:
			printAST_NODE(node->son[0]);
			fprintf(TreeFile," ");
			fprintf(TreeFile,"%s",node->symbol->yytext);
			fprintf(TreeFile," [ ");
			printAST_NODE(node->son[1]);	
			fprintf(TreeFile," ] : ");
			printAST_NODE(node->son[2]);
			fprintf(TreeFile,";\n");
			break;
		
		case AST_DECPOIT:
			printAST_NODE(node->son[0]);
			fprintf(TreeFile,"#"); //possível problema aqui
			fprintf(TreeFile,"%s",node->symbol->yytext);
			fprintf(TreeFile," = ");
			printAST_NODE(node->son[1]);
			fprintf(TreeFile,";\n");			
			break;
			
		case AST_READ:
			fprintf(TreeFile,"READ ");
			printAST_NODE(node->son[0]);	
			break;	
			
		case AST_RET:
			fprintf(TreeFile,"RETURN ");
			printAST_NODE(node->son[0]);	
			break;
			
		case AST_KCHAR:
			fprintf(TreeFile,"CHAR ");
			break;
						
		case AST_KFLOAT:
			fprintf(TreeFile,"FLOAT ");
			break;
						
		case AST_KINT:
			fprintf(TreeFile,"INT ");
			break;

			
		default: fprintf(stderr, "UNKNOWN\n");				
	}
	/*
	for (int i=0; i<MAX_SONS; i++)
		printAST_NODE(node->son[i]);	*/
}

#endif