# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozharko <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/23 14:20:43 by ozharko           #+#    #+#              #
#    Updated: 2018/07/10 20:32:28 by kmykhail         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@echo "\033[3;32mPlease wait a few seconds\033[0m"
	@make -C ./vm
	@make -C ./asem
	@echo "\033[3;36mcorewar has been made\033[0m"
clean:
	@make clean -C ./vm
	@make clean -C ./asem

fclean:
	@make fclean -C ./vm
	@make fclean -C ./asem
	@echo "\033[3;33mcorewar have been deleted\033[0m"
re:
	@echo "\033[3;32mPlease wait a few seconds\033[0m"
	@make re -C ./vm
	@make re -C ./asem
	@echo "\033[3;36mcorewar has been made\033[0m"

.PHONY: all clean fclean re
