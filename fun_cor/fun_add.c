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

static void	fun_add_go(t_main *main, t_process *proc)
{
    int     num_reg_1;
    int     num_reg_2;
    int     num_reg_3;

    num_reg_1 = main->map[ ( proc->index + 1 + 1         ) % MEM_SIZE ] - 1;
    num_reg_2 = main->map[ ( proc->index + 1 + 1 + 1     ) % MEM_SIZE ] - 1;
    num_reg_3 = main->map[ ( proc->index + 1 + 1 + 1 + 1 ) % MEM_SIZE ] - 1;

    if ((num_reg_1 < 0 || num_reg_1 > 15) || (num_reg_2 < 0 || num_reg_2 > 15) || (num_reg_3 < 0 || num_reg_3 > 15))
    {
        unvalid_only_step(main, proc);
        return ;
    }

    proc->rg[num_reg_3] = proc->rg[num_reg_1] + proc->rg[num_reg_2];

    if (proc->rg[num_reg_3])
        proc->carry = 0;
    else
        proc->carry = 1;

    proc->index += ft_step_pc(main, main->map[proc->index], proc);
}

void    fun_add(t_main *main, t_process *proc)
{
    if (main->arg[0] == 1 && main->arg[1] == 1 && main->arg[2] == 1)
        fun_add_go(main, proc);
    else
        unvalid_only_step(main, proc);
}

/////////////////////

/////////////////////

/////////////////////

// void    fun_add(t_main *main, t_process *proc)
// {
//     int     num_reg_1;
//     int     num_reg_2;
//     int     num_reg_3;

//     num_reg_1 = main->map[ ( proc->index + 1 + 1         ) % MEM_SIZE ] - 1;
//     num_reg_2 = main->map[ ( proc->index + 1 + 1 + 1     ) % MEM_SIZE ] - 1;
//     num_reg_3 = main->map[ ( proc->index + 1 + 1 + 1 + 1 ) % MEM_SIZE ] - 1;


//     proc->rg[num_reg_3] = proc->rg[num_reg_1] + proc->rg[num_reg_2];

//     if (proc->rg[num_reg_3])
//         proc->carry = 0;
//     else
//         proc->carry = 1;

//     proc->index += ft_step_pc(main, main->map[proc->index], proc);
// }
