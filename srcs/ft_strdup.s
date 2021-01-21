; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: jfreitas <jfreitas@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/01/20 00:53:22 by jfreitas          #+#    #+#              ;
;    Updated: 2021/01/21 18:58:12 by user42           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

; char	*ft_strdup(const char *s);
;
; rdi = s
; rax = return value (not changing it for safety)
; malloc()functions returns a pointer to the allocated memory
; "When the contents of a segment register is pushed onto 64-bit stack, the pointer is automatically aligned to 64 bits (as with a stack that has a 32- bit width)."
section .text
	global ft_strdup			; Defining global Label
	extern ft_strlen			; size_t ft_strlen(const char *s);
	extern ft_strcpy			; char ft_strcpy(char *dest, const char *src);
	extern malloc				; void *malloc(size_t size);

ft_strdup:
	push rdi					; Store rdi/s (aligning to 64bits on the stack)
	call ft_strlen				; Func's arg is rid/s. Re turn's stored in rax
	inc rax						; rax (length) + 1 (for NULL termination)
	mov rdi, rax				; Move rax/length back to rdi/s to call malloc
	call malloc					; Call malloc with rdi/s as it's arg
; After malloc: original string is on stack, newly allocated string is in rax
	cmp rax, 0x00				; Check if malloc returned NULL or rdi was 0
	je exit_err					; Jump to exit_err if rax == 0
	mov rdi, rax				; Move return of malloc (ptr to address) to rdi
	pop rsi						; Restoring rsi to be the second arg of strcpy
	call ft_strcpy				; Call strcpy with ret of malloc and rsi as args
	ret							; return rax (ret of strcpy - ptr to dest)

exit_err:
	mov rax, 0					; Don't forget to return NULL (move 0 to rax),
	pop rdi						; and pop what have been pushed at the beginning
	ret							; to not corrupt the stack
