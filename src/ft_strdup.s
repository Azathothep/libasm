SYS_BRK		equ	12

global	ft_strdup

section	.data
	extern	malloc
	extern	ft_strlen
	extern	ft_strcpy

section	.text

; char	*strdup(const char *s)
ft_strdup:
	push	rbp
	mov	rbp, rsp

	push	rdi		; push string to be copied on the stack
	call	ft_strlen
	inc	rax		; inc rax to leave place for \0
	call	malloc	
	
	pop	rsi		; get back the string to be copied, as second parameter for ft_strcpy
	push	rax		; push new string adress on the stack
	mov	rdi, rax
	call	ft_strcpy
	pop	rax		; return new string adress

	.exit:
	mov	rsp, rbp
	pop	rbp
	ret
