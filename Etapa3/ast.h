#ifndef _AST_
#define _AST_

#include "hash.h"
#define MAX_SONS 4

#define AST_SYMBOL    1  
#define AST_IF        2  	
#define AST_IFE       3  
#define AST_WHI       4  
#define AST_ADD       5  
#define AST_SUB       7  
#define AST_MUL       8  
#define AST_LES       9  
#define AST_GRE       10 
#define AST_NOT       11  
#define AST_DIV       12  
#define AST_LEQ       13  
#define AST_GEQ       14  
#define AST_EQU       15       /*==*/
#define AST_NEQ       16      
#define AST_AND       17      
#define AST_OR        18                                  
#define AST_POI       19      
#define AST_ADR       20      
#define AST_VEC       21      
#define AST_FUN	      22       /*CHAMADA DE FUNCAO*/
#define AST_FOR       23 
#define AST_LINILIT   24
#define AST_REST	  25      /*SEPARADOR ',' */
#define AST_SYMBOLPAR 26	      /*(SIMBOL)*/
#define AST_LIST      27      /*SEM SEPARADOR*/
#define AST_ATR       28	      /*=*/
#define AST_ATRVEC	  29	      
#define AST_PRI       30      
#define AST_FUND      31	      /*DECLARACAO DE FUNCAO*/
#define AST_PARAM     32      
#define AST_BLCOM     33      
#define AST_LISTLINE  34      /*SEPRADO É \N*/
#define AST_RESTLINE  35      /*SEPRADOR ';' */
#define AST_COMPARE   36      /*COMPARAÇÃO X == Y*/                     
#define AST_DECINIT   37
#define AST_DECVEC	  38
#define AST_DECVECLI  39
#define AST_DECPOIT	  40
#define AST_READ	  41






typedef struct ast_node{
	int type;
	HASH *symbol
	struct ast_node *son[MAX_SONS];
} AST;

AST *astCreate(int type, HASH* symbol, AST *son0, AST *son1, AST *son2, AST *son3);

void astPrint(AST *node, int level);

FILE *TreeFile;

#endif