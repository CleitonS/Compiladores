.data
a:	.long	_VarTemp0
b:	.long	_VarTemp1
.def	__main;	.scl	2;	.type	32;	.endef
.section .rdata,"dr"
.text
.globl	main
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
