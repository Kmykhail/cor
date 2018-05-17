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
    int     num_reg_1;
    int     num_reg_2;
    int     num_reg_3;

    num_reg_1 = main->map[ ( proc->index + 1 + 1         ) % MEM_SIZE ] - 1;
    num_reg_2 = main->map[ ( proc->index + 1 + 1 + 1     ) % MEM_SIZE ] - 1;
    num_reg_3 = main->map[ ( proc->index + 1 + 1 + 1 + 1 ) % MEM_SIZE ] - 1;


    proc->rg[num_reg_3] = proc->rg[num_reg_1] - proc->rg[num_reg_2];

    if (proc->rg[num_reg_3])
        proc->carry = 0;
    else
        proc->carry = 1;

    proc->index += ft_step_pc(main, main->map[proc->index], proc);
}
