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
/*%left '{' '[' '('*/
%left OPERATOR_AND OPERATOR_OR
%left OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_NE
%left '<' '>' '!'
%left '-' '+'
%left '*' '/'  

%nonassoc IDENTF
%nonassoc IFELSE
%nonassoc KW_ELSE


%%
program: declist 
	;
	
declist: dec declist	
	|
	;

dec: DECL	
	|FUNCT 
	;

/*=============================================================*/
/*====================Definição de funções=====================*/		   
/*=============================================================*/		 
FUNCT: TYPE TK_IDENTIFIER'('LISTPARAM')' BODY 
		;
	   	   
LISTPARAM: PARAM RESTPARAM 
		|
		;

RESTPARAM: ',' PARAM RESTPARAM	
		|	
		;

PARAM: TYPE TK_IDENTIFIER	
		;


/*==============Bloco de comandos===============*/		   

BODY: '{' BLCCOMAND '}' 
		;

BLCCOMAND: COMAND RESTCOMAND 
		;

RESTCOMAND: ';' COMAND RESTCOMAND	
		|	
		;

/*==============Comandos Simples===============*/	
			
COMAND: TK_IDENTIFIER '=' EXPRES 
		|TK_IDENTIFIER '[' EXPRES ']' '=' EXPRES 
		|CONTROLFL 
		|KW_READ TK_IDENTIFIER /*variável escalar =  int, float, string, boolean*/
		|KW_PRINT LISTPRINT	
		|KW_RETURN EXPRES	
		|BODY
		|TK_IDENTIFIER OPERATOR_EQ EXPRES	
		|
		;
	
LISTPRINT: ELEMENT RESTELEMENT	
		;

RESTELEMENT: ELEMENT RESTELEMENT	
			|	
			;
			
ELEMENT: LIT_STRING	
		 | EXPRES 	
		 ;

/*==============Controle de fluxo===============*/	
		 
CONTROLFL: KW_IF '('EXPRES')' KW_THEN COMAND %prec IFELSE			
		|KW_IF '('EXPRES')' KW_THEN COMAND KW_ELSE COMAND 			
		|KW_WHILE '('EXPRES')' COMAND				
		|KW_FOR '('TK_IDENTIFIER '=' EXPRES KW_TO EXPRES')' COMAND
		;		

/*==============Expressões Aritméticas e Lógicas Tipo 2 Resolve os últimos reduce/reduce===============*/	
EXPRES:  '(' EXPRES ')'  /* Isso é suficiente para garantir "As expressões aritméticas podem ser formadas recursivamente com operadores aritméticos, assim como permitem o uso de parênteses para associatividade"?*/ 
		/*|TK_IDENTIFIER '[' BLIDENT		*/
		/*|TK_IDENTIFIER '(' BLIDENT*/
		|TK_IDENTIFIER	
		|TK_IDENTIFIER '[' EXPRES ']'	{printf("EXPRES->TK_IDENTIFIER '[' EXPRES ']'\n");}
		|TK_IDENTIFIER '(' LSTARG ')'	{printf("EXPRES->TK_IDENTIFIER '(' LSTARG ')'\n");}
		|LIT_INTEGER	
		|LIT_CHAR	
		|LIT_REAL	
		|EXPRES'*' EXPRES	
		|EXPRES '+' EXPRES	
		|EXPRES '-' EXPRES	
		|EXPRES '/' EXPRES	
		| EXPRES '<' EXPRES	
		| EXPRES '>' EXPRES	
		| '!' EXPRES	
		| EXPRES OPERATOR_LE EXPRES	
		| EXPRES OPERATOR_GE EXPRES	
		| EXPRES OPERATOR_EQ EXPRES	
		| EXPRES OPERATOR_NE EXPRES	
		| EXPRES OPERATOR_AND EXPRES 
		| EXPRES OPERATOR_OR EXPRES			
		|'#'TK_IDENTIFIER	
		|'&'TK_IDENTIFIER	
		;
/*
BLIDENT:  EXPRES ']'
        | LSTARG ')'
	;
		*/
LSTARG: EXPRES ARGTAIL	
		;		
		
ARGTAIL: ',' EXPRES ARGTAIL
	 |;

/*=============================================================*/
/*==============Declarações de variáveis globais===============*/		   
/*=============================================================*/

DECL: TYPE TK_IDENTIFIER '=' INILIT';'	
	  |TYPE TK_IDENTIFIER'['LIT_INTEGER']'';'	
	  |TYPE TK_IDENTIFIER'['LIT_INTEGER']'':' RESTINILIT';'	
	  |TYPE '#'TK_IDENTIFIER '=' INILIT';'	
	  ;
	  
TYPE: KW_CHAR	
      |KW_FLOAT	
	  |KW_INT	
	  ;
	  
INILIT: LIT_CHAR	
		|LIT_INTEGER	
		|LIT_REAL	
		;

RESTINILIT: INILIT RESTINILIT	
			|	
			;
			

/*=============================================================*/
/*========================DEBUG AREA===========================*/		   
/*=============================================================*/
/*
VARREAL: LIT_REAL	
		;

LITERALINTEGER: LIT_INTEGER	
		;
		
CARAC: LIT_CHAR	
		;*/	
	  
%%
void yyerror(char *msg)
{
    int lineNum = getLineNumber();
    fprintf(stderr, "ERRO!\n%s na linha: %i\n", msg, lineNum);
    
    exit(3);
}
