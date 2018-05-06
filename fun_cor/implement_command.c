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
/* ********************`****************************************************** */

#include "../main.h"

int		choose_function_1(t_main *main, t_process *proc)
{
	if (main->map[proc->index] == 1 && !proc->cmd_cycle)//10
		fun_live(main, proc);
	else if (main->map[proc->index] == 2 && !proc->cmd_cycle)//5
		fun_ld(main, proc);
	else if (main->map[proc->index] == 3 && !proc->cmd_cycle)//5
		fun_st(main, proc);
	else if (main->map[proc->index] == 4 && !proc->cmd_cycle)//10
		fun_add(main, proc);
	else if (main->map[proc->index] == 5 && !proc->cmd_cycle)//10
		fun_sub(main, proc);
	else if (main->map[proc->index] == 6 && !proc->cmd_cycle)//6
		fun_and(main, proc);
	else if (main->map[proc->index] == 7 && !proc->cmd_cycle)//6
		fun_or(main, proc);
	else if (main->map[proc->index] == 8 && !proc->cmd_cycle)//6
		fun_xor(main, proc);
	return (1);
}

int		choose_function_2(t_main *main, t_process *proc)
{
	if (main->map[proc->index] == 9 && !proc->cmd_cycle)//20
		fun_zjmp(main, proc);
	else if (main->map[proc->index] == 10 && !proc->cmd_cycle)//25
		fun_ldi(main, proc);
	else if (main->map[proc->index] == 11 && !proc->cmd_cycle)//25
		fun_sti(main, proc);
	else if (main->map[proc->index] == 12 && !proc->cmd_cycle)//800
		fun_fork(main, proc);
	else if (main->map[proc->index] == 13 && !proc->cmd_cycle)//10
		fun_lld(main, proc);
	else if (main->map[proc->index] == 14 && !proc->cmd_cycle)//50
		fun_lldi(main, proc);
	else if (main->map[proc->index] == 15 && !proc->cmd_cycle)//1000
		fun_lfork(main, proc);
	else if (main->map[proc->index] == 16 && !proc->cmd_cycle)//2
		fun_aff(main, proc);
	return (1);
}


void    ft_implement_command(t_main *main, t_process *proc)
{
    if (main->map[proc->index] >= 1 && main->map[proc->index] < 9)
    {
        if (choose_function_1(main, proc))
        {
        	return ;
        }
    }
    else if (main->map[proc->index] >=9 && main->map[proc->index] <= 16)
    {
        if (choose_function_2(main, proc))
        {
        	return ;
        }        
    }
}
