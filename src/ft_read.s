SYS_READ	equ	0

global ft_read

section .data
	extern	__errno_location

section .text

ft_read:
	push	rbp
	mov	rbp, rsp

	mov	rax, SYS_READ
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
