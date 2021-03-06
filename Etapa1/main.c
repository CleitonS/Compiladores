extern int Running;
extern FILE * yyin;
extern char * yytext;
extern int isRunning(void);
extern int getLineNumber();
extern int yylex();
extern void hashprint();

int main(int argc, char *argv[])
{	
	int test;
	yyin = fopen(argv[1], "r"); 
	if (yyin == NULL)
	{
		printf("Erro ao abrir o arquivo!\n");
		return TOKEN_ERROR;	
	}
	while(isRunning())
	{	
		test = yylex();
		if (isRunning())
			printf("linha: %d token %d\n",getLineNumber(), test);
	}
	hashprint();

	return 0;
}