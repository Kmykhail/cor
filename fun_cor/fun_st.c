/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_st.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 09:54:20 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/26 09:54:22 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static	void	fun_st_second_reg(t_main *main, t_process *proc)
{
	int		r;
	int		res;
	int		num_reg;

	res = main->ready_arg[0][0];
	r = 4;
	num_reg = main->ready_arg[1][1];
	while (r--)
	{
		proc->rg[num_reg][r] = res;
		res = res >> 8;
	}
}

/*
** не понятно в какую ячейку надо делать запись ? T_REG или T_DIR !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

static	void	fun_st_second_ind(t_main *main, t_process *proc)
{
	dprintf(FD, "_____________FUN_ST_SECOND_IND_________________\n");
	int			r;
	int			k;
	int 		num;
	short int	res;

	num = 2;
    k = 2;
    res = 0;
    while (num--)
    {
        res = res << 8;
        res = res | main->map[proc->index + 1 + k];  // 0b 68 00 00 00 01
        dprintf(FD, "<< res = %d && k = %d\n", res, k);
        k++;
    }
    dprintf(FD, "res = %d\n", res);
    dprintf(FD, "main->ready_arg[0][0] %d\n", main->ready_arg[0][0]);
    dprintf(FD, "proc->index = %d\n", proc->index);
    r = 4;
    res = proc->index + res % IDX_MOD;
    while (r--)
    {
    	if (res + r >= 0)
    	{
	    	dprintf(FD, "res = %d && r = %d\n", res, r);
	    	dprintf(FD, "main->map[res + r] = %x\n", main->map[res + r]);
	    	main->map[res + r] = main->ready_arg[0][0];
	    	main->ready_arg[0][0] = main->ready_arg[0][0] << 8;
    	}
    }
    if (res + r >= 0)
    	lst_newchanges(main, proc, res, res + 3, 1);
}

void	fun_st(t_main *main, t_process *proc)
{
	ready_arg(main, proc);
	if (main->arg[1] == 1)
		fun_st_second_reg(main, proc);
	if (main->arg[1] == 3)
		fun_st_second_ind(main, proc);
	proc->index += ft_step_pc(main, main->map[proc->index], proc);//изменить step на indx
}