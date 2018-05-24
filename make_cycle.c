//
// Created by Kostiantyn MYKHAILENKO on 4/26/18.
//
# include "main.h"

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
 	while (*proc_list && (*proc_list)->live == 0)
 	{
 		tmp = *proc_list;
 		*proc_list = (*proc_list)->next;
 		main->nbr_proc--;
 		free(tmp);
 	}
 	buff = *proc_list;
 	while (buff && buff->next)
 	{
 		if (buff->next->live == 0)
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
		if (main->players[i]->live_cur_per >= NBR_LIVE && !check)
		{
			main->cl_to_die -= CYCLE_DELTA;
			main->cp_cl_to_die += (main->cl_to_die != U_INT) ? main->cl_to_die : 0;
			check = 1;
			main->mx_check = 0;
		}
		main->players[i]->live_last_per = main->players[i]->live_cur_per;
		main->players[i]->live_cur_per = 0;
		/*if (main->players[i]->live_cur_per >= NBR_LIVE)
		{
			main->players[i]->live_last_per = main->players[i]->live_cur_per;
			main->players[i]->live_cur_per = 0;
			check = 1;
			main->mx_check = 0;
		}
		else
		{
			main->players[i]->live_last_per = main->players[i]->live_cur_per;
			main->players[i]->live_cur_per = 0;
		}*/
		i++;
	}
	dprintf(FD, "CP_DIE: %d CL_DIE: %d\n", main->cp_cl_to_die, main->cl_to_die);
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
		main->cp_cur_cycle =  (main->cp_cur_cycle != main->cur_cycle) ? main->cur_cycle : main->cp_cur_cycle;
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
			ft_implement_command(main, head);
		head = head->next;
	}
	if (main->cp_cl_to_die == main->cur_cycle && (main->cl_to_die >= CYCLE_DELTA || main->cl_to_die == 36))
	{
		remove_proc(main, &(*proc));
		all_live_null(main, &(*proc));
		cycle_live_die(main, &(*proc));
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

