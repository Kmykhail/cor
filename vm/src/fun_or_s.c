/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_or_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 10:15:34 by ozharko           #+#    #+#             */
/*   Updated: 2018/05/22 10:15:36 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void			fun_or_dir_ind(t_main *m, t_process *p)
{
	int			r_3;
	short int	ind;

	r_3 = m->map[(p->index + 8) % MS] - 1;
	if (r_3 < 0 || r_3 > 15)
	{
		unvalid_only_step(m, p);
		return ;
	}
	ind = m->map[(p->index + 6) % MS];
	ind = ind << 8;
	ind = ind | m->map[(p->index + 7) % MS];
	ind = p->index + (ind % IDX_MOD);
	ind = (ind < 0) ? (MS + ind) : ind;
	p->rg[r_3] = m->map[(p->index + 2) % MS] | m->map[(ind + 0) % MS];
	p->rg[r_3] = p->rg[r_3] << 8;
	p->rg[r_3] |= (m->map[(p->index + 3) % MS] | m->map[(ind + 1) % MS]);
	p->rg[r_3] = p->rg[r_3] << 8;
	p->rg[r_3] |= (m->map[(p->index + 4) % MS] | m->map[(ind + 2) % MS]);
	p->rg[r_3] = p->rg[r_3] << 8;
	p->rg[r_3] |= (m->map[(p->index + 5) % MS] | m->map[(ind + 3) % MS]);
	p->carry = (p->rg[r_3]) ? 0 : 1;
	p->index = (p->index + STPC) % MS;
}

void			fun_or_ind_reg(t_main *m, t_process *p)
{
	int			r_2;
	int			r_3;
	short int	ind;

	r_2 = m->map[(p->index + 4) % MS] - 1;
	r_3 = m->map[(p->index + 5) % MS] - 1;
	if (r_2 < 0 || r_2 > 15 || r_3 < 0 || r_3 > 15)
	{
		unvalid_only_step(m, p);
		return ;
	}
	ind = m->map[(p->index + 2) % MS];
	ind = ind << 8;
	ind = ind | m->map[(p->index + 3) % MS];
	ind = p->index + (ind % IDX_MOD);
	ind = (ind < 0) ? (MS + ind) : ind;
	p->rg[r_3] = m->map[(ind + 0) % MS] | p->rg[r_2];
	p->rg[r_3] = p->rg[r_3] << 8;
	p->rg[r_3] |= (m->map[(ind + 1) % MS] | p->rg[r_2]);
	p->rg[r_3] = p->rg[r_3] << 8;
	p->rg[r_3] |= (m->map[(ind + 2) % MS] | p->rg[r_2]);
	p->rg[r_3] = p->rg[r_3] << 8;
	p->rg[r_3] |= (m->map[(ind + 3) % MS] | p->rg[r_2]);
	p->carry = (p->rg[r_3]) ? 0 : 1;
	p->index = (p->index + STPC) % MS;
}

void			fun_or_ind_dir(t_main *m, t_process *p)
{
	int			r_3;
	short int	ind;

	r_3 = m->map[(p->index + 8) % MS] - 1;
	if (r_3 < 0 || r_3 > 15)
	{
		unvalid_only_step(m, p);
		return ;
	}
	ind = m->map[(p->index + 2) % MS];
	ind = ind << 8;
	ind = ind | m->map[(p->index + 3) % MS];
	ind = p->index + (ind % IDX_MOD);
	ind = (ind < 0) ? (MS + ind) : ind;
	p->rg[r_3] = m->map[(ind + 0) % MS] | m->map[(p->index + 4) % MS];
	p->rg[r_3] = p->rg[r_3] << 8;
	p->rg[r_3] |= (m->map[(ind + 1) % MS] | m->map[(p->index + 5) % MS]);
	p->rg[r_3] = p->rg[r_3] << 8;
	p->rg[r_3] |= (m->map[(ind + 2) % MS] | m->map[(p->index + 6) % MS]);
	p->rg[r_3] = p->rg[r_3] << 8;
	p->rg[r_3] |= (m->map[(ind + 3) % MS] | m->map[(p->index + 7) % MS]);
	p->carry = (p->rg[r_3]) ? 0 : 1;
	p->index = (p->index + STPC) % MS;
}

static	void	fun_or_ind_ind_go(t_main *m, t_process *p, int r_3)
{
	short int	ind_1;
	short int	ind_2;

	ind_1 = m->map[(p->index + 2) % MS];
	ind_1 = ind_1 << 8;
	ind_1 = ind_1 | m->map[(p->index + 3) % MS];
	ind_1 = p->index + (ind_1 % IDX_MOD);
	ind_1 = (ind_1 < 0) ? (MS + ind_1) : ind_1;
	ind_2 = m->map[(p->index + 4) % MS];
	ind_2 = ind_2 << 8;
	ind_2 = ind_2 | m->map[(p->index + 5) % MS];
	ind_2 = p->index + (ind_2 % IDX_MOD);
	ind_2 = (ind_2 < 0) ? (MS + ind_2) : ind_2;
	p->rg[r_3] = m->map[(ind_1 + 0) % MS] | m->map[(ind_2 + 0) % MS];
	p->rg[r_3] = p->rg[r_3] << 8;
	p->rg[r_3] |= (m->map[(ind_1 + 1) % MS] | m->map[(ind_2 + 1) % MS]);
	p->rg[r_3] = p->rg[r_3] << 8;
	p->rg[r_3] |= (m->map[(ind_1 + 2) % MS] | m->map[(ind_2 + 2) % MS]);
	p->rg[r_3] = p->rg[r_3] << 8;
	p->rg[r_3] |= (m->map[(ind_1 + 3) % MS] | m->map[(ind_2 + 3) % MS]);
	p->carry = (p->rg[r_3]) ? 0 : 1;
	p->index = (p->index + STPC) % MS;
}

void			fun_or_ind_ind(t_main *m, t_process *p)
{
	int			r_3;

	r_3 = m->map[(p->index + 6) % MS] - 1;
	if (r_3 < 0 || r_3 > 15)
	{
		unvalid_only_step(m, p);
		return ;
	}
	else
		fun_or_ind_ind_go(m, p, r_3);
}
