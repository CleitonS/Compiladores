//#ifndef TAC_C
//#define TAC_C

#include "tac.h"


TAC* tacCreate(int type, hash* res, hash* op1, hash* op2)
{
	TAC* newtac = 0;
	newtac = (TAC*) calloc(1,sizeof(TAC));
	newtac->type = type;
	newtac->res = res;
	newtac->op1 = op1;
	newtac->op2 = op2;
	newtac->prev = 0;
	newtac->next = 0;	
	return newtac;	
}

void tacPrintSingle(TAC*tac)
{
	if (!tac) return ; //return 0 ??
	if (tac->type == TAC_SYMBOL) return ; //return 0 ??
	fprintf(stderr, "TAC(");
	switch (tac->type)
	{
		case TAC_SYMBOL: fprintf(stderr, "TAC_SYMBOL"); break;
		case TAC_ADD: fprintf(stderr, "TAC_ADD"); break;
		case TAC_SUB: fprintf(stderr, "TAC_SUB"); break;
		case TAC_MUL: fprintf(stderr, "TAC_MUL"); break;
		case TAC_DIV: fprintf(stderr, "TAC_DIV"); break;
		case TAC_LESS: fprintf(stderr, "TAC_LESS"); break;
		case TAC_GREATER: fprintf(stderr, "TAC_GREATER"); break;
		case TAC_ASS: fprintf(stderr, "TAC_ASS"); break;
		case TAC_IFZ: fprintf(stderr, "TAC_IFZ"); break;
		case TAC_LABEL: fprintf(stderr, "TAC_LABEL"); break;
		case TAC_JUMP: fprintf(stderr, "TAC_JUMP"); break;
		case TAC_EQUAL: fprintf(stderr, "TAC_EQUAL"); break;
		case TAC_IFNZ: fprintf(stderr, "TAC_IFNZ"); break;
		case TAC_LEQ: fprintf(stderr, "TAC_LEQ"); break;
		case TAC_GEQ: fprintf(stderr, "TAC_GEQ"); break;
		case TAC_EQU: fprintf(stderr, "TAC_EQU"); break;
		case TAC_NEQ: fprintf(stderr, "TAC_NEQ"); break;
		case TAC_AND: fprintf(stderr, "TAC_NEQ"); break;
		case TAC_OR: fprintf(stderr, "TAC_NEQ"); break;
		case TAC_WHI: fprintf(stderr, "TAC_WHI"); break;
		case TAC_RET: fprintf(stderr, "TAC_RET"); break;
		case TAC_NOT: fprintf(stderr, "TAC_NOT"); break;
		case TAC_PRI: fprintf(stderr, "TAC_PRI"); break;		
		case TAC_READ: fprintf(stderr, "TAC_READ"); break;				
		case TAC_ATRVEC: fprintf(stderr, "TAC_ATRVEC"); break;			
		case TAC_DECVECLI: fprintf(stderr, "TAC_DECVECLI"); break;	
		case TAC_INC: fprintf(stderr, "TAC_INC"); break;
		case TAC_ZERO: fprintf(stderr, "TAC_ZERO"); break;
		case TAC_FUNCALL: fprintf(stderr, "TAC_FUNCALL"); break;
		case TAC_FUNDEF: fprintf(stderr, "TAC_FUNDEF"); break;
		case TAC_FUNC_START: fprintf(stderr, "TAC_FUNC_START"); break;
		case TAC_FUNC_END: fprintf(stderr, "TAC_FUNC_END"); break;
		case TAC_ARG_RECEIVE: fprintf(stderr, "TAC_ARG_RECEIVE"); break;
		case TAC_ARG_CALL: fprintf(stderr, "TAC_ARG_CALL"); break;
		case TAC_CALL: fprintf(stderr, "TAC_CALL"); break;
		default: fprintf(stderr, "TAC_UNKNOWN"); break;
	}
	if (tac->res) fprintf(stderr, ",%s", tac->res->yytext);
	else fprintf(stderr, ",0");
	if (tac->op1) fprintf(stderr, ",%s", tac->op1->yytext);
	else fprintf(stderr, ",0");
	if (tac->op2) fprintf(stderr, ",%s", tac->op2->yytext);
	else fprintf(stderr, ",0");
	fprintf(stderr,")\n");
}

