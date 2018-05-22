//
// Created by Kostiantyn MYKHAILENKO on 4/26/18.
//
# include "main.h"

void	test_list(t_main *main, t_process *proc)
{
	t_process *tmp;

	tmp = proc;
	while (tmp)
	{
		dprintf(FD, "tmp->cmd_cycle:%d\n", tmp->cmd_cycle);
		dprintf(FD, "tmp->index:%d\n", tmp->index);
		dprintf(FD, "tmp->nbr_pl:%d\n", tmp->nbr_pl);
		dprintf(FD, "tmp->live:%d\n", tmp->live);
		dprintf(FD, "tmp->s_live:%d\n", tmp->live);
		dprintf(FD, "tmp->carry:%d\n", tmp->carry);
		dprintf(FD, "tmp->id:%d\n", tmp->id);
		dprintf(FD, "players->live_cur_per: %d\n", main->players[0]->live_cur_per);
		dprintf(FD, "*************\n");
		tmp = tmp->next;
	}
	dprintf(FD, "___END__TEST__LIST\n\n");
}

// void	remove_proc(t_main *main, t_process **proc_list)//ВСТАВИТЬ МУЗЫЧКУ УНИЧТОЖЕНИЕ ПРОЦЕССА
// {
// 	t_process	*tmp;
// 	t_process	*buff;

// 	if (proc_list == NULL || *proc_list == NULL)
// 		return ;
// 	tmp = *proc_list;
// 	if ((*proc_list)->live == 0)
// 	{
// 		*proc_list = (*proc_list)->next;
// 		free(tmp);
// 		main->nbr_proc--;
// 		return;
// 	}
// 	while (tmp->next != NULL)
// 	{
// 		if (tmp->next->live == 0)
// 		{
// 			buff = tmp->next;
// 			tmp->next = tmp->next->next;
// 			free(buff);
// 			main->nbr_proc--;			
// 		}
// 		else
// 			tmp = tmp->next;
// 	}
// }

void	all_live_null(t_main *main, t_process **proc_list)
{
	t_process	*tmp;

	if (proc_list == NULL || *proc_list == NULL)
 		return ;
 	tmp = *proc_list;
 	while (tmp)
 	{
 		tmp->s_live = 0;
 		tmp->live = 0;
 		tmp = tmp->next;
 	}
}

void	remove_proc(t_main *main, t_process **proc_list)
 {
 	t_process	*tmp;
 	t_process	*buff;
 
  	if (proc_list == NULL || *proc_list == NULL)
 		return ;
 	while (*proc_list && (*proc_list)->s_live == 0)
 	{
 		tmp = *proc_list;
 		*proc_list = (*proc_list)->next;
 		main->nbr_proc--;
 		free(tmp);
 	}
 	buff = *proc_list;
 	while (buff && buff->next)
 	{
 		if (buff->next->s_live == 0)
 		{
 			tmp = buff->next;
 			buff->next = tmp->next;
 			main->nbr_proc--;
 			free(tmp);
 		}
 		if (buff->next)
 			buff = buff->next;
 	}
 }
void	delet_all_proc(t_main *main, t_process **proc_list)
{
	t_process	*tmp;
	t_process	*buff;

	if (proc_list == NULL || *proc_list == NULL)
 		return ;
 	tmp = *proc_list;
 	while (tmp)
 	{
 		buff = tmp->next;
 		free(tmp);
 		tmp = NULL;
 		tmp = buff;
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
			main->players[i]->live_last_per = main->players[i]->live_cur_per;
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
		if (main->map[head->index] > 0  && main->map[head->index] < 16)
			head->cmd_cycle = (head->cmd_cycle < 0) ? main->label[main->map[head->index] - 1][2] : head->cmd_cycle;
		else if (main->map[head->index] == 0)
			(main->map[head->index] == 0) ? head->cmd_cycle -= 1 : 0;
		if (main->map[head->index] != 1 && main->map[head->index] != 12 \
		&& main->map[head->index] != 15 && main->map[head->index] != 16 && main->map[head->index] != 0)
		{
			check_codage(main, main->map[head->index + 1]);
			ft_implement_command(main, head);
			head->cmd_cycle--;
		}
		else if ((main->map[head->index] == 1 || main->map[head->index] == 12 \
		|| main->map[head->index] == 15 || main->map[head->index] == 16) && main->map[head->index] != 0)
		{
			ft_implement_command(main, head);
			head->cmd_cycle--;
		}
		else if (main->map[head->index] == 0 && head->cmd_cycle + 1 < 0)
		{
			ft_implement_command(main, head);
		}
		head = head->next;
	}
	if (main->cp_cl_to_die == main->cur_cycle && (main->cl_to_die >= CYCLE_DELTA || main->cl_to_die == 36))
	{
		if (main->cur_cycle >= 39000)
		{
			dprintf(FD, "BEFORE\n");
			test_list(main, *proc);
		}
		remove_proc(main, &(*proc));
		// if (main->nbr_proc < 3 && main->cur_cycle > 1536)
		// {
		// 	printf("CC:%d\n", main->cur_cycle);
		// 	exit(1);
		// }
		if (main->cur_cycle >= 39000)
		{
			dprintf(FD, "AFTER\n");
			test_list(main, *proc);
		}
		all_live_null(main, &(*proc));
		cycle_live_die(main, &(*proc));
		test_list(main, *proc);
	}
	if (main->cp_cl_to_die == main->cur_cycle && main->cl_to_die == U_INT)
	{
		main->finish = 1;
		main->nbr_proc = 0;
		main->cur_cycle++;
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

