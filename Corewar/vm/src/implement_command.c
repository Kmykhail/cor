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

#include "../inc/main.h"

int		choose_function_1(t_main *main, t_process *proc)
{
	if (main->map[proc->index] == 1 && !proc->cmd_cycle)
		fun_live(main, proc);
	else if (main->map[proc->index] == 2 && !proc->cmd_cycle)
		fun_ld(main, proc);
	else if (main->map[proc->index] == 3 && !proc->cmd_cycle)
		fun_st(main, proc);
	else if (main->map[proc->index] == 4 && !proc->cmd_cycle)
		fun_add(main, proc);
	else if (main->map[proc->index] == 5 && !proc->cmd_cycle)
		fun_sub(main, proc);
	else if (main->map[proc->index] == 6 && !proc->cmd_cycle)
		fun_and(main, proc);
	else if (main->map[proc->index] == 7 && !proc->cmd_cycle)
		fun_or(main, proc);
	else if (main->map[proc->index] == 8 && !proc->cmd_cycle)
		fun_xor(main, proc);
	return (1);
}

int		choose_function_2(t_main *main, t_process *proc)
{
	if (main->map[proc->index] == 9 && !proc->cmd_cycle)
		fun_zjmp(main, proc);
	else if (main->map[proc->index] == 10 && !proc->cmd_cycle)
		fun_ldi(main, proc);
	else if (main->map[proc->index] == 11 && !proc->cmd_cycle)
		fun_sti(main, proc);
	else if (main->map[proc->index] == 12 && !proc->cmd_cycle)
		fun_fork(main, proc);
	else if (main->map[proc->index] == 13 && !proc->cmd_cycle)
		fun_lld(main, proc);
	else if (main->map[proc->index] == 14 && !proc->cmd_cycle)
		fun_lldi(main, proc);
	else if (main->map[proc->index] == 15 && !proc->cmd_cycle)
		fun_lfork(main, proc);
	else if (main->map[proc->index] == 16 && !proc->cmd_cycle)
		fun_aff(main, proc);
	return (1);
}

void	ft_implement_command(t_main *main, t_process *proc)
{
	int x;

	x = 0;
	if (main->map[proc->index] >= 1 && main->map[proc->index] < 9)
	{
		if (choose_function_1(main, proc))
			return ;
	}
	else if (main->map[proc->index] >= 9 && main->map[proc->index] <= 16)
	{
		if (choose_function_2(main, proc))
			return ;
	}
	else
		proc->index = (proc->index + 1) % MEM_SIZE;
}