void tacPrintBack(TAC* tac)
{
		if(!tac) return;
		tacPrintSingle(tac);
		tacPrintBack(tac->prev);
}

TAC* tacReverse(TAC*last)
{
	//fprintf(stderr, "TacReverse\n tacLast: %d\n",last);
	TAC *tac = 0;
	//if(!last) return 0;
	for (tac = last; tac->prev; tac = tac->prev)
		tac->prev->next = tac;
	return tac;
}


void tacPrintForward(TAC*tac)
{
	//fprintf(stderr, "printf\n");
	if(!tac) return;
	tacPrintSingle(tac);
	tacPrintForward(tac->next);
}


TAC* tacJoin(TAC*l1, TAC*l2)
{
	TAC* aux = 0;
	if (!l1){return l2;}
	if (!l2){return l1;}
	for (aux = l2 ; aux->prev; aux = aux->prev){
		//fprintf(stderr, "tacJoin %d\n", aux);
		;}
	aux->prev = l1;
	//testar com e sem isso:
	//l1->next = tac; 
	return l2;
	
}

TAC* codeGenerator(AST* node)
{
	//fprintf(stderr, "CodeGenerator\n");
	int i;
	TAC* result = 0;
	TAC* code[MAX_SONS];
	if (!node) {/*fprintf(stderr, "primeiro return\n");*/ return 0;}
	for (i=0; i<MAX_SONS; i++)
		code[i] = codeGenerator(node->son[i]);
	//fprintf(stderr, "node->type: %d\n", node->type);
	//fprintf(stderr, "code0 %d   code1 %d   code2 %d   code3 %d   : %d\n", code[0],code[1],code[2],code[3]);
	switch(node->type)
	{
		case	AST_SYMBOL: result = tacCreate(TAC_SYMBOL,node->symbol,0,0);
			break;
		case	AST_ADD: result = makeBinOp(TAC_ADD,code[0],code[1]);
			break;
		case	AST_SUB: result = makeBinOp(TAC_SUB,code[0],code[1]);
			break;
		case	AST_MUL: result = makeBinOp(TAC_MUL,code[0],code[1]);
			break;
		case	AST_DIV: result = makeBinOp(TAC_DIV,code[0],code[1]);
			break;
		case	AST_LES: result = makeBinOp(TAC_LESS,code[0],code[1]);
			break;
		case	AST_GRE: result = makeBinOp(TAC_GREATER,code[0],code[1]);
			break;
		case	AST_LEQ: result = makeBinOp(TAC_LEQ,code[0],code[1]);
			break;
		case	AST_GEQ: result = makeBinOp(TAC_GEQ,code[0],code[1]);
			break;
		case	AST_EQU: result = makeBinOp(TAC_EQU,code[0],code[1]);
			break;
		case	AST_COMPARE: result = tacJoin(code[0], tacCreate(TAC_EQU, makeTemp(), node->symbol, code[0]?code[0]->res:0));
			break;			
		case	AST_NEQ: result = makeBinOp(TAC_NEQ,code[0],code[1]);
			break;
		case 	AST_AND: result = makeBinOp(TAC_AND, code[0],code[1]);
			break;
		case 	AST_OR: result = makeBinOp(TAC_OR, code[0],code[1]);
			break;	
		case 	AST_NOT: result = tacJoin(code[0], tacCreate(TAC_NOT, makeTemp(), code[0]?code[0]->res:0, 0));
			break;			
		case	AST_ATR: result = tacJoin(code[0], tacCreate(TAC_ASS, node->symbol, code[0]?code[0]->res:0,0));
			break;
		case	AST_ATRVEC: result = makeAtrVec(node->symbol,code[0],code[1]);
			break;			
		case	AST_DECINIT: {result = tacJoin(code[0], tacCreate(TAC_DECINIT, node->symbol, code[1]?code[1]->res:0,0)); /*fprintf(stderr, "declaracao --> code0 %d   code1 %d   code2 %d   code3 %d   : %d\n", code[0],code[1],code[2],code[3]);*/}
			break;			
		case 	AST_IF: result = makeIfThen(code[0],code[1]);
			break;
		case 	AST_IFE: result = makeIfThenElse(code[0],code[1],code[2]);
			break;
		case 	AST_FOR: result = makeFor(node->symbol,code[0],code[1],code[2]);
			break;
		case 	AST_WHI: result = makeWhile(code[0],code[1]);
			break;
		case 	AST_RET: result = tacJoin(code[0], tacCreate(TAC_RET, code[0]?code[0]->res:0,0,0));
			break;
		case 	AST_PRI: result = makePrint(node);
			break;
		case 	AST_READ: result = tacCreate(TAC_READ, node->symbol, 0,0);
			break;	
		case 	AST_DECVECLI: result = makeDecVetInic(node);
			break;
		case	AST_BLCOM: result = code[0];
			break;
		case 	AST_FUN: result = makeFuncCall(node);
			break;
		case 	AST_FUND: result = makeFuncDef(node->symbol, code[0], code[1], code[2], node);
			break;
					
	
		default: {result = tacJoin(tacJoin(tacJoin(code[0],code[1]),code[2]),code[3]); /*fprintf(stderr, "code0 %d   code1 %d   code2 %d   code3 %d   : %d\n", code[0],code[1],code[2],code[3])*/;}
	}
	//fprintf(stderr, "ultimo return...%d\n ", result);
	return result;
}

