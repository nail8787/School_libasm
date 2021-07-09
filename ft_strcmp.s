global _ft_strcmp
section .text
_ft_strcmp:
xor	rcx, rcx
xor	rdx, rdx
xor	rbx, rbx
xor	rax, rax
_cmp:
mov	dl, [rdi + rcx]
mov	bl, [rsi + rcx]
cmp	dl, bl
jne _exit
cmp	byte [rsi + rcx], 0
je	_exit
cmp	byte [rdi + rcx], 0
je	_exit
inc	rcx
jmp	_cmp
_exit:
mov	al, [rdi + rcx]
mov	bl, [rsi + rcx]
sub	rax, rbx
ret