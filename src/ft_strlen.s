global ft_strlen

section .data

section .text

; size_t strlen(const char *s);
ft_strlen:
	push	rbp
	mov	rbp, rsp

	mov	rax, rdi
	
	.while:
	cmp	byte [rax], 0
	jz	.exit
	inc	rax
	jmp	.while

	.exit:
	sub	rax, rdi
	
	mov	rsp, rbp
	pop	rbp
	ret
