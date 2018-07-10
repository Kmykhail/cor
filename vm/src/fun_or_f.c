/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_or_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 10:15:28 by ozharko           #+#    #+#             */
/*   Updated: 2018/05/22 10:15:29 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	fun_or_reg_reg(t_main *m, t_process *p)
{
	int			r_1;
	int			r_2;
	int			r_3;

	r_1 = m->map[(p->index + 2) % MS] - 1;
	r_2 = m->map[(p->index + 3) % MS] - 1;
	r_3 = m->map[(p->index + 4) % MS] - 1;
	if (r_1 < 0 || r_1 > 15 || r_2 < 0 || r_2 > 15 || r_3 < 0 || r_3 > 15)
	{
		unvalid_only_step(m, p);
		return ;
	}
	p->rg[r_3] = p->rg[r_1] | p->rg[r_2];
	p->carry = (p->rg[r_3]) ? 0 : 1;
	p->index = (p->index + STPC) % MS;
}

void	fun_or_reg_dir(t_main *m, t_process *p)
{
	int			r_1;
	int			r_3;

	r_1 = m->map[(p->index + 2) % MS] - 1;
	r_3 = m->map[(p->index + 7) % MS] - 1;
	if (r_1 < 0 || r_1 > 15 || r_3 < 0 || r_3 > 15)
	{
		unvalid_only_step(m, p);
		return ;
	}
	p->rg[r_3] = p->rg[r_1] | m->map[(p->index + 3) % MS];
	p->rg[r_3] = p->rg[r_3] << 8;
	p->rg[r_3] |= (p->rg[r_1] | m->map[(p->index + 4) % MS]);
	p->rg[r_3] = p->rg[r_3] << 8;
	p->rg[r_3] |= (p->rg[r_1] | m->map[(p->index + 5) % MS]);
	p->rg[r_3] = p->rg[r_3] << 8;
	p->rg[r_3] |= (p->rg[r_1] | m->map[(p->index + 6) % MS]);
	p->carry = (p->rg[r_3]) ? 0 : 1;
	p->index = (p->index + STPC) % MS;
}

void	fun_or_reg_ind(t_main *m, t_process *p)
{
	int			r_1;
	int			r_3;
	short int	ind;

	r_1 = m->map[(p->index + 2) % MS] - 1;
	r_3 = m->map[(p->index + 5) % MS] - 1;
	if (r_1 < 0 || r_1 > 15 || r_3 < 0 || r_3 > 15)
	{
		unvalid_only_step(m, p);
		return ;
	}
	ind = m->map[(p->index + 3) % MS];
	ind = ind << 8;
	ind = ind | m->map[(p->index + 4) % MS];
	ind = p->index + (ind % IDX_MOD);
	ind = (ind < 0) ? (MS + ind) : ind;
	p->rg[r_3] = p->rg[r_1] | m->map[(ind + 0) % MS];
	p->rg[r_3] = p->rg[r_3] << 8;
	p->rg[r_3] |= (p->rg[r_1] | m->map[(ind + 1) % MS]);
	p->rg[r_3] = p->rg[r_3] << 8;
	p->rg[r_3] |= (p->rg[r_1] | m->map[(ind + 2) % MS]);
	p->rg[r_3] = p->rg[r_3] << 8;
	p->rg[r_3] |= (p->rg[r_1] | m->map[(ind + 3) % MS]);
	p->carry = (p->rg[r_3]) ? 0 : 1;
	p->index = (p->index + STPC) % MS;
}

void	fun_or_dir_reg(t_main *m, t_process *p)
{
	int			r_2;
	int			r_3;

	r_2 = m->map[(p->index + 6) % MS] - 1;
	r_3 = m->map[(p->index + 7) % MS] - 1;
	if (r_2 < 0 || r_2 > 15 || r_3 < 0 || r_3 > 15)
	{
		unvalid_only_step(m, p);
		return ;
	}
	p->rg[r_3] = m->map[(p->index + 2) % MS] | p->rg[r_2];
	p->rg[r_3] = p->rg[r_3] << 8;
	p->rg[r_3] |= (m->map[(p->index + 3) % MS] | p->rg[r_2]);
	p->rg[r_3] = p->rg[r_3] << 8;
	p->rg[r_3] |= (m->map[(p->index + 4) % MS] | p->rg[r_2]);
	p->rg[r_3] = p->rg[r_3] << 8;
	p->rg[r_3] |= (m->map[(p->index + 5) % MS] | p->rg[r_2]);
	p->carry = (p->rg[r_3]) ? 0 : 1;
	p->index = (p->index + STPC) % MS;
}

void	fun_or_dir_dir(t_main *m, t_process *p)
{
	int			r_3;

	r_3 = m->map[(p->index + 10) % MS] - 1;
	if (r_3 < 0 || r_3 > 15)
	{
		unvalid_only_step(m, p);
		return ;
	}
	p->rg[r_3] = m->map[(p->index + 2) % MS] | m->map[(p->index + 6) % MS];
	p->rg[r_3] = p->rg[r_3] << 8;
	p->rg[r_3] |= (m->map[(p->index + 3) % MS] | m->map[(p->index + 7) % MS]);
	p->rg[r_3] = p->rg[r_3] << 8;
	p->rg[r_3] |= (m->map[(p->index + 4) % MS] | m->map[(p->index + 8) % MS]);
	p->rg[r_3] = p->rg[r_3] << 8;
	p->rg[r_3] |= (m->map[(p->index + 5) % MS] | m->map[(p->index + 9) % MS]);
	p->carry = (p->rg[r_3]) ? 0 : 1;
	p->index = (p->index + STPC) % MS;
}
