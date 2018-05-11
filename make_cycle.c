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
		dprintf(FD, "main->cur_cycle = %d\n", main->cur_cycle);
		dprintf(FD4, "before head->index = %d\n", head->index);
		dprintf(FD, "MC____01\n");
		dprintf(FD, "HEAD->INDEX:%d === head - %p\n", head->index, head);
		dprintf(FD, "cmd_cycle:%d\n", head->cmd_cycle);
		dprintf(FD, "_________main->label[%d][2]\n", main->map[head->index] - 1);
		dprintf(FD, "____main->label[%d][2] = %d\n", main->map[head->index] - 1, main->label[main->map[head->index] - 1][2]);
		head->cmd_cycle = (!head->cmd_cycle) ? main->label[main->map[head->index] - 1][2] : head->cmd_cycle;
		head->cmd_cycle--;
		dprintf(FD, "MC____1\n");
		if (main->map[head->index] >= 16) 
			ft_print_error(1);
		if (main->map[head->index] != 1 && main->map[head->index] != 12 \
		&& main->map[head->index] != 15 && main->map[head->index] != 16)
		{
			dprintf(FD, "MC____2\n");
			check_codage(main, main->map[head->index + 1]);
			ft_implement_command(main, head);
		}
		else if (main->map[head->index] == 1 || main->map[head->index] == 12 \
		|| main->map[head->index] == 15 || main->map[head->index] == 16)
		{
			ft_implement_command(main, head);
			dprintf(FD, "MC____3\n");
		}
		else
			head->index++;


		dprintf(FD, "MC____4\n");

		dprintf(FD, "head->next = %p\n", head->next);
		// dprintf(FD, "head->next->index = %d\n", head->next->index);
		head = head->next;
		dprintf(FD, "MC____44\n");
	}
	dprintf(FD, "MC_______4444\n");
	if (main->cp_cl_to_die == main->cur_cycle && (main->cl_to_die >= CYCLE_DELTA || main->cl_to_die == 36))
	{
		dprintf(FD, "MC____5\n");
		remove_proc(main, &(*proc));
		dprintf(FD, "MC____6\n");
		cycle_live_die(main, &(*proc));
		dprintf(FD, "MC____7\n");
	}
	if (main->cp_cl_to_die == main->cur_cycle && main->cl_to_die == U_INT)
	{
		dprintf(FD, "MC____8\n");
		main->finish = 1;
		main->cur_cycle++;
	}
	dprintf(FD, "MC____9\n");
	if (head)
		dprintf(FD4, "after head->index = %d\n", head->index);
	return (1);
}

int     make_cycle(t_main *main)
{
	if (make_cycle_second(main, &main->lst_proc))
		return (1);
	else
		return (0);
}

