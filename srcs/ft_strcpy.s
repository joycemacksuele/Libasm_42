# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfreitas <jfreitas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/20 00:53:22 by jfreitas          #+#    #+#              #
#    Updated: 2021/01/20 01:00:47 by jfreitas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

; char	*ft_strcpy(char *dest, const char *src);
;
; rdi = dest
; rsi = src
; r8 = to store variable
; rcx = counter/len/index for loop
; rax = return value (not changinf it for safety)

section .text
	global ft_strlen			; Defining global Labels
;	global loop
;	global exit
	extern ft_strlen

ft_strlen:
	xor rcx, rcx				; Changes rcx operand (count/len) to zero.
								; Same as mov rcx, 0
	mov rdi, rsi				; Moving src to dest
	call ft_strlen				; rax holds ft_strlen src
	cmp BYTE[rdi + rcx], 0		; Compare zero to char ptr [src + count/len]
	je exit						; Jump to the exit "function", if cmp is equal

loop:
;	cmp BYTE[rdi + rcx], 0		; Compare zero to char ptr [arg + count/len]
;	je exit						; Jump to the exit "function", if cmp is equal
	mov r8, [rsi + rcx]
	mov [rdi + rcx], r8
	inc rcx						; Incrementing rcx (the counter)
	call loop					; Calling itself

exit:
	mov BYTE[rdi + rcx], 0	; Moving zero to the last index/rcx of dest/rdi
	mov rax, rdi				; Moving len/rcx to rax (the return register)
	ret
