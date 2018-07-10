/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_lfork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:51:07 by ozharko           #+#    #+#             */
/*   Updated: 2018/05/03 13:51:10 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

static	void	fun_lfork_go(t_main *main, t_process *proc, t_process *np)
{
	np->nbr_pl = proc->nbr_pl;
	np->live = proc->live;
	np->s_live = proc->s_live;
	np->carry = proc->carry;
	np->next = NULL;
	proc->index = (proc->index + 3) % MEM_SIZE;
	np->next = main->lst_proc;
	main->lst_proc = np;
	main->nbr_proc++;
}

void			fun_lfork(t_main *main, t_process *proc)
{
	t_process	*new_proc;
	int			i;
	short int	res;

	res = 0;
	res = res | main->map[(proc->index + 1) % MEM_SIZE];
	res = res << 8;
	res = res | main->map[(proc->index + 2) % MEM_SIZE];
	new_proc = (t_process *)malloc(sizeof(t_process));
	i = 0;
	while (i < 16)
	{
		new_proc->rg[i] = proc->rg[i];
		i++;
	}
	new_proc->index = (proc->index + res) % MEM_SIZE;
	if (new_proc->index < 0)
		new_proc->index = MEM_SIZE + new_proc->index;
	if (main->map[new_proc->index] >= 1 && main->map[new_proc->index] <= 16)
		new_proc->cmd_cycle = main->label[main->map[new_proc->index] - 1][2];
	else
		new_proc->cmd_cycle = 0;
	fun_lfork_go(main, proc, new_proc);
}
