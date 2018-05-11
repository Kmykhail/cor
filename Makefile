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
        make_cycle.c 			\
        init_visual.c			\
       	init_visual_new.c 		\
       	read_bots.c 			\
       	./fun_cor/fun_add.c 		\
       	./fun_cor/fun_aff.c 		\
       	./fun_cor/fun_and.c		\
       	./fun_cor/fun_fork.c		\
       	./fun_cor/fun_ld.c 		\
       	./fun_cor/fun_ldi.c 	\
       	./fun_cor/fun_lfork.c 	\
       	./fun_cor/fun_live.c 	\
       	./fun_cor/fun_lld.c 	\
       	./fun_cor/fun_lldi.c 	\
       	./fun_cor/fun_or.c 		\
       	./fun_cor/fun_st.c 		\
       	./fun_cor/fun_sti.c 	\
       	./fun_cor/fun_sub.c 	\
       	./fun_cor/fun_xor.c 	\
       	./fun_cor/fun_zjmp.c 	\
       	./fun_cor/implement_command.c 	\
       	./fun_cor/process_current.c 	\
       	./fun_cor/table_label.c 		\
       	./fun_cor/test.c

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
