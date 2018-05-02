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

static void	choose_function_1(t_main *main, t_process *proc)
{
	// if (main->map[proc->pc] == 1)
	// 	fun_live(main, proc);
	if (main->map[proc->pc] == 2)
		fun_ld(main, proc);
	if (main->map[proc->pc] == 3)
		fun_st(main, proc);
	if (main->map[proc->pc] == 4)
		fun_add(main, proc);
	if (main->map[proc->pc] == 5)
		fun_sub(main, proc);
	if (main->map[proc->pc] == 6)
		fun_and(main, proc);
	if (main->map[proc->pc] == 7)
		fun_or(main, proc);
	if (main->map[proc->pc] == 8)
		fun_xor(main, proc);
}

static void	choose_function_2(t_main *main, t_process *proc)
{
	if (main->map[proc->pc] == 9)
		fun_zjmp(main, proc);
	if (main->map[proc->pc] == 10)
		fun_ldi(main, proc);
	if (main->map[proc->pc] == 11)
		fun_sti(main, proc);
	// else if (main->map[proc->pc] == 12)
	// 	fun_fork(main, proc);
	if (main->map[proc->pc] == 13)
		fun_lld(main, proc);
	if (main->map[proc->pc] == 14)
		fun_lldi(main, proc);
	// else if (main->map[proc->pc] == 15)
	// 	fun_lfork(main, proc);
	else if (main->map[proc->pc] == 16)
		fun_aff(main, proc);
}


void    ft_implement_command(t_main *main, t_process *proc)
{
    if (main->map[proc->pc] >= 1 && main->map[proc->pc] < 9)
        choose_function_1(main, proc);
    else if (main->map[proc->pc] >=9 && main->map[proc->pc] <= 16)
        choose_function_2(main, proc);
}


