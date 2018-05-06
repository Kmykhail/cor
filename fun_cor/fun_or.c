/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:30:41 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/24 19:30:46 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

// static void	fun_or_reg(t_main *main, int res, t_process *proc)
// {
// 	int     i;
//     int     num_reg;

// 	i = 4;
//    	num_reg = main->ready_arg[2][1];
//     while (i--)
//     {
//         proc->rg[num_reg][i] = res;
//         res = res >> 8;
//     }
// }

// static void	fun_or_dir(t_main *main, int res, t_process *proc)
// {
// 	int 	i;
// 	int 	curr;

// 	curr = proc->pc;
// 	i = 4;
// 	while (i--)
// 	{
// 		CODE_OF_BOT[curr + 1 + i] = res;
// 		res = res >> 8;
// 	}
// }

// static void	fun_of_ind(t_main *main, int res, t_process *proc)
// {
// 	int		step;

// 	step = proc->pc + main->ready_arg[1][0] + main->ready_arg[2][0];
//     CODE_OF_BOT[proc->pc + step] = main->ready_arg[0][0];
// }

void    fun_or(t_main *main, t_process *proc)
{
    int     k;
    int     res;
    int     carry;
    int     i;
    int     num_reg;
    
    // test_show_me_label_arg(main);
    ready_arg(main, proc);
    res = main->ready_arg[0][0] | main->ready_arg[1][0];
    /*if (res)
        proc->carry = 0;
    else
        proc->carry = 1;*/
    i = 4;
    num_reg = main->ready_arg[2][1];
    while (i--)
    {
        proc->rg[num_reg][i] = res;
        res = res >> 8;
    }
    // test_show_me_label_arg(main);
    proc->index += ft_step_pc(main, main->map[proc->index], proc);//изменить step на indx
}


