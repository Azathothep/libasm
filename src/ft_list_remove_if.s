LIST_NEXT_OFFSET	equ	8

P_BEGIN			equ	8
P_DATA			equ	16
F_CMP			equ	24
F_FREE			equ	32
P_PREV			equ	40

global	ft_list_remove_if

section	.data
	extern	free

section	.text

ft_list_remove_if:
	; rdi = t_list 	**begin_list
	; rsi = void	*data_ref
	; rdx = int	(*cmp)()
	; rcx = void	(*free_fct)(void *)

	push	rbp
	mov	rbp, rsp
	sub	rsp, 40

	mov	[rbp-F_CMP],  rdx	; r8 = *cmp
	mov	[rbp-F_FREE], rcx	
	mov	[rbp-P_BEGIN], rdi	; rbx = begin_list
	mov	[rbp-P_DATA], rsi	; rdx = data ref
					; r10 = free_fn
	mov	qword [rbp-P_PREV], 0x0	; r9 = previous list
	mov	rcx, [rdi]		; rcx = current list
	
	.while:
	cmp	rcx, 0x0
	jz	.exit
	mov	rdi, [rcx]
	mov	rsi, [rbp-P_DATA]
	push	rcx
	call	[rbp-F_CMP]
	pop	rcx
	
	jz	.remove
	mov	[rbp-P_PREV], rcx
	mov	rcx, [rcx+LIST_NEXT_OFFSET]
	jmp	.while

	.remove:
	mov	rdi, [rcx]
	push	rcx
	call	[rbp-F_FREE]
	pop	rcx
	
	mov	rdi, rcx			; pointer to list (to free)
	mov	rcx, [rcx+LIST_NEXT_OFFSET]	; current = next
	push	rcx
	call	free
	pop	rcx
	
	.check_begin_lst:
	mov	rdx, [rbp-P_PREV]
	cmp	rdx, 0x0
	jz	.lst_begin
	mov	[rdx+LIST_NEXT_OFFSET], rcx
	jmp	.while

	.lst_begin:
	mov	rbx, [rbp-P_BEGIN]
	mov	[rbx], rcx
	jmp	.while

	.exit:
	mov	rsp, rbp
	pop	rbp
	ret
