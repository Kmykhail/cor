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

#include "../inc/main.h"

unsigned int		live_cur_per(t_process *proc, uint8_t nbr_pl)
{
	unsigned int	res;

	res = 0;
	while (proc)
	{
		res += (proc->nbr_pl == nbr_pl) ? proc->live : 0;
		proc = proc->next;
	}
	return (res);
}

void				fun_live(t_main *main, t_process *proc)
{
	unsigned char	name;
	int				i;

	name = 0;
	i = 0;
	proc->s_live++;
	name |= main->map[(proc->index + 1) % MS];
	name = name << 8;
	name |= main->map[(proc->index + 2) % MS];
	name = name << 8;
	name |= main->map[(proc->index + 3) % MS];
	name = name << 8;
	name |= main->map[(proc->index + 4) % MS];
	while (main->players[i] != NULL)
	{
		if (name == main->players[i]->nbr_pl)
		{
			proc->live++;
			main->players[i]->ll_cycle = main->cur_cycle;
			main->players[i]->live_cur_per = LC;
			main->last_live_player = main->players[i];
		}
		i++;
	}
	proc->index = (proc->index + 5) % MEM_SIZE;
}
