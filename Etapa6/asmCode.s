.def	foo1;	.scl	2;	.type	32;	.endef
.seh_proc	foo1
foo1:
pushq	%rbp
.seh_pushreg	%rbp
movq	%rsp, %rbp
subq	$32, %rsp
.seh_stackalloc	32
.seh_endprologue
leaq	_Label2(%rip), %rcx
call	puts
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
movl	_VarTemp4(%rip), %eax
movl	%eax, a(%rip)
_Label0:
movl	a(%rip), %edx
movl	_VarTemp5(%rip), %eax
cmpl	%eax, %edx
setne	%al
movzbl	%al, %edx
leaq	_VarTemp6(%rip), %rax
movl	%edx, (%rax)
leaq	_VarTemp6(%rip), %rax
movl	_VarTemp6(%rip), %eax
testl	%eax, %eax
jnz	_Label1
leaq	_Label3(%rip), %rcx
call	puts
movl	a(%rip), %edx
movl	_VarTemp7(%rip), %ecx
addl	%edx, %ecx
movl	%ecx, _VarTemp8(%rip)
movl	_VarTemp8(%rip), %eax
movl	%eax, a(%rip)
jmp	_Label0
_Label1:
movl	$0, %eax
addq	$32, %rsp
popq	%rbp
ret
.seh_endproc
