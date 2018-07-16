	.file	"i.c"
	.globl	a
	.data
	.align 4
a:
	.long	10
	.globl	b
	.align 4
b:
	.long	10
	.globl	c
	.align 4
c:
	.long	100
	.globl	um
	.align 4
um:
	.long	1
	.globl	a1
	.align 4
a1:
	.long	10
	.globl	a2
	.align 4
a2:
	.long	10
	.text
	.globl	foo1
	.def	foo1;	.scl	2;	.type	32;	.endef
	.seh_proc	foo1
foo1:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	movl	%r9d, 40(%rbp)
	movl	a(%rip), %eax
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	call	__main
	movl	$7, 48(%rsp)
	movl	$6, 40(%rsp)
	movl	$5, 32(%rsp)
	movl	$4, %r9d
	movl	$3, %r8d
	movl	$2, %edx
	movl	$1, %ecx
	call	foo1
	movl	$0, %eax
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (tdm64-1) 5.1.0"
