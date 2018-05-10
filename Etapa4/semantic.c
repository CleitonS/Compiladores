
#include "semantic.h"

void set_declarations(AST *node){
	if (!node) return;
	if (node->type == AST_DECINIT  ||
		node->type == AST_DECVEC   ||
		node->type == AST_DECVECLI ||
		node->type == AST_DECPOIT  ||
		node->type == AST_FUND)
	{
		if (node->symbol->type != SYMBOL_TYPE_ID)
			fprintf(stderr, "Semantic error: Symbol '%s' already declared.\n", node->symbol->yytext);		
		else{
			switch(node->type){
				case AST_DECINIT:
					node->symbol->type = SYMBOL_TYPE_ESCALAR;
				break;
				
				case AST_DECVEC:
					node->symbol->type = SYMBOL_TYPE_VECTOR;
				break;

				case AST_DECVECLI:
					node->symbol->type = SYMBOL_TYPE_VECTOR;
				break;

				case AST_DECPOIT:
					node->symbol->type = SYMBOL_TYPE_POINTER;
				break;	
				
				case AST_FUND:
					node->symbol->type = SYMBOL_TYPE_FUNCTION;
				break;					
			}
		}				
	}	
	for (int i=0; i<MAX_SONS; i++)
		set_declarations(node->son[i]);	
}