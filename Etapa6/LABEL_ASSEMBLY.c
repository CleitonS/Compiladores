
##VARIAVEIS
.data
x:	.long	20
y:	.long	10
z:	.long	0

##VETOR com inicializacao
## w[3] = {1,2,3}
w:				
	.long	1   
	.long	2
	.long	3



text: 	.ascii "teste\0"

.PRINT_NUMBER: 	.ascii "%d\0"
.PRINT_STRING: 	.ascii "%s\0"




##BEGIN FUNC
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
	
	

main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	__main
	
	
	
	
##OPERATIONS
	
	movl	x(%rip), %edx                 ##movl	<variaval_op1>(%rip), %edx	
	movl	y(%rip), %eax				  ##movl	<variaval_op2>(%rip), %eax
	addl	%edx, %eax                    ##ADD
	subl	%edx, %eax					  ##SUB
	imull	%edx, %eax				      ##MUL
	movl	%eax, z(%rip)                 ##movl	%eax, <variaval_res>(%rip)

##DIV
	movl	x(%rip), %eax   ##OP1
	movl	y(%rip), %ecx	##OP2
	idivl	%ecx
	movl	%eax, z(%rip)	##Res
	
##	c = a > b; 
	movl	a(%rip), %edx
	movl	b(%rip), %eax
	cmpl	%eax, %edx
	setg	%al
	movzbl	%al, %edx
	leaq	c(%rip), %rax
	movl	%edx, (%rax)
	leaq	c(%rip), %rax
	
##	c = a >= b; 
	movl	a(%rip), %edx
	movl	b(%rip), %eax
	cmpl	%eax, %edx
	setge	%al
	movzbl	%al, %edx
	leaq	c(%rip), %rax
	movl	%edx, (%rax)
	leaq	c(%rip), %rax	
	
##	c = a == b; 
	movl	a(%rip), %edx
	movl	b(%rip), %eax
	cmpl	%eax, %edx
	sete	%al
	movzbl	%al, %edx
	leaq	c(%rip), %rax
	movl	%edx, (%rax)
	leaq	c(%rip), %rax	


## 	c = (a && b); 
	movl	a(%rip), %eax
	testl	%eax, %eax
	je	.L2
	movl	b(%rip), %eax
	testl	%eax, %eax
	je	.L2
	movl	$1, %edx
	jmp	.L3
.L2:
	movl	$0, %edx
.L3:
	leaq	c(%rip), %rax
	movl	%edx, (%rax)
	leaq	c(%rip), %rax
	
	
## 	c = (a || b); 
	movl	a(%rip), %eax
	testl	%eax, %eax
	jne	.L2
	movl	b(%rip), %eax
	testl	%eax, %eax
	je	.L3
.L2:
	movl	$1, %edx
	jmp	.L4
.L3:
	movl	$0, %edx
.L4:
	leaq	c(%rip), %rax
	movl	%edx, (%rax)
	leaq	c(%rip), %rax	
	
	
	
	
##PRINT_NUMBER
	movl	x(%rip), %eax			      ##variavel x
	movl	%eax, %edx
	leaq	.PRINT_NUMBER(%rip), %rcx     ##esta definido da sessão de variáveis
	call	printf

##PRINT_STRING	
	leaq	text(%rip), %rdx				##variavel text
	leaq	.PRINT_STRING(%rip), %rcx
	call	printf
	
##IF_EQUAL		
## if (x == y)
## 	 x = 1;
## else
##   x = 2;
							
	movl	x(%rip), %eax    
	cmpl	y(%rip), %eax
	jne	.L2
	movl	$1, x(%rip)
	jmp	.L3
.L2:
	movl	$2, x(%rip)
.L3:	
	
	
	
	
	
##END FUNC	
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	