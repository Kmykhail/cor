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
	int i;

	i = 0;
	proc->live++;
	proc->carry = 0;
	while (main->players[i] != NULL)
	{
		dprintf(FD, "i = %d\n", i);
		if (main->map[proc->index + 4] == main->players[i]->nbr_pl)
		{
			main->players[i]->ll_cycle = main->cur_cycle;

			main->players[i]->live_cur_per = 1;

			main->last_live_player = main->players[i];
		}
		i++;
	}
	proc->index += 5;
}