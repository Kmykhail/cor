/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 09:47:34 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/26 09:47:36 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"


void	fun_fork(t_main *main, t_process *proc)
{
	t_process	*new_proc;
	int			i;
	int			k;
	short int	res;

    res = 0;
    res = res | main->map[ ( proc->index + 1 ) % MEM_SIZE ];    
    res = res << 8;
    res = res | main->map[ ( proc->index + 2 ) % MEM_SIZE ];

	new_proc = (t_process *)malloc(sizeof(t_process));

	i = 0;
	while (i < 16)
	{

		new_proc->rg[i] = proc->rg[i];
		i++;
	}

	new_proc->nbr_pl = proc->nbr_pl;
	new_proc->live = proc->live;
	new_proc->carry = proc->carry;
	new_proc->next = NULL;

	new_proc->index = (proc->index + res % IDX_MOD) % MEM_SIZE;

	if (new_proc->index < 0)
		new_proc->index = MEM_SIZE + new_proc->index;

	if (main->map[new_proc->index] >= 1 && main->map[new_proc->index] <= 16)
		new_proc->cmd_cycle = main->label[main->map[new_proc->index] - 1][2];
	else
		new_proc->cmd_cycle = 0;

	main->id++;
	new_proc->id = main->id;
	
	 if (main->cur_cycle >= 4000)
	 {
	 	dprintf(FD, "!!!!FORK!!!!\n");
	 	dprintf(FD, "cur_cycle: %d\n", main->cur_cycle);
	 	dprintf(FD, "new_index: %d\n", new_proc->index);
	 	dprintf(FD, ">:%x< map[new_index]:%x\n", main->map[new_proc->index - 1], main->map[new_proc->index]);
	 	dprintf(FD, "new_proc->nbr_pl: %d\n", new_proc->nbr_pl);
	 	dprintf(FD, "new_proc->live: %d\n", new_proc->live);
	 	dprintf(FD, "new_proc->carry: %d\n", new_proc->carry);
	 	dprintf(FD, "new_proc->cmd_cycle: %d\n", new_proc->cmd_cycle);
	 	dprintf(FD, "new_proc->id: %d\n", new_proc->id);
	 }
	proc->index = (proc->index + 3) % MEM_SIZE;

	new_proc->next = main->lst_proc;
	main->lst_proc = new_proc;
	main->nbr_proc++;

}