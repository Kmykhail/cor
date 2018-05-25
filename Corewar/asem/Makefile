# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: giabanji <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/23 14:20:43 by giabanji          #+#    #+#              #
#    Updated: 2018/05/23 14:20:45 by giabanji         ###   ########.fr        #
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

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) -L ../vm/lib/ -lft

%.o: ./src/%.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all
