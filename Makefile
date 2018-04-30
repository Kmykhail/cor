# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/29 22:25:31 by kshyshki          #+#    #+#              #
#    Updated: 2018/02/22 10:16:39 by kshyshki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

FLAGS = -Wall -Wextra -Werror -o

SRCS =  main.c                  \
        visual.c			    \
        visual_fill_bar.c       \
        visual_fill_charts.c    \
        visual_fill_map.c       \
        visual_window.c         \
        read_bots.c             \
        make_cycle.c

OBJ=$(SRCS:.c=.o)

all: $(NAME)
	
$(NAME) : $(OBJ) 
	make -C libft/
	gcc $(FLAGS) $(NAME) $(SRCS)  -I /bin/ -L./libft -lft -lncurses #-fsanitize=address
clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)
fclean: clean
	rm -f libft/libft.a
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re norm
.NOTPARALLEL: all clean fclean re norm

norm:
	norminette *.c *.h
