; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: jfreitas <jfreitas@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/01/20 00:53:46 by jfreitas          #+#    #+#              ;
;    Updated: 2021/01/21 18:59:54 by user42           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

; size_t	ft_strlen(const char *s);
;
; rdi = s
; rcx = counter/len/index for loop
; rax = return value (not changing it for safety)
section .text
	global ft_strlen			; Defining global Label

ft_strlen:
	xor rcx, rcx				; Changes rcx operand (count/len/index) to 0
								; Same as mov rcx, 0 (but faster))

loop:
	cmp BYTE[rdi + rcx], 0		; Compare 0 to char ptr [src/rdi + index/rcx]
	je exit						; Jump to the exit function, if cmp is equal
	inc rcx						; Incrementing rcx (the counter)
	jmp loop					; Calling itself

exit:
	mov rax, rcx				; Moving len/rcx to rax (the return register)
	ret
