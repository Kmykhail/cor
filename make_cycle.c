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
	dprintf(FD, "cp_cl_to_die:%d", main->cp_cl_to_die);
	dprintf(FD, "cl_to_die;%d", main->cl_to_die);
	dprintf(FD, "mx_check:%d", main->mx_check);
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
	// int			i;
	// int			ch;	

	// i = 0;
	// ch = 0;
	// if (proc_list == NULL || *proc_list == NULL)
	// 	return ;
	// tmp = *proc_list;
	// while (tmp != NULL)
	// {
	// 	if (!tmp->live)//==0
	// 	{
	// 		while (ch < i)
	// 		{
	// 			if (ch == i - 1)
	// 				buff->next = buff->next->next;
	// 			buff = buff->next;
	// 			ch++;
	// 			main->nbr_proc--;
	// 		}
	// 		if (!ch)
	// 		{
	// 			buff = tmp->next;
	// 			free(tmp);
	// 			tmp = buff;
	// 			*proc_list = buff;
	// 			main->nbr_proc--;
	// 		}
	// 		ch = 0;
	// 	}
	// 	tmp = tmp->next;
	// 	i++;
	// }

	if (proc_list == NULL || *proc_list == NULL)
		return ;
	tmp = *proc_list;
	if ((*proc_list)->live == 0)
	{
		*proc_list = (*proc_list)->next;
		free(tmp);
		main->nbr_proc--;
		return;
	}
	while (tmp->next != NULL)
	{
		if (tmp->next->live == 0)
		{
			buff = tmp->next;
			tmp->next = tmp->next->next;
			free(buff);
			main->nbr_proc--;			
		}
		else
			tmp = tmp->next;
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
	while (main->players[i])
	{
		if (main->players[i]->live_cur_per >= NBR_LIVE)
		{
			main->cl_to_die -= CYCLE_DELTA;
			main->cp_cl_to_die += (main->cl_to_die != U_INT) ? main->cl_to_die : 0;
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
	if (!check && main->mx_check < MAX_CHECKS)
	{
		main->mx_check += 1;
		main->cp_cl_to_die += (main->mx_check != MAX_CHECKS) ? main->cl_to_die : 0;
	}
	if (main->mx_check == MAX_CHECKS)
	{
		main->cl_to_die -= CYCLE_DELTA;
		main->cp_cl_to_die += (main->cl_to_die != U_INT) ? main->cl_to_die : 0;
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
		if (main->cur_cycle == 3555)
		{
			dprintf(FD, "{head->cmd_cycle: %d head->index: %d}\n", head->cmd_cycle, head->index);
		}
		head->cmd_cycle = (head->cmd_cycle < 0) ? main->label[main->map[head->index] - 1][2] : head->cmd_cycle;
		//head->cmd_cycle--;
		if (main->map[head->index] != 1 && main->map[head->index] != 12 \
		&& main->map[head->index] != 15 && main->map[head->index] != 16)
		{
			dprintf(FD, "head->c^md_cycle: %d\n", head->cmd_cycle);
			check_codage(main, main->map[head->index + 1]);
			ft_implement_command(main, head);
			head->cmd_cycle--;
			//exit(1);
		}
		else if (main->map[head->index] == 1 || main->map[head->index] == 12 \
		|| main->map[head->index] == 15 || main->map[head->index] == 16)
		{
			/*printf("asdadad\n");
			exit(1);*/
			ft_implement_command(main, head);
			head->cmd_cycle--;
		}
		else
		{
			ft_implement_command(main, head);
			head->index++;
		}
		
		head = head->next;
	}
	if (main->cp_cl_to_die == main->cur_cycle && (main->cl_to_die >= CYCLE_DELTA || main->cl_to_die == 36))
	{
		remove_proc(main, &(*proc));
		cycle_live_die(main, &(*proc));
	}
	if (main->cp_cl_to_die == main->cur_cycle && main->cl_to_die == U_INT)
	{
		main->finish = 1;
		main->cur_cycle++;
	}
	dprintf(FD4, "main->cur_cycle = %d\n", main->cur_cycle - 1);
    // test_show_me_label_arg(main, *proc);
	return (1);
}

int     make_cycle(t_main *main)
{
	if (make_cycle_second(main, &main->lst_proc))
		return (1);
	else
		return (0);
}

