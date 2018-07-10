/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_sti_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 12:08:07 by ozharko           #+#    #+#             */
/*   Updated: 2018/05/22 12:08:09 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

static void		fun_sti_dir_dir_go(t_main *m, t_process *p, int r_1)
{
	short int	s;
	short int	t;
	int			step;
	int			tmp;

	m->ch = 1;
	s = (m->map[(p->index + 1 + 1 + 1) % MEM_SIZE]);
	s = s << 8;
	s = s | (m->map[(p->index + 1 + 1 + 1 + 1) % MEM_SIZE]);
	t = (m->map[(p->index + 1 + 1 + 1 + 1 + 1) % MEM_SIZE]);
	t = t << 8;
	t = t | (m->map[(p->index + 1 + 1 + 1 + 1 + 1 + 1) % MEM_SIZE]);
	step = p->index + ((s + t) % IDX_MOD);
	step = (step < 0) ? (MS + step) : step;
	tmp = p->rg[r_1];
	m->map[(step + 3) % MEM_SIZE] = tmp;
	tmp = tmp >> 8;
	m->map[(step + 2) % MEM_SIZE] = tmp;
	tmp = tmp >> 8;
	m->map[(step + 1) % MEM_SIZE] = tmp;
	tmp = tmp >> 8;
	m->map[(step + 0) % MEM_SIZE] = tmp;
	lst_newchanges(m, p, step % MEM_SIZE, (step + 3) % MEM_SIZE);
}

void			fun_sti_dir_dir(t_main *m, t_process *p)
{
	int			r_1;

	r_1 = m->map[(p->index + 1 + 1) % MEM_SIZE] - 1;
	if (r_1 < 0 || r_1 > 15)
	{
		unvalid_only_step(m, p);
		return ;
	}
	else
		fun_sti_dir_dir_go(m, p, r_1);
}

static int		fun_sti_ind_dir_second(t_main *m, t_process *p)
{
	int			s;
	short int	t;
	int			ind;

	t = (m->map[(p->index + 1 + 1 + 1) % MEM_SIZE]);
	t = t << 8;
	t = t | (m->map[(p->index + 1 + 1 + 1 + 1) % MEM_SIZE]);
	ind = p->index + t % IDX_MOD;
	ind = (ind < 0) ? (MS + ind) : ind;
	s = (m->map[(ind + 0) % MEM_SIZE]);
	s = s << 8;
	s = s | (m->map[(ind + 1) % MEM_SIZE]);
	s = s << 8;
	s = s | (m->map[(ind + 2) % MEM_SIZE]);
	s = s << 8;
	s = s | (m->map[(ind + 3) % MEM_SIZE]);
	t = (m->map[(p->index + 1 + 1 + 1 + 1 + 1) % MEM_SIZE]);
	t = t << 8;
	t = t | (m->map[(p->index + 1 + 1 + 1 + 1 + 1 + 1) % MEM_SIZE]);
	s = p->index + ((s + t) % IDX_MOD);
	s = (s < 0) ? (MS + s) : s;
	return (s);
}

void			fun_sti_ind_dir(t_main *m, t_process *p)
{
	int			s;
	int			r_1;
	int			tmp;

	m->ch = 1;
	r_1 = m->map[(p->index + 1 + 1) % MEM_SIZE] - 1;
	if (r_1 < 0 || r_1 > 15)
	{
		unvalid_only_step(m, p);
		return ;
	}
	s = fun_sti_ind_dir_second(m, p);
	tmp = p->rg[r_1];
	m->map[(s + 3) % MEM_SIZE] = tmp;
	tmp = tmp >> 8;
	m->map[(s + 2) % MEM_SIZE] = tmp;
	tmp = tmp >> 8;
	m->map[(s + 1) % MEM_SIZE] = tmp;
	tmp = tmp >> 8;
	m->map[(s + 0) % MEM_SIZE] = tmp;
	lst_newchanges(m, p, s % MEM_SIZE, (s + 3) % MEM_SIZE);
}
