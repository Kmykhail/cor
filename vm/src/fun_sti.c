/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_sti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:51:00 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/24 15:51:02 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

static	void	fun_sti_reg_reg(t_main *m, t_process *p)
{
	int			r_1;
	int			r_2;
	int			r_3;
	int			step;
	int			tmp;

	r_1 = m->map[(p->index + 1 + 1) % MEM_SIZE] - 1;
	r_2 = m->map[(p->index + 1 + 1 + 1) % MEM_SIZE] - 1;
	r_3 = m->map[(p->index + 1 + 1 + 1 + 1) % MEM_SIZE] - 1;
	if (r_1 < 0 || r_1 > 15 || r_2 < 0 || r_2 > 15 || r_3 < 0 || r_3 > 15)
	{
		unvalid_only_step(m, p);
		return ;
	}
	step = p->index + ((p->rg[r_2] + p->rg[r_3]) % IDX_MOD);
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

static void		fun_sti_reg_dir_go(t_main *m, t_process *p, int r_1, int r_2)
{
	short int	t;
	int			step;
	int			tmp;

	t = (m->map[(p->index + 1 + 1 + 1 + 1) % MEM_SIZE]);
	t = t << 8;
	t = t | (m->map[(p->index + 1 + 1 + 1 + 1 + 1) % MEM_SIZE]);
	step = p->index + ((p->rg[r_2] + t) % IDX_MOD);
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

static void		fun_sti_reg_dir(t_main *m, t_process *p)
{
	int			r_1;
	int			r_2;

	r_1 = m->map[(p->index + 1 + 1) % MEM_SIZE] - 1;
	r_2 = m->map[(p->index + 1 + 1 + 1) % MEM_SIZE] - 1;
	if (r_1 < 0 || r_1 > 15 || r_2 < 0 || r_2 > 15)
	{
		unvalid_only_step(m, p);
		return ;
	}
	else
		fun_sti_reg_dir_go(m, p, r_1, r_2);
}

void			fun_sti(t_main *m, t_process *p)
{
	m->ch = 1;
	if (m->arg[0] == 1 && m->arg[1] == 1 && m->arg[2] == 1)
		fun_sti_reg_reg(m, p);
	else if (m->arg[0] == 1 && m->arg[1] == 1 && m->arg[2] == 2)
		fun_sti_reg_dir(m, p);
	else if (m->arg[0] == 1 && m->arg[1] == 2 && m->arg[2] == 1)
		fun_sti_dir_reg(m, p);
	else if (m->arg[0] == 1 && m->arg[1] == 2 && m->arg[2] == 2)
		fun_sti_dir_dir(m, p);
	else if (m->arg[0] == 1 && m->arg[1] == 3 && m->arg[2] == 1)
		fun_sti_ind_reg(m, p);
	else if (m->arg[0] == 1 && m->arg[1] == 3 && m->arg[2] == 2)
		fun_sti_ind_dir(m, p);
	else
	{
		unvalid_only_step(m, p);
		return ;
	}
	p->index = (p->index + STPC) % MEM_SIZE;
}
