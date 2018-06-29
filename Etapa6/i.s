	.file	"i.c"
	.globl	a
	.data
	.align 4
a:
	.long	20
	.globl	b
	.align 4
b:
	.long	10
	.section .rdata,"dr"
.LC0:
	.ascii "FOO\0"
	.text
.LC1:
	.ascii "MAIN\0"
	.text	
	
	
	
	.def	foo;	.scl	2;	.type	32;	.endef
	.seh_proc	foo
foo:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	leaq	.LC0(%rip), %rcx
	call	puts
	movl	$5, b(%rip)
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	
	
	
	
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
	
	leaq	.LC1(%rip), %rcx
	call	puts
	call	foo
	movl	$10, a(%rip)
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc

