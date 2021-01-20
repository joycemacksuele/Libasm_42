# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfreitas <jfreitas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/20 00:53:22 by jfreitas          #+#    #+#              #
#    Updated: 2021/01/20 23:16:34 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

; char	*ft_strcpy(char *dest, const char *src);
;
; rdi = dest
; rsi = src
; rdx = to store and move the rsi/src variable
; rcx = counter/len/index for loop
; rax = return value (not changinf it for safety)
section .text
	global ft_strcpy			; Defining global Label

ft_strcpy:
	xor rcx, rcx				; Changes rcx operand (count/len/index) to 0
								; Same as mov rcx, 0 (but faster)
	xor rdx, rdx				; Changes rdxi to 0

loop:
	cmp BYTE[rsi + rcx], 0		; Compare 0 to char ptr[src/rsi + index/rcx]
	je exit						; Jump to exit if equal (src == \0)
	mov rdx, [rsi + rcx]		; Move src/rsi + index/rcx to rdx
	mov [rdi + rcx], rdx		; Move rdx to the dest/rdi + index/rcx
	inc rcx						; Incrementing rcx/index
	call loop					; Calling itself

exit:
	mov BYTE[rdi + rcx], 0		; Moving 0 to the last index/rcx of dest/rdi
	mov rax, rdi				; Moving rdi/dest to rax (the return register)
	ret
