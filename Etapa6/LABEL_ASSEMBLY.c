
##VARIAVEIS
.data
x:	.long	20
y:	.long	10
z:	.long	0


##BEGIN FUNC
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
	
	

main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
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
	
	
	
##END FUNC	
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	