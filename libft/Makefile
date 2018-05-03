# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/29 22:25:31 by kshyshki          #+#    #+#              #
#    Updated: 2017/12/05 13:21:43 by kshyshki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRCS =	ft_memset.c	\
	ft_bzero.c		\
	ft_memcpy.c		\
	ft_memccpy.c	\
	ft_memmove.c	\
	ft_memchr.c		\
	ft_memcmp.c		\
	ft_strlen.c		\
	ft_strdup.c		\
	ft_strcpy.c		\
	ft_strncpy.c	\
	ft_strcat.c		\
	ft_strncat.c	\
	ft_strlcat.c	\
	ft_strchr.c		\
	ft_strrchr.c	\
	ft_strstr.c		\
	ft_strnstr.c	\
	ft_strcmp.c 	\
	ft_strncmp.c	\
	ft_atoi.c		\
	ft_isalpha.c	\
	ft_isdigit.c	\
	ft_isalnum.c	\
	ft_isascii.c	\
	ft_isprint.c	\
	ft_toupper.c	\
	ft_tolower.c	\
					\
	ft_memalloc.c	\
	ft_memdel.c		\
	ft_strnew.c		\
	ft_strdel.c		\
	ft_strclr.c		\
	ft_striter.c	\
	ft_striteri.c	\
	ft_strmap.c		\
	ft_strmapi.c	\
	ft_strequ.c		\
	ft_strnequ.c	\
	ft_strsub.c		\
	ft_strjoin.c	\
	ft_strtrim.c 	\
	ft_strsplit.c	\
	ft_itoa.c 		\
	ft_putchar.c	\
	ft_putstr.c 	\
	ft_putendl.c	\
	ft_putnbr.c 	\
	ft_putchar_fd.c	\
	ft_putstr_fd.c	\
	ft_putendl_fd.c	\
	ft_putnbr_fd.c	\
					\
	ft_lstnew.c 	\
	ft_lstdelone.c	\
	ft_lstdel.c		\
	ft_lstdel_top.c	\
	ft_lstadd.c		\
	ft_lstiter.c	\
	ft_lstmap.c		\
					\
	ft_strnew_cpy.c	\
	ft_add_at_end.c	\
	ft_len_arr_str.c\
	ft_addlast.c	\
	ft_swapbits.c	\
	ft_strnchr.c    \
                    \
	pf_funcs.c         \
	pf_lst_res.c       \
	pf_parse_fl_aux1.c \
	pf_parse_fl_aux2.c \
	pf_parse_fl_str.c  \
	pf_parse_fl_nbr.c  \
	pf_parse_nbr.c     \
	pf_parse_p.c       \
	pf_parse_str.c     \
	pf_get_sign_arg.c  \
	pf_itoabase.c   \
	pf_uchr.c       \
	pf_lst_ctr.c    \
	ft_printf.c     \
	get_next_line.c \
	ft_hex_to_int.c \
    ft_is_valid_nbr.c \
    ft_itoa_base.c      \
    ft_is_valid_hex.c   \
    ft_dell_arr_str.c   \

OBJ=$(SRCS:.c=.o)

all: $(NAME)
	
$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

%.o : %.c
	gcc $(FLAGS) -c $< -I /bin/

.PHONY: all clean fclean re norm
.NOTPARALLEL: all clean fclean re norm

norm:
	norminette *.c *.h
