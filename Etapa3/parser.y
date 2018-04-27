%{
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    //#include "hash.h"
	//#include "main.c"
    void yyerror(char *msg);
%}

%union{
	AST* ast;
	HASH * symbol;
}

%type<ast> program
%type<ast> declist
%type<ast> dec
%type<ast> FUNCT
%type<ast> LISTPARAM
%type<ast> RESTPARAM
%type<ast> PARAM
%type<ast> BODY
%type<ast> BLCCOMAND
%type<ast> RESTCOMAND
%type<ast> COMAND
%type<ast> LISTPRINT
%type<ast> RESTELEMENT
%type<ast> ELEMENT
%type<ast> CONTROLFL
%type<ast> EXPRES
%type<ast> LSTARG
%type<ast> RESTARG
%type<ast> DECL
%type<ast> TYPE
%type<ast> INILIT
%type<ast> RESTINILIT
%type<ast> VARREAL
%type<ast> LITERALINTEGER
%type<ast> CARAC


 

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
		 
CONTROLFL: KW_IF '('EXPRES')' KW_THEN COMAND %prec IFELSE			{$$ = astCreate(AST_IF,0,$3,$6,0,0);} 
		|KW_IF '('EXPRES')' KW_THEN COMAND KW_ELSE COMAND 			{$$ = astCreate(AST_IFE,0,$3,$6,$8,0);}
		|KW_WHILE '('EXPRES')' COMAND				                {$$ = astCreate(AST_WHI,0,$3,$5,0,0);}
		|KW_FOR '('TK_IDENTIFIER '=' EXPRES KW_TO EXPRES')' COMAND  {$$ = astCreate(AST_FOR,0,$3,$5,$7,$9);}
		;		

/*==============Expressões Aritméticas e Lógicas Tipo 2 Resolve os últimos reduce/reduce===============*/	
EXPRES:  '(' EXPRES ')'  /* Isso é suficiente para garantir "As expressões aritméticas podem ser formadas recursivamente com operadores aritméticos, assim como permitem o uso de parênteses para associatividade"?*/ 

		|TK_IDENTIFIER	
		|TK_IDENTIFIER '[' EXPRES ']'	{$$ = astCreate(AST_VEC,$1,$3,0,0,0);}
		|TK_IDENTIFIER '(' LSTARG ')'	{$$ = astCreate(AST_FUN,$1,$3,0,0,0);}
		|LITERALINTEGER					{$$ = astCreate(AST_SYMBOL,$1,0,0,0,0);} /*existe distinção entre literal real, inteiro, char e string???*/
		|CARAC	                        {$$ = astCreate(AST_SYMBOL,$1,0,0,0,0);}
		|VARREAL	                    {$$ = astCreate(AST_SYMBOL,$1,0,0,0,0);}
		|EXPRES'*' EXPRES	            {$$ = astCreate(AST_MUL,0,$1,$3,0,0);}
		|EXPRES '+' EXPRES	            {$$ = astCreate(AST_ADD,0,$1,$3,0,0);}
		|EXPRES '-' EXPRES	            {$$ = astCreate(AST_SUB,0,$1,$3,0,0);}
		|EXPRES '/' EXPRES	            {$$ = astCreate(AST_DIV,0,$1,$3,0,0);}
		| EXPRES '<' EXPRES	            {$$ = astCreate(AST_LES,0,$1,$3,0,0);}
		| EXPRES '>' EXPRES	            {$$ = astCreate(AST_GRE,0,$1,$3,0,0);}
		| '!' EXPRES	                {$$ = astCreate(AST_NOT,0,$3,0,0,0);}
		| EXPRES OPERATOR_LE EXPRES	    {$$ = astCreate(AST_LEQ,0,$1,$3,0,0);}
		| EXPRES OPERATOR_GE EXPRES	    {$$ = astCreate(AST_GEQ,0,$1,$3,0,0);}
		| EXPRES OPERATOR_EQ EXPRES	    {$$ = astCreate(AST_EQU,0,$1,$3,0,0);}
		| EXPRES OPERATOR_NE EXPRES	    {$$ = astCreate(AST_NEQ,0,$1,$3,0,0);}
		| EXPRES OPERATOR_AND EXPRES    {$$ = astCreate(AST_AND,0,$1,$3,0,0);}
		| EXPRES OPERATOR_OR EXPRES		{$$ = astCreate(AST_OR,0,$1,$3,0,0);}	
		|'#'TK_IDENTIFIER	            {$$ = astCreate(AST_POI,0,$2,0,0,0);}
		|'&'TK_IDENTIFIER	            {$$ = astCreate(AST_ADD,0,$2,0,0,0);}
		;
		
LSTARG: EXPRES RESTARG	{$$ = astCreate(AST_LARG,0,$1,$2,0,0);}
		;		
		
RESTARG: ',' EXPRES RESTARG {$$ = astCreate(AST_RARG,0,$1,$2,0,0);}
	 |;

/*=============================================================*/
/*==============Declarações de variáveis globais===============*/		   
/*=============================================================*/

DECL: TYPE TK_IDENTIFIER '=' INILIT';'							{$$ = astCreate(AST_DEC,$2,$1,$4,0,0);}	  
	  |TYPE TK_IDENTIFIER'['LITERALINTEGER']'';'	            {$$ = astCreate(AST_DEC,$2,$1,$4,0,0);}
	  |TYPE TK_IDENTIFIER'['LITERALINTEGER']'':' RESTINILIT';'	{$$ = astCreate(AST_DEC,$2,$1,$4,$7,0);}
	  |TYPE '#'TK_IDENTIFIER '=' INILIT';'	                    {$$ = astCreate(AST_DEC,$3,$1,$2,$5,0);} /*???*/
	  ;
	  
TYPE: KW_CHAR	 {$$ = astCreate(AST_TYP,$1,0,0,0,0);}
      |KW_FLOAT	 {$$ = astCreate(AST_TYP,$1,0,0,0,0);}
	  |KW_INT	 {$$ = astCreate(AST_TYP,$1,0,0,0,0);}
	  ;          
	  
INILIT: CARAC	         {$$ = astCreate(AST_SYMBOL,$1,0,0,0,0);}
		|LITERALINTEGER	 {$$ = astCreate(AST_SYMBOL,$1,0,0,0,0);}
		|VARREAL	     {$$ = astCreate(AST_SYMBOL,$1,0,0,0,0);}
		;

RESTINILIT: INILIT RESTINILIT	{$$ = astCreate(AST_LINILIT,0,$1,$2,0,0);}
			|	
			;
			

/*=============================================================*/
/*========================DEBUG AREA===========================*/		   
/*=============================================================*/


/*Precisamos dessa parte?  R: Não, mas eu coloquei isso pra resolver alguns reduces na etapa anterior, se conseguir tirar sem dar reduce seria bom, reduziria a complexidade da árvore.*/
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
