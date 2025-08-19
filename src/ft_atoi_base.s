global	ft_atoi_base

P_STR		equ	8
P_BASE		equ	16
I_BLEN		equ	24
B_SIGN		equ	32

section	.data
	INVALID		db	"+-", 0x9, 0xA, 0xB, 0xC, 0x2, 0x20, 0x0
	extern		ft_strlen

section	.text

ft_atoi_base:
	; rdi = char *str
	; rsi = char *base

	push	rbp
	mov	rbp, rsp
	sub	rsp, 32
	
	mov	[rbp-P_STR], rdi
	mov	[rbp-P_BASE], rsi
  	mov	qword [rbp-B_SIGN], 1

	mov	rdi, rsi
	call	ft_strlen
	
	cmp	rax, 2
	jl	.invalid

	mov	[rbp-I_BLEN], rax
		
	; check for invalid character
	mov	rcx, 0
	xor	rsi, rsi

	.invalid_char_while:
	mov	rdi, INVALID
	mov	rbx, [rbp-P_BASE]
	mov	sil, [rbx+rcx]
	cmp	sil, 0x0
	je	.duplicate_char_start
	push	rcx
	call	contains
	pop	rcx
	cmp	rax, 0
	jge	.invalid	
	inc	rcx
	jmp	.invalid_char_while

	; check for duplicate character
	.duplicate_char_start:
	mov	rcx, 0
	xor	rsi, rsi
	
	.duplicate_char_while:
	mov	rdi, [rbp-P_BASE]
	add	rdi, rcx
	mov	sil, [rdi]
	inc	rdi
	cmp	sil, 0x0
	je	.sign_start
	push	rcx	
	call	contains
	pop	rcx
	cmp	rax, 0
	jge	.invalid
	inc	rcx
	jmp	.duplicate_char_while

	.sign_start:
  	mov	rdi, [rbp-P_STR]
  	xor	rcx, rcx

  	.sign_while:
  	mov	cl, [rdi]
  	cmp	cl, '+'
  	je	.sign_continue
  	cmp	cl, '-'
  	jne	.calculate_number_start
  	neg	qword [rbp-B_SIGN]  
  	.sign_continue:
  	inc	rdi
  	jmp	.sign_while

  	.calculate_number_start:
  	mov	rax, 0	; final number

	.calculate_number_while:
  	mov	cl, [rdi]
  	cmp	cl, 0x0
  	je	.endcount 
  	xor	rsi, rsi
	mov	sil, cl
	push	rdi
	mov	rdi, [rbp-P_BASE]
	push	rax
  	call	contains	; rdi = base, rsi = current string char
  	mov	rcx, rax	; number position in base
	pop	rax
	pop	rdi
	cmp	rcx, -1
  	je	.endcount
  	; ret += (ret * base_length) + (get num in base)	
  	mul	qword [rbp-I_BLEN]	; multiply number by base length
  	add	rax, rcx		; add len position
  	inc	rdi			; go to next character in str
  	jmp	.calculate_number_while

  	.endcount:
  	cmp	qword [rbp-B_SIGN], 1
  	je	.exit
  	neg	rax
  	jmp	.exit

	.invalid:
	mov	rax, 0

	.exit:
	mov	rsp, rbp
	pop	rbp
	ret

contains: ; rdi = *str, rsi = char
	mov	rax, rdi
	xor	rbx, rbx
	
	.while_not_in_base:
	mov	bl, [rax]
	cmp	bl, 0
	jz	.exit_not_in_base
	cmp	bl, sil
	jz	.exit_in_base
	inc	rax
	jmp	.while_not_in_base

	.exit_in_base:
	sub	rax, rdi
	jmp	.exit_base		

	.exit_not_in_base:
	mov	rax, -1
		
	.exit_base:
	ret
