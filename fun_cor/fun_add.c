/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:45:40 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/24 19:45:42 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	fun_add(t_main *main, t_process *proc)
{
    dprintf(FD, "___________fun_add______________\n");
	int     i;
    int     num_reg;
    int		res;
    int     carry;

	ready_arg(main, proc);
	res = main->ready_arg[0][0] + main->ready_arg[1][0];
    // dprintf(FD, "______res = %d\n", res);
    if (res)
        proc->carry = 0;
    else
        proc->carry = 1;
	i = 4;
    // dprintf(FD, "main->ready_arg[2][1] = %d\n", main->ready_arg[2][1]);
    // dprintf(FD, "main->ready_arg[2][1] - 1 = %d\n", main->ready_arg[2][1] - 1);
   	num_reg = main->ready_arg[2][1] - 1;
    // dprintf(FD, "num_reg = %d", num_reg);
    // dprintf(FD, "num_reg = %d", num_reg - 1);

    while (i--)
    {
        proc->rg[num_reg][i] = res;
        res = res >> 8;
    }
    proc->index += ft_step_pc(main, main->map[proc->index], proc);//изменить step на indx
    test_show_me_label_arg(main, proc);
    dprintf(FD, "__________________________________\n");
}
