
#include "semantic.h"

int num_pointers;

void set_declarations(AST *node){
	if (!node) return;
	if (node->type == AST_DECINIT  ||
		node->type == AST_DECVEC   ||
		node->type == AST_DECVECLI ||
		node->type == AST_DECPOIT  ||
		node->type == AST_FUND)
	{
		if (node->symbol->type != SYMBOL_TYPE_ID)
			fprintf(stderr, "Semantic error: Symbol '%s' already declared. Line %d \n", node->symbol->yytext, node->lineNumber);		
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

void check_undeclarations(AST *node){
	if(!node) return;
	for (int i=0; i<MAX_SONS; i++)
		check_undeclarations(node->son[i]);
	
	if(node->type == AST_SYMBOL && 
	   node->symbol->type == SYMBOL_TYPE_ID){
	   fprintf(stderr, "Semantic error: Symbol '%s' not declared. Line %d \n", node->symbol->yytext, node->lineNumber);		
	}	
}

void check_operands(AST *node){
	int i;
	if(!node) return;
	for (int i=0; i<MAX_SONS; i++)
		check_operands(node->son[i]);	
	if(node->type == AST_ADD || 
	   node->type == AST_SUB){
		if(!node->son[0] || !node->son[1]) 
			fprintf(stderr, "Operator error: undefined operator in line %d \n", node->lineNumber );		
		
		num_pointers = 0;
		if(check_number_pointer(node) > 1 )
			fprintf(stderr, "Operator error: multiple sums with pointer in line %d \n", node->lineNumber );					
	}	
	if(node->type == AST_MUL || 
	   node->type == AST_DIV){
		if(!node->son[0] || !node->son[1]) 
			fprintf(stderr, "Operator error: undefined operator in line %d \n", node->lineNumber );				   
		   
		num_pointers = 0;
		if(check_number_pointer(node) > 0 )
			fprintf(stderr, "Operator error: operation invalid with pointer in line %d \n", node->lineNumber );					
			
	}
}

int check_number_pointer(AST *node){
	if(!node) return;
	if (node->type == AST_POI)
		num_pointers++;
	for (int i=0; i<MAX_SONS; i++)
		check_number_pointer(node->son[i]);		
	
	return num_pointers;	
}







