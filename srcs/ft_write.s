; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: jfreitas <jfreitas@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/01/20 00:53:22 by jfreitas          #+#    #+#              ;
;    Updated: 2021/01/21 15:15:36 by user42           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

; ssize_t	ft_write(int fd, const void *buf, size_t count);
;
; rdi = fd
; rsi = buf
; rdx = count
; rax = system call number and syscall's return  (return is negative for error)
; rcx = return address of syscall (an unsigner integer)
; "When the contents of a segment register is pushed onto 64-bit stack, the pointer is automatically aligned to 64 bits (as with a stack that has a 32- bit width)."
; Ubuntu: add wrt ..plt to call _errno_location to make its position independent
section .text
	global ft_write						; Defining global Label
	extern __errno_location				; int *__errno_location(void);

ft_write:
	mov rax, 1							; Sycall number for write
	syscall								; Calling the operating system
	jc exit_err							; Jump if unsigned carry flag overflow
	ret

exit_err:
	push rax							; push rax/syscall error return to stack
	call __errno_location wrt ..plt		; Ret = rax, the address of errno var
	pop rax
	mov rax, -1							; Move -1 error to rax
	ret									; So the return will be an error -1
