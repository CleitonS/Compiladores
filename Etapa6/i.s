	.file	"i.c"
	.globl	x
	.data

x:
	.long	1
	.long	2
	.long	3
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "VEC: %d - %d - %d\0"
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
	movl	$0, x(%rip)
	movl	$1, 4+x(%rip)
	movl	$2, 8+x(%rip)
	movl	8+x(%rip), %ecx
	movl	4+x(%rip), %edx
	movl	x(%rip), %eax
	movl	%ecx, %r9d
	movl	%edx, %r8d
	movl	%eax, %edx
	leaq	.LC0(%rip), %rcx
	call	printf
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (tdm64-1) 5.1.0"
	.def	printf;	.scl	2;	.type	32;	.endef
