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
	t_changes	*new_change;

	new_change = (t_changes*)malloc(sizeof(t_changes));
	new_change->start = (!ITR) ? main->coor_of_p[i] : main->lst_changes->start;
	new_change->finish = (!ITR) ? fin : main->lst_changes->finish;
	new_change->cycle_init = (!ITR) ? 0 : 25;// 25 - количество циклов, у команды есть кол. циклов 
	new_change->process = proc;//??
	new_change->next = main->lst_changes;
	main->lst_changes = new_change;
	//free(new_change);
}

void	init_vizual(t_main *main, int i, int fin)
{
	if (i)
	{
		while (main->lst_proc->next)
			main->lst_proc = main->lst_proc->next;
		main->lst_proc->next = lst_newproc(main, i);
		while (main->lst_changes->next)
			main->lst_changes = main->lst_changes->next;
		lst_newchanges(main, main->lst_proc->next, i, fin);
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
	main->lst_changes->cycle_init = 0;
	main->lst_changes->process = main->lst_proc;
	main->lst_changes->next = NULL;
}