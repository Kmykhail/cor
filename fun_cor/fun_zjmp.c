/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_zjmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:14:48 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/24 18:14:50 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

/*
** CARRY 
*/

void	fun_zjmp(t_main *main, t_process *proc)
{
	int		carry;
	int		num;
	int		k;

	// dprintf(FD, "\n\n\n\n\n\n\n\n___________fun_zjmp__________\n\n");
	carry = 0;
	num = 2;
	k = 0;
	if (carry == 1)
	{
	    num = 2;
	    while (num--)
	    {
	        main->ready_arg[0][0] = main->ready_arg[0][0] << 8;
	        main->ready_arg[0][0] = main->ready_arg[0][0] | main->map[proc->index + 1 + k];  // 0b 68 00 00 00 01
	        k++;
	    }
		num = 0;
		num = main->ready_arg[0][0] % IDX_MOD;
		proc->pc = proc->pc + num;
	}
	else
		proc->index += 3;
	// proc->index += ft_step_pc(main, main->map[proc->index], proc);//изменить step на indx
}