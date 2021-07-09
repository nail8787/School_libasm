global _ft_strlen
section .text
_ft_strlen:
xor	rdx, rdx
xor	rsi, rsi
_length:
cmp	[rdi], sil
je	_exit
inc	rdx
inc	rdi
jmp	_length
_exit:
mov	rax, rdx
ret