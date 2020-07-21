	.file	"main.c"
	.text
	.data
	.type	orderOfOp, @object
	.size	orderOfOp, 4
orderOfOp:
	.ascii	"*/"
	.ascii	"+-"
	.text
	.globl	raiseError
	.type	raiseError, @function
raiseError:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	stderr(%rip), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movl	$-1, %edi
	call	exit@PLT
	.cfi_endproc
.LFE6:
	.size	raiseError, .-raiseError
	.section	.rodata
.LC0:
	.string	"1+1"
	.text
	.globl	main
	.type	main, @function
main:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	lexString@PLT
	cltq
	movq	%rax, -8(%rbp)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	main, .-main
	.ident	"GCC: (GNU) 10.1.0"
	.section	.note.GNU-stack,"",@progbits
