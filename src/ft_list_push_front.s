LIST_BYTE_SIZE	equ	16
LIST_DATA_SIZE	equ	8

P_DATA		equ	8

global	ft_list_push_front

section	.data
	extern	malloc

section	.text

ft_list_push_front:
	; rdi = t_list **begin_list, rsi = void	*data
	
	push	rbp
	mov	rbp, rsp
	sub	rsp, P_DATA
	
	push	rdi	
	mov	[rbp-P_DATA], rsi

	mov	rdi, LIST_BYTE_SIZE
	call	malloc
	
	cmp	rax, 0x0
	jz	.exit
	
	mov	rsi, [rbp-P_DATA]
	mov	[rax], rsi	; move *data to the first 8 bytes of allocated memory
	
	pop	rdi		; get back **begin_list
	mov	rbx, [rdi]	; get the adress of the first list

	mov	[rax+LIST_DATA_SIZE], rbx	; put the adress of the first list into the second 8 bytes of the new list
	
	mov	[rdi], rax	; put the new list into begin_list

	.exit:
	mov	rsp, rbp
	pop	rbp
	ret
