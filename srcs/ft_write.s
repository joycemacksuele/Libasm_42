; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_write.s                                         :+:      :+:    :+:    ;
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
; locate unistd_64.h to see the number for the syscall
; rcx = return address of syscall (an unsigned integer)
; "When the contents of a segment register is pushed onto 64-bit stack, the pointer is automatically aligned to 64 bits"
; Ubuntu: add wrt ..plt to call _errno_location to make its position independent
; to be able to compile with gcc
section .text
	global ft_write						; Defining global Label
	extern __errno_location				; int *__errno_location(void);

ft_write:
	mov rax, 1							; Sycall number for write on Linux
	syscall								; Calling the operating system
	cmp rax, 0							; Compare rax(return of read) to 0
	jl exit_err							; Jump if rax is less than 0
	ret

exit_err:
	mov	r8, rax							; Move return value of rax/read() to r8
	call __errno_location wrt ..plt		; Ret = (the address of errno = rax)
	neg r8								; Negate the return value of read()
	mov qword[rax], r8					; Move r8/open ret to rax/errno address
	mov rax, -1							; Move -1 error to rax
	ret
