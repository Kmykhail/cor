/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:05:14 by kshyshki          #+#    #+#             */
/*   Updated: 2018/04/18 12:05:16 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

static void		remove_proc(t_main *main, t_process **proc_list)
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

static void		check_max_checks(t_main *m, int check)
{
	if (!check && m->mx_check < MAX_CHECKS)
	{
		m->mx_check += 1;
		m->cp_cl_to_die += (m->mx_check != MAX_CHECKS) ? m->cl_to_die : 0;
	}
	if (m->mx_check == MAX_CHECKS)
	{
		m->cl_to_die -= CYCLE_DELTA;
		m->cp_cl_to_die += (m->cl_to_die != U_INT) ? m->cl_to_die : 0;
		m->mx_check = 0;
	}
}

static void		cycle_live_die(t_main *m, t_process **proc, int check)
{
	int			i;
	t_process	*head;

	i = 0;
	head = *proc;
	while (m->players[i])
	{
		if (m->players[i]->live_cur_per >= NBR_LIVE && !check)
		{
			m->cl_to_die -= CYCLE_DELTA;
			m->cp_cl_to_die += (m->cl_to_die != U_INT) ? m->cl_to_die : 0;
			check = 1;
			m->mx_check = 0;
		}
		m->players[i]->live_last_per = m->players[i]->live_cur_per;
		m->players[i++]->live_cur_per = 0;
	}
	check_max_checks(m, check);
	while (head)
	{
		head->live = 0;
		head->s_live = 0;
		head = head->next;
	}
}

static void		execute_byte_code(t_main *m, t_process *h)
{
	if (m->map[h->index] != 1 && m->map[h->index] != 12 \
	&& m->map[h->index] != 15 && m->map[h->index] != 16 \
	&& m->map[h->index] != 0)
	{
		check_codage(m, m->map[h->index + 1]);
		ft_implement_command(m, h);
		h->cmd_cycle--;
	}
	else if ((m->map[h->index] == 1 || m->map[h->index] == 12 \
	|| m->map[h->index] == 15 || m->map[h->index] == 16) \
	&& m->map[h->index] != 0)
	{
		ft_implement_command(m, h);
		h->cmd_cycle--;
	}
	else if (m->map[h->index] == 0 && h->cmd_cycle + 1 < 0)
		ft_implement_command(m, h);
}

int				make_cycle_second(t_main *m, t_process **proc)
{
	t_process	*head;

	head = *proc;
	m->cur_cycle++;
	while (head)
	{
		if (m->map[head->index] > 0 && m->map[head->index] < 16)
			head->cmd_cycle = (head->cmd_cycle < 0) ? \
			m->label[m->map[head->index] - 1][2] : head->cmd_cycle;
		else if (m->map[head->index] == 0)
			(m->map[head->index] == 0) ? head->cmd_cycle -= 1 : 0;
		execute_byte_code(m, head);
		head = head->next;
	}
	if (m->cp_cl_to_die == m->cur_cycle && (m->cl_to_die >= CYCLE_DELTA \
	|| m->cl_to_die == 36))
	{
		remove_proc(m, &(*proc));
		cycle_live_die(m, &(*proc), 0);
	}
	return (1);
}
