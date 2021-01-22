# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <jfreitas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/18 16:15:55 by user42            #+#    #+#              #
#    Updated: 2021/01/22 02:26:57 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm

CC = clang

NASM_FLAG = -f elf64

CFLAGS = -Wall -Wextra -Werror -g

LIB_NAME = libasm.a

SRCS = 	srcs/ft_strlen.s \
		srcs/ft_strcpy.s \
		srcs/ft_strcmp.s \
		srcs/ft_strdup.s \
		srcs/ft_write.s \
		srcs/ft_read.s

#OBJS = $(subst .s,.o,$(SRCS))
OBJS = ${SRCS:%.s=%.o}

all: $(NAME)
	@mkdir objs
	@mv ./srcs/*.o ./objs/

%.o:%.s
	@echo -n "\n\033[1;33mAssembling..."
	@echo "\033[0;32m"
	nasm $(NASM_FLAG) $^ -o $@

$(NAME): $(OBJS)
	@echo -n "\n\033[1;33mCreating libasm library..."
	@echo "\033[0;32m"
	ar rcs $(LIB_NAME) $(OBJS)
	@ranlib $(LIB_NAME)
	@echo -n "\n\033[1;33mCompiling with main.c..."
	@echo "\033[0;32m"
	$(CC) $(CFLAGS) srcs/main.c -L. -lasm -o $(NAME)
	@echo "\033[0m"

clean:
	@echo -n "\n\033[1;31mRemoving objs..."
	@echo "\033[0;32m"
	rm -rf ./objs
	rm -f a.out
	@rm -f write_example.txt
	@rm -f ft_write_example.txt
	@echo "\033[0m"

fclean: clean
	@echo -n "\033[1;31mRemoving library libasm..."
	@echo "\033[0;32m"
	rm -f $(LIB_NAME)
	@echo "\033[0m"
	@echo -n "\033[1;31mRemoving executable ./libasm..."
	@echo "\033[0;32m"
	rm -f $(NAME)
	@echo "\033[0m"

re: fclean all

.PHONY: all clean fclean re
