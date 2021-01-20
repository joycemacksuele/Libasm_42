# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfreitas <jfreitas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/20 00:53:46 by jfreitas          #+#    #+#              #
#    Updated: 2021/01/20 00:53:55 by jfreitas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

; size_t	ft_strlen(const char *s);
;
; rdi = s
; rcx = counter/len/index for loop
; rax = return value (not changinf it for safety)

section .text
	global ft_strlen			; Defining global Labels
;	global loop
;	global exit

ft_strlen:
	xor rcx, rcx				; Changes rcx operand (count/len) to zero.
								; Same as mov rcx, 0

loop:
	cmp BYTE[rdi + rcx], 0		; Compare zero to char ptr [arg + count/len]
	je exit						; Jump to the exit "function", if cmp is equal
	inc rcx						; Incrementing rcx (the counter)
	call loop					; Calling itself

exit:
	mov rax, rcx				; Moving len/rcx to rax (the return register)
	ret
