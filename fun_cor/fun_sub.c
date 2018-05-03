/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:36:51 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/24 19:36:52 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	fun_sub(t_main *main, t_process *proc)
{
	int     i;
    int     num_reg;
    int		res;
    int     carry;

	ready_arg(main, proc);
	res = main->ready_arg[0][0] - main->ready_arg[1][0];
    if (res)
        carry = 0;
    else
        carry = 1;
	i = 4;
   	num_reg = main->ready_arg[2][1];
    while (i--)
    {
        proc->rg[num_reg][i] = res;
        res = res >> 8;
    }
    proc->index += ft_step_pc(main, main->map[proc->index], proc);//изменить step на indx
}
