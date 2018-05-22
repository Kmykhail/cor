/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_live.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:19:26 by ozharko           #+#    #+#             */
/*   Updated: 2018/05/02 12:19:27 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

unsigned int	live_cur_per(t_main *main, t_process *proc, uint8_t nbr_pl)
{
	int		res;

	res = 0;
	while (proc)
	{
		if (proc->nbr_pl == nbr_pl)
		{
			//(main->cur_cycle >= 6074) ? dprintf(FD, "ID[%d] PROC_LIVE_IN_PROC: %d CC = [%d] PC =[%d]", proc->id, proc->live, main->cur_cycle, proc->index) : 0;
			res += proc->live;
			//(main->cur_cycle >= 6074) ? (dprintf(FD, "num_of_res: %d\n", res)) : 0;
		}
		proc = proc->next;
	}
	//if (main->cur_cycle >= 6074)
	//	dprintf (FD, "!RES: %d!\n", res);
	return (res);
}

void	fun_live(t_main *main, t_process *proc)
{
	int i;

	i = 0;
	proc->s_live++;
	/*if (main->cur_cycle >= 6074)
	{
		dprintf(FD, "ID[%d] PROC_LIVE_IN_PROC: %d CC = [%d] PC =[%d]\n", proc->id, proc->live, main->cur_cycle, proc->index);
		dprintf(FD, "^^main->map[ ( proc->index + 4 ) %% MEM_SIZE ] = %x\n", main->map[ ( proc->index + 4 ) % MEM_SIZE ]);
	}*/
	while (main->players[i] != NULL)
	{
		if (main->map[ ( proc->index + 4 ) % MEM_SIZE ] == main->players[i]->nbr_pl)
		{
			proc->live++;
			main->players[i]->ll_cycle = main->cur_cycle;
			/*if (main->cur_cycle >= 6074)
				dprintf(FD, "AFTER player[%d]->live_cur_per: %d\n", i, main->players[i]->live_cur_per);*/
			main->players[i]->live_cur_per = live_cur_per(main, main->lst_proc, main->players[i]->nbr_pl);
			/*if (main->cur_cycle >= 6074)
				dprintf(FD, "BEFORE player[%d]->live_cur_per: %d\n", i,  main->players[i]->live_cur_per);*/
			main->last_live_player = main->players[i];
		}
		i++;
	}
	proc->index = (proc->index + 5 ) % MEM_SIZE;
}