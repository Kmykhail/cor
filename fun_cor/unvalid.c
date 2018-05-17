/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unvalid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 12:48:04 by ozharko           #+#    #+#             */
/*   Updated: 2018/05/17 12:48:07 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	unvalid_only_step(t_main *main, t_process *proc)
{
	int		step;
	int		num_proc;
	int		dir;

	dir = 0;
	num_proc = main->map[proc->index % MEM_SIZE];
	if (num_proc == 1 || num_proc == 2 || num_proc == 3 || num_proc == 4 || num_proc == 5 || num_proc == 6 || num_proc == 7 || num_proc == 8 || num_proc == 13)
		dir = 4;
	else
		dir = 2;

	step = 1;
	if (main->arg[0] == 1)
		step = step + 1;
	else if (main->arg[0] == 2)
		step = step + dir;
	else if (main->arg[0] == 3)
		step = step + 2;

	if (main->arg[1] == 1)
		step = step + 1;
	else if (main->arg[1] == 2)
		step = step + dir;
	else if (main->arg[1] == 3)
		step = step + 2;

	if (main->arg[2] == 1)
		step = step + 1;
	else if (main->arg[2] == 2)
		step = step + dir;
	else if (main->arg[2] == 3)
		step = step + 1;

	proc->index = ( proc->index + step ) % MEM_SIZE;

}