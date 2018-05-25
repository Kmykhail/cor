# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozharko <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/23 14:20:43 by ozharko           #+#    #+#              #
#    Updated: 2018/05/23 14:20:45 by ozharko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@make -C ./vm
	@make -C ./asem

clean:
	@make clean -C ./vm
	@make clean -C ./asem

fclean:
	@make fclean -C ./vm
	@make fclean -C ./asem

re:
	@make re -C ./vm
	@make re -C ./asem

.PHONY: all clean fclean re