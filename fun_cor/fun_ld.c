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


void	 show_ld(t_main *main, t_process *proc)
{
	dprintf(FD, "________________START____________\n");
	while (proc)
	{
		dprintf(FD, "cmd_cycle = %d\npc = %d\nindex; = %d\nnbr_pl = %d\nlive = %d\ncarry = %d\nproc->next = %p\nADD proc->rg = %p\n", proc->cmd_cycle, proc->pc, proc->index, proc->nbr_pl, proc->live, proc->carry, proc->next, proc->rg);
		test_show_me_label_arg(main, proc);
		proc = proc->next;
		dprintf(FD, "\nNEXT______NEXT_____NEXT\n\n");
	}
	dprintf(FD, "main->steper = %d\nmain->cp_cl_to_die = %d\nmain->cnt_p = %d\nmain->cur_cycle = %d\nmain->cl_to_die = %d\nmain->mx_check = %d\nmain->lst_proc = %p\nmain->nbr_proc = %d\nmain->lst_changes = %p\nmain->last_live_player = %p\nmain->finish = %d\nmain->ddddd = %d\n ",main->steper, main->cp_cl_to_die, main->cnt_pl, main->cur_cycle, main->cl_to_die, main->mx_check, main->lst_proc, main->nbr_proc, main->lst_changes, main->last_live_player, main->finish, main->ddddd );
	

	int i;
	int	j;

	i = 0;
	dprintf(FD, "________________PROC_LABEL_______________\n");
	dprintf(FD, "ADD main->label = %p\n", main->label);
	while ( i < 16)
	{
		j = 0;
		while (j < 4)
		{
			dprintf(FD, "[%4d]", main->label[i][j]);
			j++;
		}
		dprintf(FD, "\n");
		i++;
	}
	dprintf(FD, "__________________________END\n");
	dprintf(FD, "arg[0] = %d\n", main->arg[0]);
	dprintf(FD, "arg[1] = %d\n", main->arg[1]);
	dprintf(FD, "arg[2] = %d\n", main->arg[2]);
	dprintf(FD, "\n");
	dprintf(FD, "ready_arg[0][0] = %d\n", main->ready_arg[0][0]);
	dprintf(FD, "ready_arg[0][1] = %d\n", main->ready_arg[0][1]);
	dprintf(FD, "\n");
	dprintf(FD, "ready_arg[1][0] = %d\n", main->ready_arg[1][0]);
	dprintf(FD, "ready_arg[1][1] = %d\n", main->ready_arg[1][1]);
	dprintf(FD, "\n");
	dprintf(FD, "ready_arg[2][0] = %d\n", main->ready_arg[2][0]);
	dprintf(FD, "ready_arg[2][1] = %d\n", main->ready_arg[2][1]);
	dprintf(FD, "\n");
	dprintf(FD, "ADD ready_arg = %p\n", main->ready_arg);
	dprintf(FD, "\n");
	dprintf(FD, "coor_of_p[0] = %d\n", main->coor_of_p[0]);
	dprintf(FD, "coor_of_p[1] = %d\n", main->coor_of_p[1]);
	dprintf(FD, "coor_of_p[2] = %d\n", main->coor_of_p[2]);
	dprintf(FD, "coor_of_p[3] = %d\n", main->coor_of_p[3]);
	dprintf(FD, "ADD lst_changes = %p\n", main->lst_changes);
	dprintf(FD, "\n");

}

static	void	fun_ld_dir(t_main *main, t_process *proc)
{
	// dprintf(FD, "фннкция ld с dir\n");
	int		i;
	int		res;
	int		num_reg;

	res = main->ready_arg[0][0];

	if (res)
		proc->carry = 0;
	else
		proc->carry = 1;

	i = 3;
	num_reg = main->ready_arg[1][1] - 1;

	dprintf(FD, "__DIR___NUM_REG = %d\n", num_reg);
	// dprintf(FD, "Запись в регистр №%d\n", num_reg);

	dprintf(FD4, "RES = %d\n", res);
	while (i >= 0)
	{
		// if (num_reg > 15 && num_reg < 0 && i > 3 && i < 0)
		// {
		// 	exit (1);
		// }
		proc->rg[num_reg][i] = res;
		dprintf(FD, "ADDD proc->rg[%d][%d] = %p\n", num_reg, i, proc->rg);
		res = res >> 8;
		i--;
	}

}

/*
** не понятно в какую ячейку надо делать запись ? T_IND !!!!!!!!!!!!!!!!!!!!!!
*/

static	void	fun_ld_ind(t_main *main, t_process *proc)
{
	// dprintf(FD, "фннкция ld с ind\n");
	int		step;
	int		res;
	int		r;
	int		num_reg;

	num_reg = main->ready_arg[1][1] - 1;

	dprintf(FD, "___IND__NUM_REG = %d\n", num_reg);
	// dprintf(FD, "Запись в регистр №%d\n", num_reg);

	res = main->ready_arg[0][0];

	if (res)
		proc->carry = 0;
	else
		proc->carry = 1;

	r = 0;
	while (r < 4)
	{
		if (num_reg > 15 && num_reg < 0 && r > 3 && r < 0)
		{
			exit (1);
		}
		proc->rg[num_reg][r] = proc->rg[num_reg][r] | res;
		dprintf(FD, "ADDD proc->rg[%d][%d] = %p\n", num_reg, r, proc->rg);
		res = res >> 8;
		r++;
	}
}

void	fun_ld(t_main *main, t_process *proc)
{
	dprintf(FD, "____FUN_LD__02____\n");
	/*dprintf(FD, "MAIN->CUR_CYCLE:%d PROC->INDEX:%d\n", main->cur_cycle, proc->index);*/
	test_show_part_of_map(main, proc);
	ready_arg(main, proc);

	if (main->arg[0] == 2)
	{
		fun_ld_dir(main, proc);
	}

	if (main->arg[0] == 3)
	{
		fun_ld_ind(main, proc);
	}

	proc->index += ft_step_pc(main, main->map[proc->index], proc);//изменить step на indx

	test_show_me_label_arg(main, proc);
	dprintf(FD, "___proc->carry:%d____\n", proc->carry);
	//show_ld(main, proc);
}