/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_sti_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 12:07:58 by ozharko           #+#    #+#             */
/*   Updated: 2018/05/22 12:08:00 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

static void		fun_sti_dir_reg_go(t_main *m, t_process *p, int r_1, int r_2)
{
	short int	s;
	int			step;
	int			tmp;

	m->ch = 1;
	s = m->map[(p->index + 1 + 1 + 1) % MEM_SIZE];
	s = s << 8;
	s = s | (m->map[(p->index + 1 + 1 + 1 + 1) % MEM_SIZE]);
	step = p->index + ((s + p->rg[r_2]) % IDX_MOD);
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

void			fun_sti_dir_reg(t_main *m, t_process *p)
{
	int			r_1;
	int			r_2;

	r_1 = m->map[(p->index + 1 + 1) % MEM_SIZE] - 1;
	r_2 = m->map[(p->index + 1 + 1 + 2 + 1) % MEM_SIZE] - 1;
	if (r_1 < 0 || r_1 > 15 || r_2 < 0 || r_2 > 15)
	{
		unvalid_only_step(m, p);
		return ;
	}
	else
		fun_sti_dir_reg_go(m, p, r_1, r_2);
}

static int		fun_sti_ind_reg_second(t_main *m, t_process *p, int r_2)
{
	short int	c_s;
	int			step;
	int			tmp;

	c_s = (m->map[(p->index + 1 + 1 + 1) % MEM_SIZE]);
	c_s = c_s << 8;
	c_s = c_s | (m->map[(p->index + 1 + 1 + 1 + 1) % MEM_SIZE]);
	step = p->index + c_s % IDX_MOD;
	step = (step < 0) ? (MS + step) : step;
	tmp = (m->map[(step + 0) % MEM_SIZE]);
	tmp = tmp << 8;
	tmp = tmp | (m->map[(step + 1) % MEM_SIZE]);
	tmp = tmp << 8;
	tmp = tmp | (m->map[(step + 2) % MEM_SIZE]);
	tmp = tmp << 8;
	tmp = tmp | (m->map[(step + 3) % MEM_SIZE]);
	step = p->index + ((tmp + p->rg[r_2]) % IDX_MOD);
	step = (step < 0) ? (MS + step) : step;
	return (step);
}

void			fun_sti_ind_reg(t_main *m, t_process *p)
{
	int			r_1;
	int			r_2;
	int			step;
	int			tmp;

	m->ch = 1;
	r_1 = m->map[(p->index + 1 + 1) % MEM_SIZE] - 1;
	r_2 = m->map[(p->index + 1 + 1 + 2 + 1) % MEM_SIZE] - 1;
	if (r_1 < 0 || r_1 > 15 || r_2 < 0 || r_2 > 15)
	{
		unvalid_only_step(m, p);
		return ;
	}
	step = fun_sti_ind_reg_second(m, p, r_2);
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