TAC* makeBinOp(int type, TAC* code0, TAC* code1)
{
	//tacJoin(code[0],tacJoin(code[1],tacCreate(TAC_ADD,makeTemp(),code[0]?code[0]->res:0,code[1]?code[1]->res:0)));
	
	TAC* newtac = tacCreate(type, makeTemp(), code0?code0->res:0,code1?code1->res:0);	
	//fprintf(stderr, "NewTac: %s\n", newtac->res->yytext);
	return tacJoin(code0,tacJoin(code1,newtac));
}

TAC* makeIfThen(TAC *code0, TAC *code1){
	TAC* newiftac = 0 ;
	TAC* newlabeltac = 0 ;
	hash *newlabel = 0;
	
	newlabel = makeLabel();
	newiftac = tacCreate(TAC_IFZ,newlabel,code0?code0->res:0,0);
	newlabeltac = tacCreate(TAC_LABEL, newlabel,0,0);
	
	return tacJoin(tacJoin(tacJoin(code0,newiftac), code1),newlabeltac);
	
}

TAC* makeIfThenElse(TAC *code0, TAC *code1, TAC *code2){
	TAC* ifTac = 0 ;
	TAC* JumpTac = 0 ;
	TAC* elseLabelTac = 0 ;
	TAC* endLabelTac = 0 ;
	hash* elseLabel = makeLabel();
	hash* endLabel = makeLabel();	
	
	ifTac = tacCreate(TAC_IFZ,elseLabel,code0?code0->res:0,0);
	JumpTac = tacCreate(TAC_JUMP,endLabel,0,0);
	
	elseLabelTac = tacCreate(TAC_LABEL, elseLabel,0,0);
	endLabelTac = tacCreate(TAC_LABEL, endLabel,0,0);
	
	return tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(code0, ifTac),code1 ),JumpTac ), elseLabelTac) , code2) , endLabelTac);	
}

TAC* makeFor(hash* symbol, TAC *code0, TAC *code1, TAC *code2){
	TAC* assTac = 0 ;
	TAC* equalTac = 0 ;
	TAC* JumpTac = 0 ;	
	TAC* beginLabelTac = 0 ;	
	TAC* ifTac = 0 ;
	TAC* outLabelTac = 0 ;	
	hash* beginLabel = makeLabel();
	hash* outLabel = makeLabel();
	hash* VarTemp = makeTemp();
	
	assTac = tacCreate(TAC_ASS, symbol, code0->res,0);
	beginLabelTac = tacCreate(TAC_LABEL, beginLabel,0,0);
	equalTac = tacCreate(TAC_EQUAL, VarTemp, symbol,code1->res);
	ifTac = tacCreate(TAC_IFNZ,outLabel,VarTemp,0);
	JumpTac = tacCreate(TAC_JUMP,beginLabel,0,0);
	outLabelTac = tacCreate(TAC_LABEL, outLabel,0,0);
	
	return tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(assTac,beginLabelTac),equalTac),ifTac),code2), JumpTac), outLabelTac);
}

