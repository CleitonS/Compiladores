#include <stdio.h>
#include <stdlib.h>	
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

TAC* tacReserve(TAC*last)
{
	TAC*tac = 0;
	for (tac = last; tac->prev; tac = tac->prev)
		tac->prev->next = tac;
	return tac;
}


void tacPrintForward(TAC*tac)
{
	if(!tac) return;
	tacPrintSingle(tac);
	tacPrintForward(tac->next);
}


TAC* tacJoin(TAC*l1, TAC*l2)
{
	TAC* aux = 0;
	if (!l1) return l2;
	if (!l2) return l1;
	for (aux = l2 ; aux->prev; aux = aux->prev)
		aux->prev = l1;
	return l2;
}

TAC* codeGenerator(AST* node)
{
	int i;
	TAC* result = 0;
	TAC* code[MAX_SONS];
	if (!node) return 0;
	for (i=0; i<MAX_SONS; i++)
		code[i] = codeGenerator(node->son[i]);
	switch(node->type)
	{
		case	AST_SYMBOL: tacCreate(TAC_SYMBOL,node->symbol,0,0);
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
		case	AST_ATR: result = tacJoin(code[0], tacCreate(TAC_ASS, node->symbol, code[0]?code[0]->res:0,0)); //Era AST_ASS no professor, não sei qual o equivalente no nosso, botei atr.
			break;
		case 	AST_IFE: result = makeIfThen(code[0],code[1]);
		default: result = tacJoin(tacJoin(tacJoin(code[0],code[1]),code[2]),code[3]);
	}
	return result;
}

TAC* makeBinOP(int type, TAC* code0, TAC* code1)
{
	//tacJoin(code[0],tacJoin(code[1],tacCreate(TAC_ADD,makeTemp(),code[0]?code[0]->res:0,code[1]?code[1]->res:0)));
	
	TAC* newtac = tacCreate(type, makeTemp(), code0?code0->res:0,code1?code1->res:0);
	tacJoin(code0,tacJoin(code1,newtac));
}

TAC* makeIfThen(TAC *code0, TAC *code1){
	TAC* newiftac = 0 ;
	TAC* newlabeltac = 0 ;
	hash *newlabel = 0;
	
	newlabel = makelable();
	newiftac = tacCreate(TAC_IFZ,newlabel,code0?code0->res:0,0);
	newlabeltac = tacCreate(TAC_LABEL, newlabel,0,0);
	
	return tacJoin(tacJoin(tacJoin(code0,newiftac), code1),newlabeltac);
	
}
