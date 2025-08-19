global ft_strcmp

section .data

section .text

; int strcmp(const char *s1, const char *s2)
ft_strcmp:
	push	rbp
	mov	rbp, rsp

	xor	rax, rax

	.while:
	cmp	byte [rdi], 0
	jz	.finished
	cmp	byte [rsi], 0
	jz	.finished
	
	mov	al, [rdi]
	cmp	al, [rsi]
	jnz	.finished
	inc	rdi
	inc	rsi
	jmp	.while		

	.finished:
	mov	al, [rdi]	; move only 1 byte in rax
	xor	rdi, rdi	; clear rdi
	mov	dil, [rsi]	; move only 1 bite in rdi
	sub	eax, edi	; compare as two 2-bytes integers
	
	mov	rsp, rbp
	pop	rbp
	ret
