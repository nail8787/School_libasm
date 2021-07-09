global _ft_strcpy
section .text
_ft_strcpy:
xor rcx, rcx
_copy:
mov rdx, [rsi + rcx]
mov [rdi + rcx], rdx
inc rcx
cmp byte[rdi + rcx], 0
jne _copy
_exit:
mov rax, rdi
ret