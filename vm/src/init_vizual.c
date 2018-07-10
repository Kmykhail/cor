/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vizual.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:05:14 by kshyshki          #+#    #+#             */
/*   Updated: 2018/04/18 12:05:16 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

t_process		*lst_newproc(t_main *main, int pl_indx)
{
	t_process	*new_proc;
	int			c;

	c = 0;
	new_proc = (t_process*)malloc(sizeof(t_process));
	while (c < 16)
	{
		new_proc->rg[c] = 0;
		c++;
	}
	new_proc->rg[0] = pl_indx - ((pl_indx * 2) + 1);
	new_proc->pc = 0;
	new_proc->index = main->coor_of_p[pl_indx];
	new_proc->cmd_cycle = main->label[main->map[new_proc->index] - 1][2];
	new_proc->nbr_pl = main->players[pl_indx]->nbr_pl;
	new_proc->carry = 0;
	new_proc->live = 0;
	new_proc->s_live = 0;
	new_proc->id = main->count_id;
	new_proc->next = main->lst_proc;
	return (new_proc);
}

void			lst_newchanges(t_main *main, t_process *proc,
				int start, int fin)
{
	t_changes	*new_change;

	new_change = (t_changes*)malloc(sizeof(t_changes));
	new_change->start = (!main->ch) ? main->coor_of_p[start] : start;
	new_change->finish = fin;
	new_change->cycle_init = main->cur_cycle;
	new_change->nbr_pl = proc->nbr_pl;
	if (main->lst_changes)
		new_change->next = main->lst_changes;
	else
		new_change->next = NULL;
	main->lst_changes = new_change;
}

void			init_vizual_helper(t_main *main, int i)
{
	int c;

	c = -1;
	main->lst_proc = (t_process*)malloc(sizeof(t_process));
	while (c++ < 16)
		main->lst_proc->rg[c] = (!c) ? -1 : 0;
	main->lst_proc->rg[0] = -1;
	main->lst_proc->pc = 0;
	main->lst_proc->index = main->coor_of_p[i];
	main->lst_proc->cmd_cycle = main->label[MAP_BYTE - 1][2];
	main->lst_proc->nbr_pl = main->players[i]->nbr_pl;
	main->lst_proc->carry = 0;
	main->lst_proc->live = 0;
	main->lst_proc->s_live = 0;
	main->lst_proc->next = NULL;
}

void			init_vizual(t_main *main, int i, int fin)
{
	t_process	*tmp;

	tmp = NULL;
	if (i)
	{
		main->ch = 0;
		tmp = lst_newproc(main, i);
		lst_newchanges(main, tmp, i, fin);
		main->lst_proc = tmp;
		return ;
	}
	init_vizual_helper(main, i);
	main->lst_changes = (t_changes*)malloc(sizeof(t_changes));
	main->lst_changes->start = main->coor_of_p[i];
	main->lst_changes->finish = fin;
	main->lst_changes->cycle_init = 1;
	main->lst_changes->nbr_pl = main->lst_proc->nbr_pl;
	main->lst_changes->next = NULL;
}
