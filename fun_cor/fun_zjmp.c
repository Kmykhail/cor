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
	int			num;
	int			k;
	short int	jump;

	num = 2;
	k = 0;
	jump = 0;

	dprintf(FD, "________________________proc->carry = %d\n", proc->carry);
	if (proc->carry == 1)
	{
	    num = 2;
	    while (num--)
	    {
	        jump = jump << 8;
	        dprintf(FD, "main->map[proc->index + 1 + k] = %x\n", main->map[proc->index + 1 + k]);
	        jump = jump | main->map[proc->index + 1 + k];
	        dprintf(FD, "jump = %d && num = %d\n", jump, num);
	        k++;
	    }
		num = 0;
		num = jump % IDX_MOD;
		proc->index = proc->index + num;
	}
	else
		proc->index += 3;
}