global _ft_strcpy

section .data

section .text

_ft_strcpy:
	mov		rax, 0
	push	rdx

loop:	
	cmp		byte[rsi+rax], 0
	je		exit
	mov		dl, byte[rsi + rax]
	mov		byte[rdi + rax], dl
	inc		rax
	jmp		loop

exit:
	mov		rax, rdi
	pop		rdx
	ret