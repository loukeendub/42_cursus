global _ft_strcmp

section .text

_ft_strcmp:
	mov		rcx, 0

loop:
	movzx		rax,byte[rdi+rcx]
	movzx		rdx,byte[rsi+rcx]
	cmp		rdx, 0
	je		exit
	cmp		rax, 0
	je		exit
	cmp		rax, rdx
	jne		exit
	inc		rcx
	jmp		loop

exit:
	sub		rax,rdx
	ret