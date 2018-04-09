%{
#include "hash.c"
#include "parser.tab.h"
#include <stdio.h>

	int countLine = 1;
	int running = 1;
	int isRunning(void);
	int yylex(void);
	int getLineNumber();
%}

%x COMMENT

%%

char				{return KW_CHAR;}
int					{return KW_INT;}
float				{return KW_FLOAT;}
if					{return KW_IF;}
then				{return KW_THEN;}
else				{return KW_ELSE;}
while				{return KW_WHILE;}
for					{return KW_FOR;}
to					{return KW_TO;}
read				{return KW_READ;}
return				{return KW_RETURN;}
print				{return KW_PRINT;}
[a-zA-Z_]+[0-9a-zA-Z_]*		{hashinsert(SYMBOL_TYPE_ID,yytext);return TK_IDENTIFIER;}
"<="				{return OPERATOR_LE;}    
">="				{return OPERATOR_GE;}  
"=="				{return OPERATOR_EQ;}  
"!="				{return OPERATOR_NE;} 
"&&"				{return OPERATOR_AND;}   
"||"				{return OPERATOR_OR;}  

"//".*				{}
"/*"				{BEGIN(COMMENT);}
[0-9]+				{hashinsert(SYMBOL_TYPE_LIT_INT,yytext);return LIT_INTEGER;}
[0-9]+[.][0-9]+		{hashinsert(SYMBOL_TYPE_LIT_FLOAT,yytext);return LIT_REAL;}
'.'					{hashinsert(SYMBOL_TYPE_LIT_CHAR,yytext);return LIT_CHAR;}	
\"[.^\ ]*\"				{hashinsert(SYMBOL_TYPE_LIT_STRING,yytext);return LIT_STRING;}

[\,\;\:\(\)\[\]\{\}\+\-\*\/\<\>\=\!\&\$\#]		{return yytext[0];}
[\n]				{countLine++;}	
[ \t]
.					{return TOKEN_ERROR;}

<COMMENT>"*/"		{BEGIN(INITIAL);}
<COMMENT>[\n]		{countLine++;}
<COMMENT>.*			{}

%%
int getLineNumber(void)
{
	return countLine;
}

int isRunning(void)
{
	return running;
}

void initMe(void)
{
	hashinit();
}



int yywrap(void) 
{		
	running = 0;	
	return 1;
} 
