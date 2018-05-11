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
	num_reg = main->ready_arg[1][1] - 1;
	while (r--)
	{
		proc->rg[num_reg][r] = res;
		res = res >> 8;
	}
}

static	void	fun_st_second_ind(t_main *main, t_process *proc)
{
	int			r;
	int			k;
	int 		num;
	short int	res;

	num = 2;
    k = 2;
    res = 0;

    res = main->ready_arg[1][0];
    res = (proc->index + res) % MEM_SIZE;
    if (res < 0)
    	res = MEM_SIZE + res;
    r = 0;
    while (r < 4)
    {
    	if (res + r >= 0)
    	{
	    	main->map[res + r] = proc->rg[main->ready_arg[0][1] - 1][r];
    	}
    	r++;
    }
    if (res + r >= 0)
    	lst_newchanges(main, proc, res, res + 3, 1);
}

void	fun_st(t_main *main, t_process *proc)
{
	test_show_part_of_map(main, proc);
	ready_arg(main, proc);
	if (main->arg[1] == 1)
	{
		fun_st_second_reg(main, proc);
	}
	if (main->arg[1] == 3)
	{
		fun_st_second_ind(main, proc);
	}
	proc->index += ft_step_pc(main, main->map[proc->index], proc);
	test_show_me_label_arg(main, proc);
}