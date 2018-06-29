.def	main;	.scl	2;	.type	32;	.endef
.seh_proc	main
main:
pushq	%rbp
.seh_pushreg	%rbp
movq	%rsp, %rbp
subq	$32, %rsp
.seh_stackalloc	32
.seh_endprologue
movl	b(%rip), %edx
movl	_VarTemp2(%rip), %ecx
addl	%edx, %eax
movl	%eax, _VarTemp3(%rip)
movl	_VarTemp3(%rip), %eax
movl	%eax, a(%rip)
movl	$0, %eax
addq	$32, %rsp
popq	%rbp
ret
.seh_endproc
