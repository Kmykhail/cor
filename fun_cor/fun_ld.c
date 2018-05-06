/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_ld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 10:07:35 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/26 10:07:36 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

/*
** для T_IND не определен способ записи
*/

static	void	fun_ld_second_reg(t_main *main, t_process *proc)
{
	int		i;
	int		res;
	int		num_reg;

	res = main->ready_arg[0][0];
	if (res)
		proc->carry = 0;
	else
		proc->carry = 1;
	i = 4;
	num_reg = main->ready_arg[1][1] - 1;
	while (i--)
	{
		proc->rg[num_reg][i] = res;
		res = res >> 8;
	}
}

/*
** не понятно в какую ячейку надо делать запись ? T_IND !!!!!!!!!!!!!!!!!!!!!!
*/

static	void	fun_ld_second_ind(t_main *main, t_process *proc)
{
	int		step;
	int		res;
	int		r;
	int		num_reg;

	num_reg = main->ready_arg[1][1];
	res = main->ready_arg[0][0];
	if (res)
		proc->carry = 0;
	else
		proc->carry = 1;
	r = 0;
	while (r < 4)
	{
		proc->rg[num_reg][r] = proc->rg[num_reg][r] | res;
		res = res >> 8;
		r++;
	}
}

void	fun_ld(t_main *main, t_process *proc)
{
	dprintf(FD, "____FUN_LD__02____\n");
	dprintf(FD, "MAIN->CUR_CYCLE:%d PROC->INDEX:%d\n", main->cur_cycle, proc->index);
	test_show_part_of_map(main, proc);
	ready_arg(main, proc);
	if (main->arg[0] == 2)
	{
		fun_ld_second_reg(main, proc);
	}
	if (main->arg[0] == 3)
	{
		fun_ld_second_ind(main, proc);
	}
	proc->index += ft_step_pc(main, main->map[proc->index], proc);//изменить step на indx
	test_show_me_label_arg(main, proc);
	dprintf(FD, "___proc->carry:%d____\n", proc->carry);
}
