.data
a:	.long	10
b:	.long	10
c:	.long	100
um:	.long	1
a1:	.long	10
a2:	.long	10
_VarTemp8:	.long	1
_VarTemp9:	.long	2
.def	__main;	.scl	2;	.type	32;	.endef
.section .rdata,"dr"
.text
.globl	main
.def	foo1;	.scl	2;	.type	32;	.endef
.seh_proc	foo1
foo1:
pushq	%rbp
.seh_pushreg	%rbp
movq	%rsp, %rbp
subq	$32, %rsp
.seh_stackalloc	32
.seh_endprologue
movl	$0, %eax
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
subq	$32, %rsp
.seh_stackalloc	32
.seh_endprologue
movl	$0, %eax
addq	$32, %rsp
popq	%rbp
ret
.seh_endproc
