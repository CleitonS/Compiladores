#include <stdio.h>
#include <stdlib.h>
//extern int Running;
extern FILE * yyin;
//extern char * yytext;
//extern int isRunning(void);
//extern int getLineNumber();
//extern int yylex();
//extern void hashprint();
//extern FILE *TreeFile;
//int yyparse ();

#include "ast.h"
//#include "lex.yy.c"
#include "hash.h"
#include "y.tab.h"
#include "semantic.h"
#include "tac.h"

/*
extern AST *root;
extern void printAST_NODE(AST *node);
*/

int main(int argc, char *argv[])
{	

	int test;
	yyin = fopen(argv[1], "r"); 
	if (yyin == NULL)
	{
		printf("Erro ao abrir o arquivo Fonte!\n");
		exit(0);	
	}
	TreeFile = fopen(argv[2], "w+"); 
	if (TreeFile == NULL)
	{
		printf("Erro ao abrir o arquivo Destino!\n");
		exit(0);	
	}	
	
	
	/*
	while(isRunning())
	{	
		test = yylex();
		if (isRunning())
			printf("linha: %d token %d\n",getLineNumber(), test);
	}
	*/
	printf("Chamando parser\n");
	yyparse();
	printf("Imprimindo AST\n");
	/*printAST_NODE(root);*/
	/*hashprint();*/

	return 0;
}
