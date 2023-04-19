	.text
	.file	"array.c"
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3                               # -- Begin function main
.LCPI0_0:
	.quad	0x3fd3333340000000              # double 0.30000001192092896
	.section	.rodata.cst4,"aM",@progbits,4
	.p2align	2
.LCPI0_1:
	.long	0x3e99999a                      # float 0.300000012
	.text
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%r15
	.cfi_def_cfa_offset 16
	pushq	%r14
	.cfi_def_cfa_offset 24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	subq	$16, %rsp
	.cfi_def_cfa_offset 48
	.cfi_offset %rbx, -32
	.cfi_offset %r14, -24
	.cfi_offset %r15, -16
	cmpl	$2, %edi
	jl	.LBB0_1
# %bb.2:
	movq	%rsi, %r14
	movl	%edi, %r15d
	movss	.LCPI0_1(%rip), %xmm0           # xmm0 = mem[0],zero,zero,zero
	movl	$1, %ebx
	.p2align	4, 0x90
.LBB0_3:                                # =>This Inner Loop Header: Depth=1
	movss	%xmm0, 12(%rsp)                 # 4-byte Spill
	movq	(%r14,%rbx,8), %rdi
	xorl	%esi, %esi
	movl	$10, %edx
	callq	strtol@PLT
	xorps	%xmm0, %xmm0
	cvtsi2ss	%rax, %xmm0
	movss	12(%rsp), %xmm1                 # 4-byte Reload
                                        # xmm1 = mem[0],zero,zero,zero
	addss	%xmm0, %xmm1
	movss	%xmm1, 12(%rsp)                 # 4-byte Spill
	movss	12(%rsp), %xmm0                 # 4-byte Reload
                                        # xmm0 = mem[0],zero,zero,zero
	addq	$1, %rbx
	cmpq	%rbx, %r15
	jne	.LBB0_3
# %bb.4:
	cvtss2sd	%xmm0, %xmm0
	jmp	.LBB0_5
.LBB0_1:
	movsd	.LCPI0_0(%rip), %xmm0           # xmm0 = mem[0],zero
.LBB0_5:
	leaq	.L.str(%rip), %rdi
	movb	$1, %al
	callq	printf@PLT
	xorl	%eax, %eax
	addq	$16, %rsp
	.cfi_def_cfa_offset 32
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	.L.str,@object                  # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"sum = %f\n"
	.size	.L.str, 10

	.ident	"Ubuntu clang version 14.0.0-1ubuntu1"
	.section	".note.GNU-stack","",@progbits
