# include "main.h"

void	free_change(t_changes **del)//доделать
{
	free(&del);
}

t_process	*lst_newproc(t_main *main, int i)
{
	t_process	*new_proc;

	new_proc = (t_process*)malloc(sizeof(t_process));
	new_proc->index = (!ITR) ? main->coor_of_p[i] : STEP;
	new_proc->nbr_pl = (!ITR) ? main->players[i]->nbr_pl : main->players[0]->nbr_pl;//тест
	new_proc->live = 0;
	new_proc->next = NULL;
	return (new_proc);
}

void	lst_newchanges(t_main *main, t_process *proc, int i, int fin)
{
	ft_putstr_fd("GOOOD", 3);
	t_changes	*new_change;

	new_change = (t_changes*)malloc(sizeof(t_changes));
	new_change->start = (!ITR) ? main->coor_of_p[i] : main->coor_of_p[i];
	new_change->finish = (!ITR) ? fin : fin;
	new_change->cycle_init = (!ITR) ? 0 : 25;// 25 - количество циклов, у команды есть кол. циклов 
	new_change->process = proc;//??
	new_change->next = main->lst_changes;
	main->lst_changes = new_change;

	dprintf(FD, "new_change \n");
	dprintf(FD, "main->lst_changes->start %d\n", main->lst_changes->start);
	dprintf(FD, "main->lst_changes->finish %d\n", main->lst_changes->finish);
	dprintf(FD, "main->lst_changes->cycle_init %d\n", main->lst_changes->cycle_init);
	dprintf(FD, "main->lst_changes->process->nbr_pl %x\n", main->lst_changes->process->nbr_pl);
	dprintf(FD, "main->lst_changes->process->index %d\n", main->lst_changes->process->index);
	dprintf(FD, "main->lst_changes %p\n", main->lst_changes);
	dprintf(FD, "ITR%d\n", ITR);

	//free(new_change);
}

void	init_vizual(t_main *main, int i, int fin)
{
	//dprintf(FD, "ITR:%d\n", ITR);
	if (ITR)
	{
			dprintf(FD, "\n>>INDX: %d\n", main->lst_proc->index);
		/*while (main->lst_proc->next)
			main->lst_proc = main->lst_proc->next;*/
			main->lst_proc->index = STEP;
		//main->lst_changes->cycle_init = 25;

			dprintf(FD,"\n!!!INDX: %d\n", main->lst_proc->index);
			dprintf(FD,"\nLBR_pr: %x\n", main->lst_proc->nbr_pl);
		return ;
	}
	if (i)
	{
		dprintf(FD, "SDFSDFSDFSFSFSFSDF");
		while (main->lst_proc->next)
			main->lst_proc = main->lst_proc->next;
		main->lst_proc->next = lst_newproc(main, i);
		dprintf(FD, "main->lst_changes->start\n");
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

	main->lst_proc->index = main->coor_of_p[i];
	main->lst_proc->nbr_pl = main->players[i]->nbr_pl;
	main->lst_proc->live = 0;
	main->lst_proc->next = NULL;

	main->lst_changes->start =  main->coor_of_p[i];
	main->lst_changes->finish = fin;
	main->lst_changes->finish = fin;
	main->lst_changes->cycle_init = 1;
	main->lst_changes->process = main->lst_proc;
	main->lst_changes->next = NULL;
	dprintf(FD, ">>>>lst_changes->finish: %d<<<<<<\n", main->lst_changes->finish);
}