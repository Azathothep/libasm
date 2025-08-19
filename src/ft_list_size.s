LIST_NEXT_OFFSET		equ	8

global	ft_list_size

section	.data

section	.text

; int ft_list_size(t_list *begin_list);
ft_list_size:

	push	rbp
	mov	rbp, rsp

	mov	rax, 1
	
	.while:
	cmp	qword [rdi+LIST_NEXT_OFFSET], 0x0
	jz	.exit
	mov	rdi, [rdi+LIST_NEXT_OFFSET]
	inc	rax
	jmp	.while

	.exit:
	mov	rsp, rbp
	pop	rbp
	ret
