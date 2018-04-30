/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 09:18:50 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/24 09:18:52 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	choose_function_1(t_main *main)
{
	// if (main->map[main->pc] == 1)
	// 	fun_live(main);
	if (main->map[main->pc] == 2)
		fun_ld(main);
	if (main->map[main->pc] == 3)
		fun_st(main);
	if (main->map[main->pc] == 4)
		fun_add(main);
	if (main->map[main->pc] == 5)
		fun_sub(main);
	if (main->map[main->pc] == 6)
		fun_and(main);
	if (main->map[main->pc] == 7)
		fun_or(main);
	if (main->map[main->pc] == 8)
		fun_xor(main);
}

void	choose_function_2(t_main *main)
{
	if (main->map[main->pc] == 9)
		fun_zjmp(main);
	if (main->map[main->pc] == 10)
		fun_ldi(main);
	if (main->map[main->pc] == 11)
		fun_sti(main);
	// else if (main->map[main->pc] == 12)
	// 	fun_fork(main);
	if (main->map[main->pc] == 13)
		fun_lld(main);
	if (main->map[main->pc] == 14)
		fun_lldi(main);
	// else if (main->map[main->pc] == 15)
	// 	fun_lfork(main);
	else if (main->map[main->pc] == 16)
		fun_aff(main);
}


void    ft_implement_command(t_main *main)
{
    if (main->map[main->pc] >= 1 && main->map[main->pc] < 9)
        choose_function_1(main);
    else if (main->map[main->pc] >=9 && main->map[main->pc] <= 16)
        choose_function_2(main);
}


