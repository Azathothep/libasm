LIST_NEXT_OFFSET	equ	8

P_BEGIN			equ	8
F_CMP			equ	16

global	ft_list_sort

section	.data
	extern	ft_write

section	.bss
	num	resb	5

section	.text

; void	ft_list_sort(t_list **begin_list, int (*cmp)())
ft_list_sort:
	push	rbp
	mov	rbp, rsp
	sub	rsp, 16

	mov	[rbp-P_BEGIN], rdi  ; begin_list pointer
	mov	[rbp-F_CMP], rsi    ; function pointer

	mov	rcx, [rdi]          ; rcx = current list pointer
	mov	rdx, 0x0            ; rdx = prev list pointer
	
	.while:
	cmp	qword [rcx+LIST_NEXT_OFFSET], 0x0
	jz	.exit

	mov	rdi, [rcx]			; get data from current list
	mov	rsi, [rcx+LIST_NEXT_OFFSET] 	; get next list pointer
	mov	rsi, [rsi] 			; get data from next list
	
	push	rdx
	push	rcx
	call	[rbp-F_CMP]
	pop	rcx
	pop	rdx	
	jg	.swap				; cmp already returned info if negative
	
	mov	rdx, rcx
	mov	rcx, [rcx+LIST_NEXT_OFFSET]
	jmp	.while
	
	.swap:
	mov	rdi, [rbp-P_BEGIN]
	mov	rsi, rcx
	; rdx already holds the prev list pointer, no need to re-assign it as 3rd argument
	call	.ft_list_swap
	mov	rbx, [rbp-P_BEGIN]
	mov	rcx, [rbx]		; put the list back on the first ...
	mov	rdx, 0x0		; ... and reset the prev list pointer
	jmp	.while

	; rdi = begin_list, rsi = lst, rdx = prev
	.ft_list_swap:
		mov	rax, [rsi+LIST_NEXT_OFFSET]
		mov	rbx, [rax+LIST_NEXT_OFFSET]
		mov	[rax+LIST_NEXT_OFFSET], rsi
		mov	[rsi+LIST_NEXT_OFFSET], rbx
	
		cmp	rdx, 0x0
		jz	.begin
		mov	[rdx+LIST_NEXT_OFFSET], rax
		jmp	.exit_swap
		
		.begin:
		mov	[rdi], rax

		.exit_swap:
		ret

	.exit:
	mov	rsp, rbp
	pop	rbp
	ret
