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

#include "../inc/main.h"

void			fun_zjmp(t_main *main, t_process *proc)
{
	short int	jump;

	if (proc->carry == 1)
	{
		jump = 0;
		jump = jump | main->map[(proc->index + 1) % MEM_SIZE];
		jump = jump << 8;
		jump = jump | main->map[(proc->index + 1 + 1) % MEM_SIZE];
		jump = jump % IDX_MOD;
		proc->index = (proc->index + jump) % MEM_SIZE;
		if (proc->index < 0)
			proc->index = MEM_SIZE + proc->index;
	}
	else
		proc->index = (proc->index + 3) % MEM_SIZE;
}
