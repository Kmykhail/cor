#include "main.h"

void	free_change(t_changes **del)//доделать
{
	free(&del);
}

t_process	*lst_newproc(t_main *main, int pl_indx)
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
	new_proc->rg[0] = -1;
	new_proc->pc = 0;
	new_proc->index = main->coor_of_p[pl_indx];
	new_proc->cmd_cycle = main->label[main->map[new_proc->index] - 1][2];
	new_proc->nbr_pl = main->players[pl_indx]->nbr_pl;
	new_proc->carry = 0;
	new_proc->live = 0;
	new_proc->next = NULL;
	new_proc->id = main->id;
	return (new_proc);
}

void	lst_newchanges(t_main *main, t_process *proc, int start, int fin, int ch)
{
	t_changes	*new_change;

	new_change = (t_changes*)malloc(sizeof(t_changes));

	//dprintf(FD, "@@@@main->map = %x\n", main->map[proc->index]);
	//dprintf(FD, "@@@@.   CH:%d @@@@.  start:%d @@@@.    main->coor_of_p[start]:%d\n", ch, start, main->coor_of_p[start]);

	new_change->start = (!ch) ? main->coor_of_p[start] : start;

	//dprintf(FD, "@@@@    new_change->start: %d\n", new_change->start);

	new_change->finish = fin;
	new_change->cycle_init = main->cur_cycle;
	new_change->nbr_pl = proc->nbr_pl;
	if (main->lst_changes)
		new_change->next = main->lst_changes;
	else
		new_change->next = NULL;
	main->lst_changes = new_change;
}