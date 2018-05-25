/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_lldi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:50:04 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/24 19:50:06 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

static	void	fun_lldi_ind_reg_go(t_main *m, t_process *p, int r_2, int r_3)
{
	short int	ind;
	int			d_1;
	int			d_2;

	ind = m->map[(p->index + 1 + 1) % MS] << 8;
	ind = ind | m->map[(p->index + 1 + 1 + 1) % MS];
	ind = p->index + ind % IDX_MOD;
	ind = (ind < 0) ? (MS + ind) : ind;
	d_1 = m->map[(ind + 0) % MS] << 8;
	d_1 = d_1 | m->map[(ind + 1) % MS];
	d_1 = d_1 << 8;
	d_1 = d_1 | m->map[(ind + 2) % MS];
	d_1 = d_1 << 8;
	d_1 = d_1 | m->map[(ind + 3) % MS];
	d_2 = p->rg[r_2];
	p->rg[r_3] = m->map[(d_1 + d_2 + p->index + 0) % MS];
	p->rg[r_3] = p->rg[r_3] << 8;
	p->rg[r_3] |= m->map[(d_1 + d_2 + p->index + 1) % MS];
	p->rg[r_3] = p->rg[r_3] << 8;
	p->rg[r_3] |= m->map[(d_1 + d_2 + p->index + 2) % MS];
	p->rg[r_3] = p->rg[r_3] << 8;
	p->rg[r_3] |= m->map[(d_1 + d_2 + p->index + 3) % MS];
	p->carry = (p->rg[r_3]) ? 0 : 1;
	p->index = (p->index + STPC) % MS;
}

static	void	fun_lldi_ind_reg(t_main *m, t_process *p)
{
	int			r_2;
	int			r_3;

	r_2 = m->map[(p->index + 1 + 2 + 1) % MS] - 1;
	r_3 = m->map[(p->index + 1 + 2 + 1 + 1) % MS] - 1;
	if (r_2 < 0 || r_2 > 15 || r_3 < 0 || r_3 > 15)
	{
		unvalid_only_step(m, p);
		return ;
	}
	else
		fun_lldi_ind_reg_go(m, p, r_2, r_3);
}

static	void	fun_lldi_ind_dir_go(t_main *m, t_process *p, int r_3)
{
	short int	ind;
	int			d_1;
	short int	d_2;

	ind = m->map[(p->index + 1 + 1) % MS] << 8;
	ind = ind | m->map[(p->index + 1 + 1 + 1) % MS];
	ind = p->index + ind % IDX_MOD;
	ind = (ind < 0) ? (MS + ind) : ind;
	d_1 = m->map[(ind + 0) % MS] << 8;
	d_1 = d_1 | m->map[(ind + 1) % MS];
	d_1 = d_1 << 8;
	d_1 = d_1 | m->map[(ind + 2) % MS];
	d_1 = d_1 << 8;
	d_1 = d_1 | m->map[(ind + 3) % MS];
	d_2 = m->map[(p->index + 1 + 2 + 1) % MS] << 8;
	d_2 = d_2 | m->map[(p->index + 1 + 2 + 1 + 1) % MS];
	p->rg[r_3] = m->map[(d_1 + d_2 + p->index + 0) % MS];
	p->rg[r_3] = p->rg[r_3] << 8;
	p->rg[r_3] |= m->map[(d_1 + d_2 + p->index + 1) % MS];
	p->rg[r_3] = p->rg[r_3] << 8;
	p->rg[r_3] |= m->map[(d_1 + d_2 + p->index + 2) % MS];
	p->rg[r_3] = p->rg[r_3] << 8;
	p->rg[r_3] |= m->map[(d_1 + d_2 + p->index + 3) % MS];
	p->carry = (p->rg[r_3]) ? 0 : 1;
	p->index = (p->index + STPC) % MS;
}

static	void	fun_lldi_ind_dir(t_main *m, t_process *p)
{
	int			r_3;

	r_3 = m->map[(p->index + 1 + 2 + 2 + 1) % MS] - 1;
	if (r_3 < 0 || r_3 > 15)
	{
		unvalid_only_step(m, p);
		return ;
	}
	else
		fun_lldi_ind_dir_go(m, p, r_3);
}

void			fun_lldi(t_main *m, t_process *p)
{
	if (m->arg[0] == 1 && m->arg[1] == 1 && m->arg[2] == 1)
		fun_lldi_reg_reg(m, p);
	else if (m->arg[0] == 1 && m->arg[1] == 2 && m->arg[2] == 1)
		fun_lldi_reg_dir(m, p);
	else if (m->arg[0] == 2 && m->arg[1] == 1 && m->arg[2] == 1)
		fun_lldi_dir_reg(m, p);
	else if (m->arg[0] == 2 && m->arg[1] == 2 && m->arg[2] == 1)
		fun_lldi_dir_dir(m, p);
	else if (m->arg[0] == 3 && m->arg[1] == 1 && m->arg[2] == 1)
		fun_lldi_ind_reg(m, p);
	else if (m->arg[0] == 3 && m->arg[1] == 2 && m->arg[2] == 1)
		fun_lldi_ind_dir(m, p);
	else
		unvalid_only_step(m, p);
}
