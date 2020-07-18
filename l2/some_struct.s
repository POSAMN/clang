	.file	"some_struct.c"
	.text
	.globl	template
	.section	.rodata
	.align 8
.LC0:
	.string	"num = %d; volume = %f; ints[0] = %d\n"
	.section	.data.rel.local,"aw",@progbits
	.align 8
	.type	template, @object
	.size	template, 8
template:
	.quad	.LC0
	.text
	.globl	printData
	.type	printData, @function
printData:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movl	(%rax), %edx
	movq	-8(%rbp), %rax
	movq	24(%rax), %rsi
	movq	-8(%rbp), %rax
	movl	(%rax), %ecx
	movq	template(%rip), %rax
	movq	%rsi, -16(%rbp)
	movsd	-16(%rbp), %xmm0
	movl	%ecx, %esi
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	printData, .-printData
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
