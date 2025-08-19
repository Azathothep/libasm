global ft_strcpy

section	.data

section	.text

; char	*strcpy(char *destination, char *source);
ft_strcpy:
	push	rbp
	mov	rbp, rsp

	push	rdi
	
	.while:
	mov	al, byte [rsi]
	cmp	al, 0
	jz	.finished
	mov	byte [rdi], al
	inc	rsi
	inc	rdi
	jmp	.while

	.finished:
	mov	byte [rdi], 0
	pop	rax

	mov	rsp, rbp
	pop	rbp
	ret
