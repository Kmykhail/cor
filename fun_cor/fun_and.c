/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_and.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 11:08:12 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/24 11:08:13 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void    fun_and(t_main *main, t_process *proc)
{
    int     k;
    int     res;
    int		carry;
    int     i;
    int     num_reg;
    
	// test_show_me_label_arg(main);
    ready_arg(main, proc);
    res = main->ready_arg[0][0] & main->ready_arg[1][0];
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
    // test_show_me_label_arg(main);
}

