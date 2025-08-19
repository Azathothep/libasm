SYS_WRITE	equ	1

global ft_write

section	.data
	extern	__errno_location

section	.text

ft_write:
	push	rbp
	mov	rbp, rsp

	mov	rax, SYS_WRITE
	syscall

	cmp	rax, 0
	jge	.exit
	
	neg	rax
	push	rax
	call	__errno_location
	pop	qword [rax]
	mov	rax, -1

	.exit:
	mov	rsp, rbp
	pop	rbp

	ret
