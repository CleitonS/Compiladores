#ifndef _semantich_
#define _semantich_
#include "ast.h"
#include "y.tab.h"
#include "hash.h"
void set_declarations(AST *node);
void check_operands(AST *node);
void check_undeclarations(AST *node);
int check_number_pointer(AST *node);
#endif