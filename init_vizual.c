# include "main.h"

void	init_vizual(t_main *main, int i, int fin)
{
	t_process	*tmp;
	int	c;

	c = 0;
	tmp = NULL;
	if (i)
	{
		tmp = main->lst_proc;
		while (main->lst_proc->next)
			main->lst_proc = main->lst_proc->next;
		main->lst_proc->next = lst_newproc(main, i);
		lst_newchanges(main, main->lst_proc->next, i, fin, 0);
		main->lst_proc = tmp;
		return ;
	}
	main->lst_proc = (t_process*)malloc(sizeof(t_process));
	main->lst_changes = (t_changes*)malloc(sizeof(t_changes));
	while (c < 16)
	{
		main->lst_proc->rg[c] = (!c) ? -1 : 0;
		c++;
	}
	main->lst_proc->rg[0] = -1;
	main->lst_proc->pc = 0;
	main->lst_proc->index = main->coor_of_p[i];
	main->lst_proc->cmd_cycle = main->label[main->map[main->lst_proc->index] - 1][2];
	main->lst_proc->nbr_pl = main->players[i]->nbr_pl;
	main->lst_proc->carry = 0;
	main->lst_proc->live = 0;
	main->lst_proc->next = NULL;

	main->lst_changes->start = main->coor_of_p[i];
	main->lst_changes->finish = fin;
	main->lst_changes->cycle_init = 1;
	main->lst_changes->nbr_pl = main->lst_proc->nbr_pl;
	main->lst_changes->next = NULL;
}