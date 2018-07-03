
#include "tac.h"




int genasm(TAC* tac){
	FILE * asmData = fopen("asmData.s", "w+");
	FILE * asmRData = fopen("asmRData.s", "w+");
	FILE * asmCode = fopen("asmCode.s", "w+");	
	
	
	hash* label;
	hash* label01;
	hash* label02;
	hash* label03;
	hash* label04;

		

	
	
	fprintf(asmData, ".data\n");	
	fprintf(asmRData, ".def\t__main;\t.scl\t2;\t.type\t32;\t.endef\n");
	fprintf(asmRData, ".section .rdata,\"dr\"\n");
	printf("GENASM\n");
	
	for(; tac; tac = tac->next){
		printf("for %d\n", tac->type);
		switch(tac->type)
		{
			
			//case TAC_SYMBOL:
	
			//break;
			
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
				fprintf(asmCode, "cltd\n");
				fprintf(asmCode, "idivl\t%%ecx\n");
				fprintf(asmCode, "movl\t%%eax, %s(%%rip)\n", tac->res->yytext);	
			break;
			
			case TAC_LESS:
			//res = op1 < op2
				fprintf(asmCode, "movl\t%s(%%rip), %%edx\n", tac->op2->yytext);
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
				fprintf(asmCode, "movl\t%s(%%rip), %%edx\n", tac->op1->yytext);
				fprintf(asmCode, "movl\t%s(%%rip), %%eax\n", tac->op2->yytext);
				fprintf(asmCode, "cmpl\t%%eax, %%edx\n");
				fprintf(asmCode, "setg\t%%al\n");
				fprintf(asmCode, "movzbl\t%%al, %%edx\n");
				fprintf(asmCode, "leaq\t%s(%%rip), %%rax\n", tac->res->yytext);
				fprintf(asmCode, "movl\t%%edx, (%%rax)\n");
				fprintf(asmCode, "leaq\t%s(%%rip), %%rax\n", tac->res->yytext);		
			
			break;
			case TAC_ASS:
				fprintf(asmCode, "movl\t%s(%%rip), %%eax\n", tac->op1->yytext);	
				fprintf(asmCode, "movl\t%%eax, %s(%%rip)\n", tac->res->yytext);				
			
			break;
			
			
			/*TESTEI ATE AQUI*/
			
			case TAC_IFZ:
				fprintf(asmCode, "movl\t%s(%%rip), %%eax\n", tac->op1->yytext);				
				fprintf(asmCode, "testl\t%%eax, %%eax\n");
				fprintf(asmCode, "jne\t%s\n", tac->res->yytext);
			
			break;
			case TAC_LABEL :
				fprintf(asmCode, "%s:\n", tac->res->yytext);				
			break;
			case TAC_JUMP :
				fprintf(asmCode, "jmp\t%s\n", tac->res->yytext);
			break;
			case TAC_IFNZ :
				fprintf(asmCode, "movl\t%s(%%rip), %%eax\n", tac->op1->yytext);				
				fprintf(asmCode, "testl\t%%eax, %%eax\n");
				fprintf(asmCode, "je\t%s\n", tac->res->yytext);			
			break;
			case TAC_LEQ :
			//res = op1 <= op2
				fprintf(asmCode, "movl\t%s(%%rip), %%edx\n", tac->op2->yytext);
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
				fprintf(asmCode, "movl\t%s(%%rip), %%edx\n", tac->op1->yytext);
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
				fprintf(asmCode, "movl\t%s(%%rip), %%edx\n", tac->op1->yytext);
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
				fprintf(asmCode, "movl\t%s(%%rip), %%edx\n", tac->op1->yytext);
				fprintf(asmCode, "movl\t%s(%%rip), %%eax\n", tac->op2->yytext);
				fprintf(asmCode, "cmpl\t%%eax, %%edx\n");
				fprintf(asmCode, "setne\t%%al\n");
				fprintf(asmCode, "movzbl\t%%al, %%edx\n");
				fprintf(asmCode, "leaq\t%s(%%rip), %%rax\n", tac->res->yytext);
				fprintf(asmCode, "movl\t%%edx, (%%rax)\n");
				fprintf(asmCode, "leaq\t%s(%%rip), %%rax\n", tac->res->yytext);				
			
			break;
			case TAC_AND :
				label01 = makeLabel();
				label02 = makeLabel();
				
				fprintf(asmCode, "movl\t%s(%%rip), %%eax\n", tac->op1->yytext);				
				fprintf(asmCode, "testl	%%eax, %%eax\n");
				fprintf(asmCode, "je\t%s\n", label01->yytext);
				fprintf(asmCode, "movl\t%s(%%rip), %%eax\n", tac->op2->yytext);
				fprintf(asmCode, "testl	%%eax, %%eax\n");
				fprintf(asmCode, "je\t%s\n", label01->yytext);
				fprintf(asmCode, "movl\t$$1, %%edx\n");
				fprintf(asmCode, "jmp\t%s\n", label02->yytext);
				fprintf(asmCode, "%s:\n", label01->yytext);
				fprintf(asmCode, "movl\t$$0, %%edx\n");
				fprintf(asmCode, "%s:\n", label02->yytext);
				fprintf(asmCode, "leaq\t%s(%%rip), %%rax\n", tac->res->yytext);
				fprintf(asmCode, "movl\t%%edx, (%%rax)\n");
				fprintf(asmCode, "leaq\t%s(%%rip), %%rax\n", tac->res->yytext);

			break;
			case TAC_OR :
				label02 = makeLabel();
				label03 = makeLabel();
				label04 = makeLabel();
				
				fprintf(asmCode, "movl\t%s(%%rip), %%eax\n", tac->op1->yytext);
				fprintf(asmCode, "testl\t%%eax, %%eax\n");
				fprintf(asmCode, "jne\t%s\n", label02->yytext);
				fprintf(asmCode, "movl\t%s(%%rip), %%eax\n", tac->op2->yytext);
				fprintf(asmCode, "testl\t%%eax, %%eax\n");
				fprintf(asmCode, "je\t%s\n", label03->yytext);
				fprintf(asmCode, "%s:\n", label02->yytext);
				fprintf(asmCode, "movl\t$$1, %%edx\n");
				fprintf(asmCode, "jmp\t%s\n", label04->yytext);
				fprintf(asmCode, "%s:\n", label03->yytext);
				fprintf(asmCode, "movl\t$$0, %%edx\n");
				fprintf(asmCode, "%s:\n", label04->yytext);
				fprintf(asmCode, "leaq\t%s(%%rip), %%rax\n", tac->res->yytext);
				fprintf(asmCode, "movl\t%%edx, (%%rax)\n");
				fprintf(asmCode, "leaq\t%s(%%rip), %%rax\n", tac->res->yytext);

			break;
			case TAC_RET :
			break;
			case TAC_NOT :
				fprintf(asmCode, "movl	%s(%%rip), %%eax\n", tac->op1->yytext);
				fprintf(asmCode, "testl\t%%eax, %%eax\n");
				fprintf(asmCode, "sete\t%%al\n");
				fprintf(asmCode, "movzbl\t%%al, %%edx\n");
				fprintf(asmCode, "leaq\t%s(%%rip), %%rax\n", tac->res->yytext);
				fprintf(asmCode, "movl\t%%edx, (%%rax)\n");
				fprintf(asmCode, "leaq\t%s(%%rip), %%rax\n", tac->res->yytext);
				
			break;
			case TAC_PRI :
				label = makeLabel();
				
				fprintf(asmCode, "leaq\t%s(%%rip), %%rcx\n", label->yytext);
				fprintf(asmCode, "call\tputs\n");
				fprintf(asmRData, "%s:\t.ascii %s\n", label->yytext, tac->res->yytext );				
			
			break;
			case TAC_READ :
			break;
			case TAC_ATRVEC :
				
				fprintf(asmCode, "movl\t%s(%%rip), %%eax\n", tac->op1->yytext);
				fprintf(asmCode, "movl\t%s(%%rip), %%edx\n", tac->op2->yytext);
				fprintf(asmCode, "cltq\n");
				fprintf(asmCode, "leaq	0(,%%rax,4), %%rcx\n");
				fprintf(asmCode, "leaq\t%s(%%rip), %%rax\n", tac->res->yytext);
				fprintf(asmCode, "movl\t%%edx, (%%rcx,%%rax)\n");

			break;


			case TAC_FUNCALL :
			break;
			case TAC_FUNDEF :
			break;
			case TAC_FUNC_END :
				fprintf(asmCode, "movl\t$0, %%eax\n"
								 "addq\t$32, %%rsp\n"
								 "popq\t%%rbp\n"
								 "ret\n"
								 ".seh_endproc\n");
			break;
			case TAC_FUNC_START :
				fprintf(asmCode, ".def	%s;\t.scl\t2;\t.type\t32;\t.endef\n", tac->res->yytext);
				fprintf(asmCode, ".seh_proc\t%s\n", tac->res->yytext);
				fprintf(asmCode, "%s:\n", tac->res->yytext);
				fprintf(asmCode, "pushq\t%%rbp\n"
								 ".seh_pushreg\t%%rbp\n"
								 "movq\t%%rsp, %%rbp\n"
								 "subq\t$32, %%rsp\n"
								 ".seh_stackalloc\t32\n"
								 ".seh_endprologue\n" );
				
			break;
			case TAC_ARG_RECEIVE :
			break;
			case TAC_ARG_CALL :
			break;
			case TAC_CALL :
			break;
			case TAC_DECINIT :
				fprintf(asmData, "%s:\t.long\t%s\n", tac->res->yytext, tac->op1?tac->op1->yytext:"0");			
			break;
			case TAC_DECVET :
				fprintf(asmData, "%s:\n", tac->res->yytext);				
			break;
			case TAC_ATRVECINI:
				fprintf(asmData, "\t.long\t%s\n", tac->op1?tac->op1->yytext:"0");				
			break;			
			
		}
	}
	printf("terminou de percorrer...\n");
	
	
	fseek( asmData, 0, SEEK_SET );
	fseek( asmRData, 0, SEEK_SET );
	fseek( asmCode, 0, SEEK_SET );
	FILE * asmFile = fopen("asmFile.s", "w+");	
	char buffer[256];
	
	
	while(fgets(buffer, 256, asmData) != NULL)
		fputs(buffer, asmFile);	
	
	while(fgets(buffer, 256, asmRData) != NULL)
		fputs(buffer, asmFile);
		
	fprintf(asmFile, ".text\n");
	fprintf(asmFile, ".globl	main\n");
	
	while(fgets(buffer, 256, asmCode) != NULL)
		fputs(buffer, asmFile);
	
	

	fclose(asmData);
	fclose(asmRData);
	fclose(asmCode);
	fclose(asmFile);	
	return 0;
}