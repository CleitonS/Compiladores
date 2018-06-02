#ifndef _semantich_
#define _semantich_
void set_declarations(AST *node);
void check_operands(AST *node);
void check_undeclarations(AST *node);
int check_number_pointer(AST *node);
#endif