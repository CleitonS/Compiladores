	.file	"i.c"
	.globl	x
	.data
	.align 4
x:
	.long	20
	.globl	y
	.align 4
y:
	.long	10
	.globl	z
	.bss
	.align 4
z:
	.space 4
	.def	__main;	.scl	2;	.type	32;	.endef
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
	movl	x(%rip), %eax
	movl	y(%rip), %ecx
	
	idivl	%ecx
	movl	%eax, z(%rip)
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (tdm64-1) 5.1.0"
