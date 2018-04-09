%{
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    //#include "hash.h"
	//#include "main.c"
    void yyerror(char *msg);
%}

%token KW_CHAR      
%token KW_INT       
%token KW_FLOAT     
%token KW_IF        
%token KW_THEN      
%token KW_ELSE      
%token KW_WHILE     
%token KW_FOR
%token KW_TO       
%token KW_READ      
%token KW_RETURN    
%token KW_PRINT     

%token OPERATOR_LE  
%token OPERATOR_GE  
%token OPERATOR_EQ  
%token OPERATOR_NE  
%token OPERATOR_AND 
%token OPERATOR_OR  

%token TK_IDENTIFIER
%token LIT_INTEGER  
%token LIT_REAL     
%token LIT_CHAR     
%token LIT_STRING   
%token TOKEN_ERROR

/*Prioridade de operações, resolve alguns reduce*/	

%left OPERATOR_AND OPERATOR_OR
%left OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_NE
%left '<' '>' '!'
%left '-' '+'
%left '*' '/'  

%nonassoc IFELSE
%nonassoc KW_ELSE


%%
program: declist {printf("program->declist\n");}
	;
	
declist: dec declist	{printf("declist->dec declist\n");}
	|
	;

dec: DECL	{printf("-----------------dec->DECL-----------------------------------\n");}
	|FUNCT {printf("------------------dec->FUNCT----------------------------------\n");}
	;

/*=============================================================*/
/*====================Definição de funções=====================*/		   
/*=============================================================*/		 
FUNCT: TYPE TK_IDENTIFIER'('LISTPARAM')' BODY {printf("FUNCT->TYPE TK_IDENTIFIER'('LISTPARAM')' BODY\n");}
		;
	   	   
LISTPARAM: PARAM RESTPARAM {printf("LISTPARAM-> PARAM RESTPARAM\n");}
		|{printf("LISTPARAM-> vazio\n");}
		;

RESTPARAM: ',' PARAM RESTPARAM	{printf("RESTPARAM-> ',' PARAM RESTPARAM\n");}
		|	{printf("RESTPARAM-> vazio\n");}
		;

PARAM: TYPE TK_IDENTIFIER	{printf("PARAM-> TYPE TK_IDENTIFIER\n");}
		;


/*==============Bloco de comandos===============*/		   

BODY: '{' BLCCOMAND '}' {printf("BODY-> '{' BLCCOMAND '}'");}
		;

BLCCOMAND: COMAND RESTCOMAND {printf("BLCCOMAND: COMAND RESTCOMAND\n");}
		|	{printf("BLCCOMAND: vazio\n");}
		;

RESTCOMAND: ';' COMAND RESTCOMAND	{printf("RESTCOMAND: ';' COMAND RESTCOMAND\n");}
		|	{printf("RESTCOMAND: vazio\n");}
		;

/*==============Comandos Simples===============*/	
			
COMAND: TK_IDENTIFIER '=' EXPRES {printf("\tCOMAND->TK_ID '=' EXPRES->\n");}
		|TK_IDENTIFIER '[' EXPRES ']' '=' EXPRES {printf("\tCOMAND->TK_ID '[' EXPRES ']' '=' EXPRES->\n");}
		|CONTROLFL {printf("\tCOMAND: CONTROLFL\n");}
		|KW_READ TK_IDENTIFIER {printf("\tCOMAND: KW_READ TK_IDENTIFIER\n");}/*variável escalar =  int, float, string, boolean*/
		|KW_PRINT LISTPRINT	{printf("\tCOMAND: KW_PRINT LISTPRINT\n");}
		|KW_RETURN EXPRES	{printf("\tCOMAND: KW_RETURN EXPRES\n");}
		;
	
LISTPRINT: ELEMENT RESTELEMENT	{printf("LISTPRINT: ELEMENT RESTELEMENT\n");}
		;

RESTELEMENT: ELEMENT RESTELEMENT	{printf("RESTELEMENT: ELEMENT RESTELEMENT\n");}
			|	{printf("RESTELEMENT: vazio\n");}
			;
			
ELEMENT: LIT_STRING	{printf("ELEMENT: LIT_STRING\n");}
		 | EXPRES 	{printf("ELEMENT: EXPRES\n");}
		 ;

/*==============Controle de fluxo===============*/	
		 
CONTROLFL: KW_IF '('EXPRES')' KW_THEN COMAND %prec IFELSE			{printf("CONTROLFL: KW_IF '('EXPRES')' KW_THEN COMAND %prec IFELSE\n");}
		|KW_IF '('EXPRES')' KW_THEN COMAND KW_ELSE COMAND			{printf("CONTROLFL: KW_IF '('EXPRES')' KW_THEN COMAND KW_ELSE COMAND\n");}
		|KW_WHILE '('EXPRES')' BODY									{printf("CONTROLFL: KW_WHILE '('EXPRES')' BODY\n");}
		|KW_FOR '('TK_IDENTIFIER '=' EXPRES KW_TO EXPRES')' COMAND	{printf("CONTROLFL: KW_FOR '('TK_IDENTIFIER '=' EXPRES KW_TO EXPRES')' COMAND\n");}
		;		

/*==============Expressões Aritméticas e Lógicas Tipo 2 Resolve os últimos reduce/reduce===============*/	
EXPRES:  '(' EXPRES: ')' {printf("EXPRES->'(' EXPRES: ')'\n");} /* Isso é suficiente para garantir "As expressões aritméticas podem ser formadas recursivamente com operadores aritméticos, assim como permitem o uso de parênteses para associatividade"?*/ 
		|TK_IDENTIFIER	{printf("EXPRES->TK_IDENTIFIER\n");}
		|TK_IDENTIFIER '[' EXPRES ']'	{printf("EXPRES->TK_IDENTIFIER '[' EXPRES ']'\n");}
		|LITERALINTEGER	{printf("EXPRES->LITERALINTEGER\n");}
		|CARAC	{printf("EXPRES->CARAC\n");}
		|VARREAL	{printf("EXPRES->ARREAL\n");}
		|EXPRES'*' EXPRES	{printf("EXPRES->EXPRES'*' EXPRES\n");}
		|EXPRES '+' EXPRES	{printf("EXPRES->EXPRES '+' EXPRES\n");}
		|EXPRES '-' EXPRES	{printf("EXPRES->EXPRES '-' EXPRES\n");}
		|EXPRES '/' EXPRES	{printf("EXPRES->EXPRES '/' EXPRES\n");}
		| EXPRES '<' EXPRES	{printf("EXPRES->EXPRES '<' EXPRES\n");}
		| EXPRES '>' EXPRES	{printf("EXPRES->EXPRES '>' EXPRES\n");}
		| '!' EXPRES	{printf("EXPRES->'!' EXPRES\n");}
		| EXPRES OPERATOR_LE EXPRES	{printf("EXPRES->EXPRES OPERATOR_LE EXPRES	\n");}
		| EXPRES OPERATOR_GE EXPRES	{printf("EXPRES->EXPRES OPERATOR_GE EXPRES	\n");}
		| EXPRES OPERATOR_EQ EXPRES	{printf("EXPRES->EXPRES OPERATOR_EQ EXPRES	\n");}
		| EXPRES OPERATOR_NE EXPRES	{printf("EXPRES->EXPRES OPERATOR_NE EXPRES	\n");}
		| EXPRES OPERATOR_AND EXPRES {printf("EXPRES->EXPRES OPERATOR_AND EXPRES\n");}
		| EXPRES OPERATOR_OR EXPRES	{printf("EXPRES->EXPRES OPERATOR_OR EXPRES\n");}
		| TK_IDENTIFIER '(' LSTARG ')'	{printf("EXPRES->TK_IDENTIFIER '(' LSTARG ')'\n");}
		|'#'TK_IDENTIFIER	{printf("EXPRES->'#'TK_IDENTIFIER\n");}
		|'&'TK_IDENTIFIER	{printf("EXPRES->'&'TK_IDENTIFIER\n");}
		;
		
LSTARG: EXPRES ARGTAIL	{printf("LSTARG: EXPRES ARGTAIL\n");}
		;		
		
ARGTAIL: ',' EXPRES ARGTAIL
		|
		;

/*=============================================================*/
/*==============Declarações de variáveis globais===============*/		   
/*=============================================================*/

DECL: TYPE TK_IDENTIFIER '=' INILIT';'	{printf("DECL: TYPE TK_IDENTIFIER '=' INILIT';'\n");}
	  |TYPE TK_IDENTIFIER'['LITERALINTEGER']'';'	{printf("DECL: TYPE TK_IDENTIFIER'['LITERALINTEGER']'';'\n");}
	  |TYPE TK_IDENTIFIER'['LITERALINTEGER']'':' RESTINILIT';'	{printf("DECL: TYPE TK_IDENTIFIER'['LITERALINTEGER']'':' RESTINILIT';'\n");}
	  |TYPE '#'TK_IDENTIFIER '=' INILIT';'	{printf("DECL: TYPE '#'TK_IDENTIFIER '=' INILIT';'\n");}
	  ;
	  
TYPE: KW_CHAR	{printf("TYPE: KW_CHAR\n");}
      |KW_FLOAT	{printf("TYPE: KW_FLOAT\n");}
	  |KW_INT	{printf("TYPE: KW_INT\n");}
	  ;
	  
INILIT: CARAC	{printf("INILIT: CARAC\n");}
		|LITERALINTEGER	{printf("INILIT: LITERALINTEGER\n");}
		|VARREAL	{printf("INILIT: VARREAL\n");}
		;

RESTINILIT: INILIT RESTINILIT	{printf("RESTINILIT:: VARREAL\n");}
			|	{printf("RESTINILIT: Vazio\n");}
			;
			

/*=============================================================*/
/*========================DEBUG AREA===========================*/		   
/*=============================================================*/

VARREAL: LIT_REAL	
		;

LITERALINTEGER: LIT_INTEGER	
		;
		
CARAC: LIT_CHAR	
		;	
	  
%%
void yyerror(char *msg)
{
    int lineNum = getLineNumber();
    fprintf(stderr, "ERRO!\n%s na linha: %i\n", msg, lineNum);
    
    exit(3);
}