TAC* makeWhile(TAC *code0, TAC *code1){
	TAC* iftac = 0;
	TAC* labeltac1 = 0;
	TAC* labeltac2 = 0;
	TAC* jump = 0;
	hash* newlabel1 = 0;
	hash* newlabel2 = 0;
	newlabel1 = makeLabel();
	newlabel2 = makeLabel();
	
	iftac = tacCreate(TAC_IFNZ,newlabel2,code0?code0->res : 0, 0);
	labeltac1 = tacCreate(TAC_LABEL,newlabel1,0,0);
	labeltac2 = tacCreate(TAC_LABEL,newlabel2,0,0);
	jump = tacCreate(TAC_JUMP,newlabel1,0,0);
	
	return tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(labeltac1,code0),iftac),code1),jump),labeltac2);
	
}

TAC* makePrint(AST* node){
	TAC* priTac = 0;
	TAC* listTac = 0;
	
	node = node->son[0];
	while(node){
		priTac = tacCreate(TAC_PRI, node->son[0]->symbol, 0,0);
		listTac = tacJoin(listTac, priTac);
		node = node->son[1];
	}
	return listTac;	
}

TAC* makeAtrVec(hash* symbol, TAC *code0, TAC *code1){
	TAC* atrVecTac = 0;
	
	atrVecTac = tacCreate(TAC_ATRVEC,symbol, code0?code0->res:0, code1?code1->res:0 );
	
	return tacJoin(tacJoin(code0, code1), atrVecTac);
}

TAC* makeDecVetInic(AST* node){
	hash* symbol = node->symbol;
	TAC* zeroTac = 0;
	TAC* incTac = 0;
	TAC* listTac = 0;
	hash* VarTemp = makeTemp();
	zeroTac = tacCreate(TAC_ZERO,VarTemp, 0, 0 );	
	listTac = tacJoin(listTac, zeroTac);
	node = node->son[2];
	while(node){
		listTac = tacJoin(listTac, tacCreate(TAC_ATRVEC,symbol,VarTemp, node->son[0]->symbol));
		incTac = tacCreate(TAC_INC,VarTemp, 0, 0 );
		listTac = tacJoin(listTac, incTac);
		node = node->son[1]?node->son[1]:0;
	}
	return listTac;
	
}

TAC* makeFuncDef(hash* identifier, TAC *code0, TAC *code1, TAC *code2, AST *funcDef){
	AST* buff;
	TAC* tacBuff = 0;
	TAC* tacArg = 0;
	TAC* params = 0;
	//int i = 1;

	
	TAC* beginFunc = tacCreate(TAC_FUNC_START, identifier, 0, 0);
	
	
	

	for(buff = funcDef->son[0]->son[1]; buff; buff = buff->son[1]){
		tacBuff = codeGenerator(buff->son[0]);
		tacArg = tacCreate(TAC_ARG_RECEIVE, tacBuff->res, 0, identifier); //esse controle com o int i serve pra controlar o número de argumentos, não sei como que fica no nosso... CONVERSAR SOBRE ISSO!!!
		params = tacJoin(tacJoin(params,tacBuff), tacArg);
		//i++;
	}
	
	
	

	TAC* endFunc = tacCreate(TAC_FUNC_END, identifier, 0, 0);
	return tacJoin(tacJoin(tacJoin(beginFunc,params),code2), endFunc);
}


TAC* makeFuncCall(AST *funcCall){
	TAC* tacCall = 0;	
	TAC* params = 0;
	AST* buff = 0;
	TAC* tacBuff = 0;
	TAC* tacArg = 0;
	//int i = 1;
	hash* func_name = funcCall->symbol;
	for(buff = funcCall->son[0]; buff; buff = buff->son[1]){
		tacBuff = codeGenerator(buff->son[0]);
		tacArg = tacCreate(TAC_ARG_CALL, 0, tacBuff->res,func_name);
		params = tacJoin(tacJoin(params,tacBuff),tacArg);
		//i++;
	}

	hash* tempCall = makeTemp();
	tacCall = tacCreate(TAC_CALL, tempCall, funcCall->symbol,0); //não sei se precisa
	return tacJoin(params,tacCall);
}



//#endif