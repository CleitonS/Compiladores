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
		if (node->symbol->type != SYMBOL_TYPE_ID){
			fprintf(stderr, "Semantic error: Symbol '%s' already declared. Line %d \n", node->symbol->yytext, node->lineNumber);		
			exit(4);
		}
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
	

	if(node->symbol != 0 &&
	   node->symbol->type == SYMBOL_TYPE_ID){
	   fprintf(stderr, "Semantic error: Symbol '%s' not declared. Line %d \n", node->symbol->yytext, node->lineNumber);	
	   exit(-4);
	}	
}

int contArg;
void set_NumArg(AST *node){
	AST *nodeAux;

	if(!node) return;	
	if (node->type == AST_FUND){
		contArg = 0;
		nodeAux = node->son[1];
		while (nodeAux != 0){
			contArg++;
			if(nodeAux -> son[1] != 0)
				nodeAux = nodeAux -> son[1];
			else 
				nodeAux = 0;
		}
		node->symbol->NumArg = contArg;
	}

	for (int i=0; i<MAX_SONS; i++)
		set_NumArg(node->son[i]);		
}

void check_NumArg(AST *node){
	AST *nodeAux;

	if(!node) return;	
	if (node->type == AST_FUN){
		contArg = 0;
		nodeAux = node->son[0];
		while (nodeAux != 0){
			contArg++;
			if(nodeAux -> son[1] != 0)
				nodeAux = nodeAux -> son[1];
			else 
				nodeAux = 0;
		}		
		if(node->symbol->NumArg != contArg){
			fprintf(stderr, "Argument error: Number of arguments incorrect in line %d \n", node->lineNumber );		
			exit(4);
		}
			
	}
	for (int i=0; i<MAX_SONS; i++)
		check_NumArg(node->son[i]);		
}

void check_operands(AST *node){
	
	if(!node) return;
	for (int i=0; i<MAX_SONS; i++)
		check_operands(node->son[i]);	
	if(node->type == AST_ADD || node->type == AST_SUB){
		if(!node->son[0] || !node->son[1]) {
			fprintf(stderr, "Operator error: undefined operator in line %d \n", node->lineNumber );		
			exit(4);
		}
		
		num_pointers = 0;
		if(check_number_pointer(node) > 1 ){
			fprintf(stderr, "Operator error: multiple sums with pointer in line %d \n", node->lineNumber );					
			exit(4);
		}
	}	
	if(node->type == AST_MUL || node->type == AST_DIV){
		if(!node->son[0] || !node->son[1]){ 
			fprintf(stderr, "Operator error: undefined operator in line %d \n", node->lineNumber );				   
			exit(4);
		}
		num_pointers = 0;
		if(check_number_pointer(node) > 0 ){
			fprintf(stderr, "Operator error: operation invalid with pointer in line %d \n", node->lineNumber );					
			exit(4);
		}		
	}
	/*Verifica se todos os ponteiros tem indice -->  p[1]*/
	if (node->type == AST_VEC || node->type == AST_ATRVEC){						
		if(node->symbol == 0 || node->symbol->type != SYMBOL_TYPE_VECTOR){
			fprintf(stderr, "Operator error: pointer operation with not pointer in line %d \n", node->lineNumber );					
			exit(4);
		}			
	}
	
	/*Verifica se alguma variavel que não é ponteiro esta sendo acessado como tal*/
	if (node->type == AST_FOR || node->type == AST_ATR){						
		if(node->symbol == 0 || node->symbol->type != SYMBOL_TYPE_ESCALAR){
			fprintf(stderr, "Operator error: escalar operation with not escalar in line %d \n", node->lineNumber );					
			exit(4);
		}			
	}
	
	if (node-> type == AST_FUN){
		if(node->symbol == 0 || node->symbol->type != SYMBOL_TYPE_FUNCTION){
			fprintf(stderr, "Operator error: incorrect function call in line %d \n", node->lineNumber );					
			exit(4);
		}					
	}
	
	

	
	
	
	
	
}

int check_number_pointer(AST *node){
	if(!node) return 0;
	if (node->symbol != NULL &&
		node->symbol->type == SYMBOL_TYPE_POINTER)
		num_pointers++;
	for (int i=0; i<MAX_SONS; i++)
		check_number_pointer(node->son[i]);		
	
	return num_pointers;	
}







