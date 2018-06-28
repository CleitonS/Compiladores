	.file	"i.c"
	.globl	a
	.data
	.align 4
a:
	.long	1
	.globl	b
	.bss
	.align 4
b:
	.space 4
	.comm	c, 4, 2
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "%d\12\0"
	.text
	.globl	main
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
	
	
	
	leaq	.LC0(%rip), %rcx
	call	printf
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (tdm64-1) 5.1.0"
	.def	printf;	.scl	2;	.type	32;	.endef
