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

int		choose_function_1(t_main *main, t_process *proc)
{
	if (main->map[proc->index] == 1 && main->cur_cycle % main->label[main->map[proc->index] - 1][2] == 0 && main->cur_cycle != 0)
		fun_live(main, proc);
	else if (main->map[proc->index] == 2 && main->cur_cycle % main->label[main->map[proc->index] - 1][2] == 0 && main->cur_cycle != 0)
		fun_ld(main, proc);
	else if (main->map[proc->index] == 3 && main->cur_cycle % main->label[main->map[proc->index] - 1][2] == 0 && main->cur_cycle != 0)
		fun_st(main, proc);
	else if (main->map[proc->index] == 4 && main->cur_cycle % main->label[main->map[proc->index] - 1][2] == 0 && main->cur_cycle != 0)
		fun_add(main, proc);
	else if (main->map[proc->index] == 5 && main->cur_cycle % main->label[main->map[proc->index] - 1][2] == 0 && main->cur_cycle != 0)
		fun_sub(main, proc);
	else if (main->map[proc->index] == 6 && main->cur_cycle % main->label[main->map[proc->index] - 1][2] == 0 && main->cur_cycle != 0)
		fun_and(main, proc);
	else if (main->map[proc->index] == 7 && main->cur_cycle % main->label[main->map[proc->index] - 1][2] == 0 && main->cur_cycle != 0)
		fun_or(main, proc);
	else if (main->map[proc->index] == 8 && main->cur_cycle % main->label[main->map[proc->index] - 1][2] == 0 && main->cur_cycle != 0)
		fun_xor(main, proc);
	return (1);
}

int		choose_function_2(t_main *main, t_process *proc)
{
	if (main->map[proc->index] == 9 && main->cur_cycle % main->label[main->map[proc->index] - 1][2] == 0 && main->cur_cycle != 0)
		fun_zjmp(main, proc);
	else if (main->map[proc->index] == 10 && main->cur_cycle % main->label[main->map[proc->index] - 1][2] == 0 && main->cur_cycle != 0)
		fun_ldi(main, proc);
	else if (main->map[proc->index] == 11 && main->cur_cycle % main->label[main->map[proc->index] - 1][2] == 0 && main->cur_cycle != 0)
		fun_sti(main, proc);
	else if (main->map[proc->index] == 12 && main->cur_cycle % main->label[main->map[proc->index] - 1][2] == 0 && main->cur_cycle != 0)
		fun_fork(main, proc);
	else if (main->map[proc->index] == 13 && main->cur_cycle % main->label[main->map[proc->index] - 1][2] == 0 && main->cur_cycle != 0)
		fun_lld(main, proc);
	else if (main->map[proc->index] == 14 && main->cur_cycle % main->label[main->map[proc->index] - 1][2] == 0 && main->cur_cycle != 0)
		fun_lldi(main, proc);
	else if (main->map[proc->index] == 15 && main->cur_cycle % main->label[main->map[proc->index] - 1][2] == 0 && main->cur_cycle != 0)
		fun_lfork(main, proc);
	else if (main->map[proc->index] == 16 && main->cur_cycle % main->label[main->map[proc->index] - 1][2] == 0 && main->cur_cycle != 0)
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


