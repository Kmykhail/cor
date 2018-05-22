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


	dprintf(FD, "INVALID______FUNCTION_______________\n");
	dprintf(FD, "ID = %d\n", proc->id);
	dprintf(FD, "FUN [%02x] ID [%d] CC = [%d] PC =[%d]\n", main->map[proc->index], proc->id, main->cur_cycle, proc->index);test_show_me_label_arg(main, proc);
	dprintf(FD, "END_________________________________________\n");
	dprintf(FD, " main->map 0 = %x\n",  main->map[ ( proc->index + 0 ) % MEM_SIZE ]);
	dprintf(FD, " main->map 1 = %x\n",  main->map[ ( proc->index + 1 ) % MEM_SIZE ]);
	dprintf(FD, " main->map 2 = %x\n",  main->map[ ( proc->index + 2 ) % MEM_SIZE ]);
	dprintf(FD, " main->map 3 = %x\n",  main->map[ ( proc->index + 3 ) % MEM_SIZE ]);
	dprintf(FD, " main->map 4 = %x\n",  main->map[ ( proc->index + 4 ) % MEM_SIZE ]);
	dprintf(FD, " main->map 5 = %x\n",  main->map[ ( proc->index + 5 ) % MEM_SIZE ]);
	dprintf(FD, " main->map 6 = %x\n",  main->map[ ( proc->index + 6 ) % MEM_SIZE ]);
	dprintf(FD, " main->map 7 = %x\n",  main->map[ ( proc->index + 7 ) % MEM_SIZE ]);
	dprintf(FD, " main->map 8 = %x\n",  main->map[ ( proc->index + 8 ) % MEM_SIZE ]);
	dir = 0;
	num_proc = main->map[proc->index % MEM_SIZE];
	// if (main->arg[0] == 0 && main->arg[1] == 0 && main->arg[2] == 0)
	// {
	// 	proc->index++;
	// 	return ;
	// }
	if (num_proc == 1 || num_proc == 2 || num_proc == 3 || num_proc == 4 || num_proc == 5 || num_proc == 6 || num_proc == 7 || num_proc == 8 || num_proc == 13)
		dir = 4;
	else
		dir = 2;

	if (num_proc == 2 || num_proc == 3 || num_proc == 4 || num_proc == 5 || num_proc == 6 || num_proc == 7 || num_proc == 8 || num_proc == 10 || num_proc == 11 || num_proc == 13 || num_proc == 14)
		step = 2;
	else
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

	dprintf(FD, "STEP = %d\n", step);
	dprintf(FD, "STEP + proc->index = %d\n", ( proc->index + step ) % MEM_SIZE);
	proc->index = ( proc->index + step ) % MEM_SIZE;

}