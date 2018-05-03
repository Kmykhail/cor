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
	i = 4;
	num_reg = main->ready_arg[1][1];
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
	int		carry;
	int		step;
	int		res;
	int		r;
	int		num_reg;

	num_reg = main->ready_arg[1][1];
	carry = 0;
	res = main->ready_arg[0][0];
	if (res)
		carry = 0;
	else
		carry = 1;
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
	dprintf(FD, "______________________________\n");
	dprintf(FD, "FUN_LD\n");
	ready_arg(main, proc);
	if (main->arg[0] == 1)
		fun_ld_second_reg(main, proc);
	if (main->arg[0] == 3)
		fun_ld_second_ind(main, proc);
	dprintf(FD, "____________________________________\n");
	dprintf(FD, ">>>>>>>>>>>>>main->map[proc->index] = %d\n", main->map[proc->index]);
	dprintf(FD, "proc->index === %d\n", proc->index);
	proc->index += ft_step_pc(main, main->map[proc->index], proc);//изменить step на indx
	dprintf(FD, "next proc->index = %d\n", proc->index);
}
