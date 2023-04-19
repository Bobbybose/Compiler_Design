	.text
	.file	"math.c"
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rax
	.cfi_def_cfa_offset 16
	movq	%rsi, %rax
	movl	$30, %esi
	cmpl	$2, %edi
	jl	.LBB0_2
# %bb.1:
	movq	8(%rax), %rdi
	xorl	%esi, %esi
	movl	$10, %edx
	callq	strtol@PLT
	leal	(%rax,%rax,2), %esi
	addl	$30, %esi
.LBB0_2:
	leaq	.L.str(%rip), %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	xorl	%eax, %eax
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	.L.str,@object                  # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"hello, %d\n"
	.size	.L.str, 11

	.ident	"Ubuntu clang version 14.0.0-1ubuntu1"
	.section	".note.GNU-stack","",@progbits
