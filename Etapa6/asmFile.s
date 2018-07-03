.data
a:	.long	20
b:	.long	10
c:	.long	100
_VarTemp3:	.long	1
_VarTemp5:	.long	0
_VarTemp4:	.long	0
.def	__main;	.scl	2;	.type	32;	.endef
.section .rdata,"dr"
_Label1:	.ascii "TESTEIF"
_Label2:	.ascii "FIMTESTE"
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
movl	_VarTemp3(%rip), %eax
movl	%eax, a(%rip)
movl	a(%rip), %edx
movl	_VarTemp4(%rip), %eax
cmpl	%eax, %edx
sete	%al
movzbl	%al, %edx
leaq	_VarTemp5(%rip), %rax
movl	%edx, (%rax)
leaq	_VarTemp5(%rip), %rax
movl	_VarTemp5(%rip), %eax
testl	%eax, %eax
jne	_Label0
leaq	_Label1(%rip), %rcx
call	puts
_Label0:
leaq	_Label2(%rip), %rcx
call	puts
movl	$0, %eax
addq	$32, %rsp
popq	%rbp
ret
.seh_endproc
