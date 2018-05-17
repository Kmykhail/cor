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
    int     num_reg_1;
    int     num_reg_2;
    int     num_reg_3;

    num_reg_1 = main->map[ ( proc->index + 1 + 1         ) % MEM_SIZE ] - 1;
    num_reg_2 = main->map[ ( proc->index + 1 + 1 + 1     ) % MEM_SIZE ] - 1;
    num_reg_3 = main->map[ ( proc->index + 1 + 1 + 1 + 1 ) % MEM_SIZE ] - 1;


    proc->rg[num_reg_3] = proc->rg[num_reg_1] + proc->rg[num_reg_2];

    // if (proc->id == 3)
    // {
    //     dprintf(FD, "proc->rg[num_reg_1] = %d\n", proc->rg[num_reg_1]);
    //     dprintf(FD, "proc->rg[num_reg_2] = %d\n", proc->rg[num_reg_2]);
    //     dprintf(FD, "proc->rg[num_reg_3] = %d\n", proc->rg[num_reg_3]);
    // }

    if (proc->rg[num_reg_3])
        proc->carry = 0;
    else
        proc->carry = 1;

    // if (proc->id == 3)
    // {
    //     dprintf(FD, "proc->carry = %d\n", proc->carry);
    // }
    proc->index += ft_step_pc(main, main->map[proc->index], proc);
}
