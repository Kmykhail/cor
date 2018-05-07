//
// Created by Kostiantyn MYKHAILENKO on 4/26/18.
//
# include "main.h"

void	test_list(t_main *main, t_process *proc)
{
	t_process *tmp;

	tmp = proc;
	dprintf(FD, "___START___TEST_LIST____\n");
	dprintf(FD, "CUR_CYCLE:%d\n", main->cur_cycle);
	while (tmp)
	{
		dprintf(FD, "tmp->cmd_cycle:%d\n", tmp->cmd_cycle);
		dprintf(FD, "tmp->index:%d\n", tmp->index);
		dprintf(FD, "tmp->nbr_pl:%d\n", tmp->nbr_pl);
		dprintf(FD, "tmp->live:%d\n", tmp->live);
		dprintf(FD, "tmp->carry:%d\n", tmp->carry);
		dprintf(FD, "*************\n");
		tmp = tmp->next;
	}
	dprintf(FD, "___END__TEST__LIST\n\n");
}

void	remove_proc(t_main *main, t_process **proc_list)//ВСТАВИТЬ МУЗЫЧКУ УНИЧТОЖЕНИЕ ПРОЦЕССА
{
	t_process	*tmp;
	t_process	*buff;
	int			i;
	int			ch;	

	i = 0;
	ch = 0;
	if (*proc_list == NULL)
		return ;
	tmp = *proc_list;
	buff = *proc_list;
	while (tmp!= NULL)
	{
		if (!tmp->live)
		{
			while (ch < i)
			{
				if (ch == i - 1)
					buff->next = buff->next->next;
				buff = buff->next;
				ch++;
			}
			free(tmp);//LEAKS
			if (!ch)
			{
				buff = buff->next;
				*proc_list = buff;
			}	
		}
		tmp = tmp->next;
		i++;
	}
}

void	cycle_live_die(t_main *main, t_process **proc)
{
	int i;
	int check;
	t_process	*head;

	i = 0;
	check = 0;
	head = *proc;
	if (main->cur_cycle == 22725)
	dprintf(FD, "YYYY22725YYYY{3}\n");
	while (main->players[i])
	{
		if (main->players[i]->live_cur_per >= NBR_LIVE)
		{
			main->cl_to_die -= CYCLE_DELTA;
			main->cp_cl_to_die += main->cl_to_die;
			main->players[i]->live_last_per = main->players[i]->live_cur_per;
			main->players[i]->live_cur_per = 0;
			check = 1;
			main->mx_check = 0;
		}
		else
		{
			main->players[i]->live_last_per =  main->players[i]->live_cur_per;
			main->players[i]->live_cur_per = 0;
		}
		i++;
	}
	main->mx_check += (!check && main->mx_check != 10) ? 1 : 0;
	//main->cl_to_die -= (main->mx_check == MAX_CHECKS) ? CYCLE_DELTA : 0; 
	if (main->mx_check == MAX_CHECKS)
	{
		main->cl_to_die -= CYCLE_DELTA;
		main->cp_cl_to_die += main->cl_to_die;
		main->mx_check = 0;
	}
	while (head)
	{
		head->live = 0;
		head = head->next;
	}
}

int 	make_cycle_second(t_main *main, t_process **proc)
{
	t_process	*head;

	head = *proc;
    main->cur_cycle++;
	while (head)
	{
		head->cmd_cycle = (!head->cmd_cycle) ? main->label[main->map[head->index] - 1][2] : head->cmd_cycle;
		head->cmd_cycle--;
		if (main->map[head->index] >= 16) 
			ft_print_error(1);
		if (main->map[head->index] != 1 && main->map[head->index] != 12 \
		&& main->map[head->index] != 15 && main->map[head->index] != 16)
		{
			check_codage(main, main->map[head->index + 1]);
			ft_implement_command(main, head);
		}
		else if (main->map[head->index] == 1 || main->map[head->index] == 12 \
		|| main->map[head->index] == 15 || main->map[head->index] == 16)
			ft_implement_command(main, head);
		else
			head->index++;
		head = head->next;
	}
	if (main->cur_cycle == 22725)
	{
		dprintf(FD, "YYYY22725YYYY{1}\n");
		dprintf(FD, "Ymain->cur_cycle:%dY\n", main->cur_cycle);
		dprintf(FD, "Ymain->cp_cl_to_die:%dY\n", main->cp_cl_to_die);
		dprintf(FD, "Ymain->mx_check:%dY\n", main->mx_check);
		dprintf(FD, "Ymain->cl_to_die:%dY\n", main->cl_to_die);
		dprintf(FD, "YCYCLE_DELAT%dY\n", CYCLE_DELTA);
	}
	if (main->cp_cl_to_die == main->cur_cycle && main->cl_to_die >= CYCLE_DELTA)
	{
		if (main->cur_cycle == 22725)
		dprintf(FD, "YYYY22725YYYY{2}\n");
		remove_proc(main, &(*proc));
		cycle_live_die(main, &(*proc));
	}
	else if (main->cp_cl_to_die == main->cur_cycle && main->cl_to_die < CYCLE_DELTA)
	{
		//free_proc(main, proc);
		main->finish = 1;
	}
	return (1);
}

int     make_cycle(t_main *main)
{
	if (make_cycle_second(main, &main->lst_proc))
		return (1);
	else
		return (0);
}

