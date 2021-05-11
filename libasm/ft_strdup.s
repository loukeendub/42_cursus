global    _ft_strdup

extern    _ft_strlen
extern    _ft_strcpy
extern    _malloc
extern    ___error

section .text

_ft_strdup:
    cmp        rdi, 0
    je        error
    call    _ft_strlen
    push    rdi
    inc        rax
    mov        rdi, rax
    call    _malloc
    cmp        rax, 0
    je        enomem
    pop        rdi
    mov        rsi, rdi
    mov        rdi, rax
    call    _ft_strcpy
    ret

enomem:
    mov        rdi, 0xc
    call    ___error
    pop        rdi
    mov        rax, 0
    ret

error:
    mov rax, 0
    ret

