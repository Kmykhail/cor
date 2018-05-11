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
	{
		dprintf(FD, "1\n");
		dprintf(FD, "imp__b__proc->index = %d\n", proc->index);
		fun_live(main, proc);
		dprintf(FD, "imp__a__proc->index = %d\n", proc->index);
	}
	else if (main->map[proc->index] == 2 && !proc->cmd_cycle)//5
	{
		dprintf(FD, "2\n");
		dprintf(FD, "imp__b__proc->index = %d\n", proc->index);
		fun_ld(main, proc);
		dprintf(FD, "imp__a__proc->index = %d\n", proc->index);
	}
	else if (main->map[proc->index] == 3 && !proc->cmd_cycle)//5
	{
		dprintf(FD, "3\n");
		dprintf(FD, "imp__b__proc->index = %d\n", proc->index);
		fun_st(main, proc);
		dprintf(FD, "imp__a__proc->index = %d\n", proc->index);
	}
	else if (main->map[proc->index] == 4 && !proc->cmd_cycle)//10
	{
		dprintf(FD, "4\n");
		dprintf(FD, "imp__b__proc->index = %d\n", proc->index);
		fun_add(main, proc);
		dprintf(FD, "imp__a__proc->index = %d\n", proc->index);
	}
	else if (main->map[proc->index] == 5 && !proc->cmd_cycle)//10
	{
		dprintf(FD, "5\n");
		dprintf(FD, "imp__b__proc->index = %d\n", proc->index);
		fun_sub(main, proc);
		dprintf(FD, "imp__a__proc->index = %d\n", proc->index);
	}
	else if (main->map[proc->index] == 6 && !proc->cmd_cycle)//6
	{
		dprintf(FD, "6\n");
		dprintf(FD, "imp__b__proc->index = %d\n", proc->index);
		fun_and(main, proc);
		dprintf(FD, "imp__a__proc->index = %d\n", proc->index);
	}
	else if (main->map[proc->index] == 7 && !proc->cmd_cycle)//6
	{
		dprintf(FD, "7\n");
		dprintf(FD, "imp__b__proc->index = %d\n", proc->index);
		fun_or(main, proc);
		dprintf(FD, "imp__a__proc->index = %d\n", proc->index);
	}
	else if (main->map[proc->index] == 8 && !proc->cmd_cycle)//6
	{
		dprintf(FD, "8\n");
		dprintf(FD, "imp__b__proc->index = %d\n", proc->index);
		fun_xor(main, proc);
		dprintf(FD, "imp__a__proc->index = %d\n", proc->index);
	}
	return (1);
}

int		choose_function_2(t_main *main, t_process *proc)
{
	if (main->map[proc->index] == 9 && !proc->cmd_cycle)//20
	{
		dprintf(FD, "9\n");
		dprintf(FD, "imp__b__proc->index = %d\n", proc->index);
		fun_zjmp(main, proc);
		dprintf(FD, "imp__a__proc->index = %d\n", proc->index);
	}
	else if (main->map[proc->index] == 10 && !proc->cmd_cycle)//25
	{
		dprintf(FD, "10\n");
		dprintf(FD, "imp__b__proc->index = %d\n", proc->index);
		fun_ldi(main, proc);
		dprintf(FD, "imp__a__proc->index = %d\n", proc->index);
	}
	else if (main->map[proc->index] == 11 && !proc->cmd_cycle)//25
	{
		dprintf(FD, "11\n");
		dprintf(FD, "imp__b__proc->index = %d\n", proc->index);
		fun_sti(main, proc);
		dprintf(FD, "imp__a__proc->index = %d\n", proc->index);
	}
	else if (main->map[proc->index] == 12 && !proc->cmd_cycle)//800
	{
		dprintf(FD, "12\n");
		dprintf(FD, "imp__b__proc->index = %d\n", proc->index);
		fun_fork(main, proc);
		dprintf(FD, "imp__a__proc->index = %d\n", proc->index);
	}
	else if (main->map[proc->index] == 13 && !proc->cmd_cycle)//10
	{
		dprintf(FD, "13\n");
		dprintf(FD, "imp__b__proc->index = %d\n", proc->index);
		fun_lld(main, proc);
		dprintf(FD, "imp__a__proc->index = %d\n", proc->index);
	}
	else if (main->map[proc->index] == 14 && !proc->cmd_cycle)//50
	{
		dprintf(FD, "14\n");
		dprintf(FD, "imp__b__proc->index = %d\n", proc->index);
		fun_lldi(main, proc);
		dprintf(FD, "imp__a__proc->index = %d\n", proc->index);
	}
	else if (main->map[proc->index] == 15 && !proc->cmd_cycle)//1000
	{
		dprintf(FD, "15\n");
		dprintf(FD, "imp__b__proc->index = %d\n", proc->index);
		fun_lfork(main, proc);
		dprintf(FD, "imp__a__proc->index = %d\n", proc->index);
	}
	else if (main->map[proc->index] == 16 && !proc->cmd_cycle)//2
	{
		dprintf(FD, "16\n");
		dprintf(FD, "imp__b__proc->index = %d\n", proc->index);
		fun_aff(main, proc);
		dprintf(FD, "imp__a__proc->index = %d\n", proc->index);
	}
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
