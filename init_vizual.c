# include "main.h"

void	init_vizual(t_main *main, int i, int fin)
{
	int	c;

	c = 0;
	if (i)
	{
		//dprintf(FD, "SDFSDFSDFSFSFSFSDF");
		while (main->lst_proc->next)
			main->lst_proc = main->lst_proc->next;
		main->lst_proc->next = lst_newproc(main, i);
		//dprintf(FD, "main->lst_changes->start\n");
		// dprintf(FD, "main->lst_changes->start %d", main->lst_changes->start);
		// dprintf(FD, "main->lst_changes->finish %d", main->l;st_changes->finish);
		// dprintf(FD, "main->lst_changes->cycle_init%d", main->lst_changes->cycle_init);
		// dprintf(FD, "main->lst_changes->next %d", main->lst_changes->next);
		// dprintf(FD, "main->lst_changes-> %d", main->lst_changes->start);
		//dprintf(FD, "\nGOOOD 1 \n");
		// dprintf(FD, "ADD %p", main->lst_changes);
		/*while (main->lst_changes->next)
		{
			// printf("main->lst_changes:%d  ", main->lst_changes->start);
			dprintf(FD, "NEXT\n");
			main->lst_changes = main->lst_changes->next;
		}*/
		lst_newchanges(main, main->lst_proc->next, i, fin);
		//dprintf(FD, "main->lst_changes->finish %d\n", main->lst_changes->finish);
		return ;
	}

	main->lst_proc = (t_process*)malloc(sizeof(t_process));
	main->lst_changes = (t_changes*)malloc(sizeof(t_changes));

	while (c < 16)
	{
		main->lst_proc->rg[c][0] = (!c) ? -1 : 0;
		main->lst_proc->rg[c][1] = (!c) ? -1 : 0;
		main->lst_proc->rg[c][2] = (!c) ? -1 : 0;
		main->lst_proc->rg[c][3] = (!c) ? -1 : 0;
		c++;
	}
	main->lst_proc->pc = 0;
	main->lst_proc->index = main->coor_of_p[i];
	main->lst_proc->nbr_pl = main->players[i]->nbr_pl;
	main->lst_proc->live = 0;
	main->lst_proc->next = NULL;

	main->lst_changes->start = main->coor_of_p[i];
	main->lst_changes->finish = fin;
	main->lst_changes->finish = fin;
	main->lst_changes->cycle_init = 1;
	main->lst_changes->process = main->lst_proc;
	main->lst_changes->next = NULL;
	dprintf(FD, "ADDRSS1 %p\n", main->lst_changes);
	dprintf(FD, ">>>>lst_changes->finish: %d<<<<<<\n", main->lst_changes->finish);
}