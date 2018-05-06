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
	int 		num;
	short int	res;

	dprintf(FD, "______FORK____\n");
	i = 0;
	num = 2;
    k = 0;
    while (num--)
    {
        res = res << 8;
        res = res | main->map[proc->index + 1 + k];  // 0b 68 00 00 00 01
        k++;
    }
	new_proc = (t_process *)malloc(sizeof(t_process));
	while (i < 16)
	{
		k = 0;
		while (k < 4)
		{
			new_proc->rg[i][k] = proc->rg[i][k];
			k++;
		}
		i++;
	}
	new_proc->pc = proc->pc;
	new_proc->index = proc->index;
	new_proc->nbr_pl = proc->nbr_pl;
	new_proc->live = proc->live;
	new_proc->carry = proc->carry;
	new_proc->next = NULL;
	proc->index += 3;
	new_proc->index += res % IDX_MOD;
	new_proc->cmd_cycle = main->label[main->map[new_proc->index] - 1][2] + 1;
	while (proc->next)
		proc = proc->next;
	proc->next = new_proc;
	main->nbr_proc++;
}