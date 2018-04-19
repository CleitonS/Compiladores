#ifndef _AST_
define _AST_

#include "hash.h"
#define MAX_SONS 4

define AST_SYMBOL  1
define AST_ADD     2
define AST_SUB     3
define AST_MUL     4
define AST_ADD     5
define AST_SUB     6 
define AST_DIV     7
define AST_LES     8 
define AST_GRE     9 
define AST_NOT     10
define AST_LEQ     11
define AST_GEQ     12
define AST_EQU     13
define AST_NEQ     14
define AST_AND     15
define AST_OR      16
define AST_POI     17
define AST_ADD     18
define AST_VEC     19 
define AST_FUN	   20	
define AST_IF      21
define AST_IFE     22
define AST_WHI     23 
define AST_FOR     24
define AST_DEC 	   25
define AST_TYP	   26
define AST_LINILIT 27
define AST_LARG	   28	
define AST_RARG	   29 	

	

typedef struct ast_node{
	int type;
	HASH *symbol
	struct ast_node *son[MAX_SONS];
} AST;

AST *astCreate(int type, HASH* symbol, AST *son0, AST *son1, AST *son2, AST *son3);

void astPrint(AST *node, int level);

#endif