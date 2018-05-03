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

void	fun_live(t_main *main, t_process *proc)
{
	dprintf(FD, "|||||||||LLLLLIIIIIVVVVVVEEEEEEE||||||||||||||||||||||\n");
	int i;

	i = 0;
	proc->live++;
	/*if (proc->nbr_pl == main->map[proc->index + 4])
	{
		main->last_live_player->
	}*/

	while (main->players[i] != NULL)
	{
		dprintf(FD, "i = %d\n", i);
		if (main->map[proc->index + 4] == main->players[i]->nbr_pl)
		{
			// dprintf(FD, "NAME_PL:%x\n", main->players[i]->nbr_pl)

			main->players[i]->ll_cycle = main->cur_cycle;

			main->players[i]->live_cur_per = 1;

			main->last_live_player = main->players[i];
		}
		i++;
	}
	dprintf(FD, ">>>>proc->index = %d\n", proc->index);
	proc->index += 5;
	dprintf(FD, " new proc->index = %d\n", proc->index);
}