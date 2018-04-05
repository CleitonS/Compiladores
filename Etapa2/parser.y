%{



%}

%token KW_CHAR      
%token KW_INT       
%token KW_FLOAT     
%token KW_IF        
%token KW_THEN      
%token KW_ELSE      
%token KW_WHILE     
%token KW_FOR       
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




%%

program: BLCDECL
	     |FUNCT;
		 
		 
FUNCT: TYPE TK_IDENTIFIER'('LISTPARAM')' BODY;
	   	   
LISTPARAM: PARAM RESTPARAM
           |
		   ;

RESTPARAM: ',' PARAM RESTPARAM
			|
			;

PARAM: TYPE TK_IDENTIFIER;

BODY: '{' BLCCOMAND '}';

BLCCOMAND: COMAND RESTCOMAND
		   |
		   ;

RESTCOMAND: ';' COMAND RESTCOMAND
			|
			;
			
COMAND: TK_IDENTIFIER '=' EXPRES
		|TK_IDENTIFIER '[' EXPRES ']' '=' EXPRES
		|CONTROLFL
		|'read' TK_IDENTIFIER /*variável escalar ???*/
		|'print' LISTPRINT
		|'return' EXPRES
		|
		;
		
LISTPRINT: ELEMENT RESTELEMENT;

RESTELEMENT: ' ' ELEMENT RESTELEMENT
			|
			;
			
ELEMENT: LIT_STRING
		 | EXPRESARIT;

EXPRESS: EXPRESARIT
		 |EXPRESLOG;

/*STOP HERE*/
		 
EXPRESARIT: 		 



		   

BLCDECL: DECL RESTDECL;

RESTDECL: DECL RESTDECL
		  |
		  ;
		
DECL: TYPE TK_IDENTIFIER '=' INILIT';'
	  |TYPE TK_IDENTIFIER'['LIT_INTEGER']'';'
	  |TYPE TK_IDENTIFIER'['LIT_INTEGER']:' BLCINILIT';'
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

BLCINILIT: INILIT RESTINILIT
		   ;

RESTINILIT: INILIT RESTINILIT
			|
			;
	  
%%
