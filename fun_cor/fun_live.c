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

uint8_t		live_cur_per(t_main *main, t_process *proc, uint8_t nbr_pl)
{
	uint8_t		res;

	res = 0;
	while (proc)
	{
		res += (proc->nbr_pl == nbr_pl) ? proc->live : 0;
		proc = proc->next;
	}
	return (res);
}

void	fun_live(t_main *main, t_process *proc)
{
	int i;

	i = 0;
	proc->live++;
	while (main->players[i] != NULL)
	{
		if (main->map[ ( proc->index + 4 ) % MEM_SIZE ] == main->players[i]->nbr_pl)
		{
			main->players[i]->ll_cycle = main->cur_cycle;

			main->players[i]->live_cur_per = live_cur_per(main, main->lst_proc, main->players[i]->nbr_pl);

			main->last_live_player = main->players[i];
		}
		i++;
	}
	proc->index += 5;

}