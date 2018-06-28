
#include "tac.h"




int genasm(TAC* tac){
	FILE * asmData = fopen("asmData.s", "w+");
	FILE * asmCode = fopen("asmCode.s", "w+");	
	
	fprintf(asmData, ".data\n");	
	
	
	for(; tac; tac = tac->next){
		switch(tac->type)
		{
			
			case TAC_SYMBOL:
			/*
			em que caso terá um SYMBOL sem ser no print?
			    hash* label = makeLabel();
				fprintf(asmData, "%s:\t.ascii \"%s\"\\0\n", label->yytext, tac->res->yytext);
			*/		
			break;
			
			case TAC_ADD:
				fprintf(asmCode, "movl\t%s(%%rip), %%edx\n", tac->op1->yytext);
				fprintf(asmCode, "movl\t%s(%%rip), %%ecx\n", tac->op2->yytext);
				fprintf(asmCode, "addl\t%%edx, %%eax\n");
				fprintf(asmCode, "movl\t%%eax, %s(%%rip)\n", tac->res->yytext);			
			break;
			
			case TAC_SUB:
				fprintf(asmCode, "movl\t%s(%%rip), %%edx\n", tac->op1->yytext);
				fprintf(asmCode, "movl\t%s(%%rip), %%ecx\n", tac->op2->yytext);
				fprintf(asmCode, "subl\t%%edx, %%eax\n");
				fprintf(asmCode, "movl\t%%eax, %s(%%rip)\n", tac->res->yytext);				
			break;
			
			case TAC_MUL:
				fprintf(asmCode, "movl\t%s(%%rip), %%edx\n", tac->op1->yytext);
				fprintf(asmCode, "movl\t%s(%%rip), %%ecx\n", tac->op2->yytext);
				fprintf(asmCode, "imull\t%%edx, %%eax\n");
				fprintf(asmCode, "movl\t%%eax, %s(%%rip)\n", tac->res->yytext);				
			break;
			
			case TAC_DIV:
				fprintf(asmCode, "movl\t%s(%%rip), %%eax\n", tac->op1->yytext);
				fprintf(asmCode, "movl\t%s(%%rip), %%ecx\n", tac->op2->yytext);
				fprintf(asmCode, "idivl\t%%ecx\n");
				fprintf(asmCode, "movl\t%%eax, %s(%%rip)\n", tac->res->yytext);	
			break;
			
			case TAC_LESS:
			//res = op1 < op2
				fprintf(asmCode, "movl\t$s(%%rip), %%edx\n", tac->op2->yytext);
				fprintf(asmCode, "movl\t%s(%%rip), %%eax\n", tac->op1->yytext);
				fprintf(asmCode, "cmpl\t%%eax, %%edx\n");
				fprintf(asmCode, "setg\t%%al\n");
				fprintf(asmCode, "movzbl\t%%al, %%edx\n");
				fprintf(asmCode, "leaq\t%s(%%rip), %%rax\n", tac->res->yytext);
				fprintf(asmCode, "movl\t%%edx, (%%rax)\n");
				fprintf(asmCode, "leaq\t%s(%%rip), %%rax\n", tac->res->yytext);			
			
			
			break;
			case TAC_GREATER:
			//res = op1 > op2
				fprintf(asmCode, "movl\t$s(%%rip), %%edx\n", tac->op1->yytext);
				fprintf(asmCode, "movl\t%s(%%rip), %%eax\n", tac->op2->yytext);
				fprintf(asmCode, "cmpl\t%%eax, %%edx\n");
				fprintf(asmCode, "setg\t%%al\n");
				fprintf(asmCode, "movzbl\t%%al, %%edx\n");
				fprintf(asmCode, "leaq\t%s(%%rip), %%rax\n", tac->res->yytext);
				fprintf(asmCode, "movl\t%%edx, (%%rax)\n");
				fprintf(asmCode, "leaq\t%s(%%rip), %%rax\n", tac->res->yytext);		
			
			break;
			case TAC_ASS:
			break;
			case TAC_IFZ:
			break;
			case TAC_LABEL :
			break;
			case TAC_JUMP :
			break;
			case TAC_EQUAL :
			break;
			case TAC_IFNZ :
			break;
			case TAC_LEQ :
			//res = op1 <= op2
				fprintf(asmCode, "movl\t$s(%%rip), %%edx\n", tac->op2->yytext);
				fprintf(asmCode, "movl\t%s(%%rip), %%eax\n", tac->op1->yytext);
				fprintf(asmCode, "cmpl\t%%eax, %%edx\n");
				fprintf(asmCode, "setge\t%%al\n");
				fprintf(asmCode, "movzbl\t%%al, %%edx\n");
				fprintf(asmCode, "leaq\t%s(%%rip), %%rax\n", tac->res->yytext);
				fprintf(asmCode, "movl\t%%edx, (%%rax)\n");
				fprintf(asmCode, "leaq\t%s(%%rip), %%rax\n", tac->res->yytext);	
				
			break;
			case TAC_GEQ :
			//res = op1 >= op2
				fprintf(asmCode, "movl\t$s(%%rip), %%edx\n", tac->op1->yytext);
				fprintf(asmCode, "movl\t%s(%%rip), %%eax\n", tac->op2->yytext);
				fprintf(asmCode, "cmpl\t%%eax, %%edx\n");
				fprintf(asmCode, "setge\t%%al\n");
				fprintf(asmCode, "movzbl\t%%al, %%edx\n");
				fprintf(asmCode, "leaq\t%s(%%rip), %%rax\n", tac->res->yytext);
				fprintf(asmCode, "movl\t%%edx, (%%rax)\n");
				fprintf(asmCode, "leaq\t%s(%%rip), %%rax\n", tac->res->yytext);					
			break;
			case TAC_EQU :
			
			//res = op1 == op2
				fprintf(asmCode, "movl\t$s(%%rip), %%edx\n", tac->op1->yytext);
				fprintf(asmCode, "movl\t%s(%%rip), %%eax\n", tac->op2->yytext);
				fprintf(asmCode, "cmpl\t%%eax, %%edx\n");
				fprintf(asmCode, "sete\t%%al\n");
				fprintf(asmCode, "movzbl\t%%al, %%edx\n");
				fprintf(asmCode, "leaq\t%s(%%rip), %%rax\n", tac->res->yytext);
				fprintf(asmCode, "movl\t%%edx, (%%rax)\n");
				fprintf(asmCode, "leaq\t%s(%%rip), %%rax\n", tac->res->yytext);				
			
			break;
			case TAC_NEQ :
			
			//res = op1 != op2
				fprintf(asmCode, "movl\t$s(%%rip), %%edx\n", tac->op1->yytext);
				fprintf(asmCode, "movl\t%s(%%rip), %%eax\n", tac->op2->yytext);
				fprintf(asmCode, "cmpl\t%%eax, %%edx\n");
				fprintf(asmCode, "setne\t%%al\n");
				fprintf(asmCode, "movzbl\t%%al, %%edx\n");
				fprintf(asmCode, "leaq\t%s(%%rip), %%rax\n", tac->res->yytext);
				fprintf(asmCode, "movl\t%%edx, (%%rax)\n");
				fprintf(asmCode, "leaq\t%s(%%rip), %%rax\n", tac->res->yytext);				
			
			break;
			case TAC_AND :
				hash* label01 = makeLabel();
				hash* label02 = makeLabel();
				
				fprintf(asmCode, "movl\t%s(%%rip), %%eax\n", tac->op1->yytext);				
				fprintf(asmCode, "testl	%%eax, %%eax\n");
				fprintf(asmCode, "je\t%s\n", label01->yytext);
				fprintf(asmCode, "movl\t%s(%%rip), %%eax\n", tac->op2->yytext);
				fprintf(asmCode, "testl	%%eax, %%eax\n");
				fprintf(asmCode, "je\t%s\n", label01->yytext);
				fprintf(asmCode, "movl\t$$1, %%edx\n");
				fprintf(asmCode, "jmp\t$s\n", label02->yytext);
				fprintf(asmCode, "%s:\n", label01->yytext);
				fprintf(asmCode, "movl\t$$0, %%edx\n");
				fprintf(asmCode, "%s:\n", label02->yytext);
				fprintf(asmCode, "leaq\t$s(%%rip), %%rax\n", tac->res->yytext);
				fprintf(asmCode, "movl\t%%edx, (%%rax)\n");
				fprintf(asmCode, "leaq\t$s(%%rip), %%rax\n", tac->res->yytext);

			break;
			case TAC_OR :
				hash* label02 = makeLabel();
				hash* label03 = makeLabel();
				hash* label04 = makeLabel();
				
				fprintf(asmCode, "movl\t%s(%%rip), %%eax\n", tac->op1->yytext);
				fprintf(asmCode, "testl\t%%eax, %%eax\n");
				fprintf(asmCode, "jne\t%s\n", label02->yytext);
				fprintf(asmCode, "movl\t%s(%%rip), %%eax\n", tac->op2->yytext);
				fprintf(asmCode, "testl\t%%eax, %%eax\n");
				fprintf(asmCode, "je\t%s\n", label03->yytext);
				fprintf(asmCode, "%s:\n", label02->yytext);
				fprintf(asmCode, "movl\t$$1, %%edx\n");
				fprintf(asmCode, "jmp\t$s\n", label04->yytext);
				fprintf(asmCode, "%s:\n", label03->yytext);
				fprintf(asmCode, "movl\t$$0, %%edx\n");
				fprintf(asmCode, "%s:\n", label04->yytext);
				fprintf(asmCode, "leaq\t%s(%%rip), %%rax\n", tac->res->yytext);
				fprintf(asmCode, "movl\t%%edx, (%%rax)\n");
				fprintf(asmCode, "leaq\t%s(%%rip), %%rax\n", tac->res->yytext);

			break;
			case TAC_WHI :
			break;
			case TAC_RET :
			break;
			case TAC_NOT :
			break;
			case TAC_PRI :
			break;
			case TAC_READ :
			break;
			case TAC_ATRVEC :
			break;
			case TAC_DECVECLI :
			break;
			case TAC_ZERO :
			break;
			case TAC_INC :
			break;
			case TAC_FUNCALL :
			break;
			case TAC_FUNDEF :
			break;
			case TAC_FUNC_END :
			break;
			case TAC_FUNC_START :
			break;
			case TAC_ARG_RECEIVE :
			break;
			case TAC_ARG_CALL :
			break;
			case TAC_CALL :
			break;
			case TAC_DECINIT :
			break;
			case TAC_DECVET :
			break;
			case TAC_ATRVECINI:
			break;			
			
		}
	}
}