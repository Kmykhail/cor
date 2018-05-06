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
	dprintf(FD, "FUN FORK _______________________________\n");
	t_process	*new_proc;
	int			i;
	int			k;
	int 		num;
	short int	res;

	i = 0;
	num = 2;
    k = 0;
   	if (main->tmp_fork && main->tmp_fork + 800 != main->cmd_cycle)
   	{
   		dprintf(FD, "MAIN->CMD:%d TMP_FORK:%d\n", main->cmd_cycle, main->tmp_fork);
   		return ;
   	}
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
	dprintf(FD, "proc->pc:%d\n", proc->pc);
	dprintf(FD, "proc->index:%d\n", proc->index);
	dprintf(FD, "proc->nbr_pl:%x\n", proc->nbr_pl);
	dprintf(FD, "proc->live:%x\n", proc->live);
	dprintf(FD, "proc->live:%x\n", proc->live);
	dprintf(FD, "______________________________\n");
	new_proc->pc = proc->pc;
	new_proc->index = proc->index;
	new_proc->nbr_pl = proc->nbr_pl;
	new_proc->live = proc->live;
	new_proc->next = NULL;
	proc->index += 3;
	new_proc->index += res % IDX_MOD;
	new_proc->cmd_cycle = main->label[main->map[new_proc->index] - 1][2] + 1;
	dprintf(FD, "new_proc->pc:%d\n", new_proc->pc);
	dprintf(FD, "new_proc->index:%d\n", new_proc->index);
	dprintf(FD, "new_proc->cmd_cycle:%d\n", new_proc->cmd_cycle);
	dprintf(FD, "new_proc->nbr_pl:%x\n", new_proc->nbr_pl);
	dprintf(FD, "new_proc->live:%x\n", new_proc->live);
	dprintf(FD, "new_proc->live:%x\n", new_proc->live);
	dprintf(FD, "___________________________________\n");
	while (proc->next)
		proc = proc->next;
	proc->next = new_proc;
	main->nbr_proc++;
}