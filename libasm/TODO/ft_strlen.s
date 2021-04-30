global _ft_strlen

section .data

section .text

_ft_strlen:
		mov		rax, -1
loop:	inc		rax	
		mov		cl, byte [rdi+rax]
		cmp		cl, 0
    	jne		loop
		ret
