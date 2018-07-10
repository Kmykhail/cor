/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_lldi_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 12:07:39 by ozharko           #+#    #+#             */
/*   Updated: 2018/05/22 12:07:45 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void			fun_lldi_reg_reg(t_main *m, t_process *p)
{
	int			r_1;
	int			r_2;
	int			r_3;
	int			d_1;
	int			d_2;

	r_1 = m->map[(p->index + 1 + 1) % MS] - 1;
	r_2 = m->map[(p->index + 1 + 1 + 1) % MS] - 1;
	r_3 = m->map[(p->index + 1 + 1 + 1 + 1) % MS] - 1;
	if (r_1 < 0 || r_1 > 15 || r_2 < 0 || r_2 > 15 || r_3 < 0 || r_3 > 15)
	{
		unvalid_only_step(m, p);
		return ;
	}
	d_1 = p->rg[r_1];
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

void			fun_lldi_reg_dir(t_main *m, t_process *p)
{
	int			r_1;
	int			r_3;
	int			d_1;
	short int	d_2;

	r_1 = m->map[(p->index + 1 + 1) % MS] - 1;
	r_3 = m->map[(p->index + 1 + 1 + 2 + 1) % MS] - 1;
	if (r_1 < 0 || r_1 > 15 || r_3 < 0 || r_3 > 15)
	{
		unvalid_only_step(m, p);
		return ;
	}
	d_1 = p->rg[r_1];
	d_2 = m->map[(p->index + 1 + 1 + 1) % MS] << 8;
	d_2 = d_2 | m->map[(p->index + 1 + 1 + 1 + 1) % MS];
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

void			fun_lldi_dir_reg(t_main *m, t_process *p)
{
	int			r_2;
	int			r_3;
	short int	d_1;
	int			d_2;

	r_2 = m->map[(p->index + 1 + 2 + 1) % MS] - 1;
	r_3 = m->map[(p->index + 1 + 2 + 1 + 1) % MS] - 1;
	if (r_2 < 0 || r_2 > 15 || r_3 < 0 || r_3 > 15)
	{
		unvalid_only_step(m, p);
		return ;
	}
	d_1 = m->map[(p->index + 1 + 1) % MS];
	d_1 = d_1 << 8;
	d_1 = d_1 | m->map[(p->index + 1 + 1 + 1) % MS];
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

void			fun_lldi_dir_dir(t_main *m, t_process *p)
{
	int			r_3;
	short int	d_1;
	short int	d_2;

	r_3 = m->map[(p->index + 1 + 2 + 2 + 1) % MS] - 1;
	if (r_3 < 0 || r_3 > 15)
	{
		unvalid_only_step(m, p);
		return ;
	}
	d_1 = m->map[(p->index + 1 + 1) % MS];
	d_1 = d_1 << 8;
	d_1 = d_1 | m->map[(p->index + 1 + 1 + 1) % MS];
	d_2 = m->map[(p->index + 1 + 2 + 1) % MS];
	d_2 = d_2 << 8;
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
