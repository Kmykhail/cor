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
		main->lst_proc->rg[c][0] = (!c) ? -1 : 0;
		main->lst_proc->rg[c][1] = (!c) ? -1 : 0;
		main->lst_proc->rg[c][2] = (!c) ? -1 : 0;
		main->lst_proc->rg[c][3] = (!c) ? -1 : 0;
		c++;
	}
	new_proc->index = main->coor_of_p[pl_indx];
	new_proc->nbr_pl = main->players[pl_indx]->nbr_pl;//что кидать
	new_proc->live = 0;//
	new_proc->next = NULL;
	return (new_proc);
}

void	lst_newchanges(t_main *main, t_process *proc, int start, int fin)
{
	t_changes	*new_change;

	new_change = (t_changes*)malloc(sizeof(t_changes));
	new_change->start =  main->coor_of_p[start];
	new_change->finish = fin;
	new_change->cycle_init = main->cur_cycle;
	new_change->process = proc;
	//new_change->next = main->lst_changes;
	if (main->lst_changes)
		new_change->next = main->lst_changes;
	else
		new_change->next = NULL;
	main->lst_changes = new_change;
	/*dprintf(FD, "new_change \n");
	dprintf(FD, "main->lst_changes->start %d\n", main->lst_changes->start);
	dprintf(FD, "main->lst_changes->finish %d\n", main->lst_changes->finish);
	dprintf(FD, "main->lst_changes->cycle_init %d\n", main->lst_changes->cycle_init);
	dprintf(FD, "main->slst_changes->process->nbr_pl %x\n", main->lst_changes->process->nbr_pl);
	dprintf(FD, "main->lst_changes->process->index %d\n", main->lst_changes->process->index);
	dprintf(FD, "main->lst_changes %p\n", main->lst_changes);
	dprintf(FD, "ITR%d\n", ITR);*/

	//free(new_change);
}