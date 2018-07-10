# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: giabanji <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/23 14:20:43 by giabanji          #+#    #+#              #
#    Updated: 2018/07/10 20:27:42 by kmykhail         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../asm

SRC = 	src/main.c			\
		src/extras_func.c	\
		src/get_next_line.c	\
		src/input_file.c	\
		src/operation.c		\
		src/operation2.c	\
		src/valid_name.c	\

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) -L ../vm/lib/ -lft

%.o: ./src/%.c
	@$(CC) $(FLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: clean all
