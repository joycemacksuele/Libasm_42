# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfreitas <jfreitas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/20 00:53:22 by jfreitas          #+#    #+#              #
#    Updated: 2021/01/21 18:59:21 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

; int	ft_strcmp(const char *s1, const char *s2);
;
; rdi = s1
; rsi = s2
; rdx = to store variable s1
; r8 = to store variable s2
; rcx = counter/len/index for loop
; rax = return value (not changing it for safety)
; BYTE[ptr] is a char/8bits/1byte access memory, so, use an 8bits register
section .text
	global ft_strcmp			; Defining global Label

ft_strcmp:
	xor rcx, rcx				; Changes rcx operand (count/leni/index) to 0
								; Same as mov rcx, 0 (but faster)
	xor rdx, rdx				; Changes rdx to 0
	xor r8, r8					; Changes r8 to 0

loop:
	mov dl, BYTE[rdi + rcx]		; Move src/rdi + index/rcx to rdx (dl in 8bits)
	mov r8b, BYTE[rsi + rcx]	; Move src/rdi + index/rcx to rd8 (r8b in 8bits)
	cmp dl, 0					; Compare 0 to rdx (dl in 8bits)
	je exit						; If equal, exit
	cmp r8b, 0					; Compare 0 to rsi
	je exit						; If equal, exit
	cmp dl, r8b					; Compare r8 (r8b in 8bits) to rdx (dl in 8bits)
	jne exit					; Jump to exit if NOT equal (r8b != dl)
	inc rcx						; Incrementing rcx/index
	jmp loop					; Calling itself

exit:
	mov rax, rdx				; Moving rdx/s1 to rax (the return register)
	sub rax, r8					; s2/r8 - s1/rax
	ret
