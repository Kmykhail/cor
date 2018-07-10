/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_ld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 10:07:35 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/26 10:07:36 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

static	void	fun_ld_dir(t_main *m, t_process *p)
{
	int			r;

	r = m->map[(p->index + 1 + 4 + 1) % MS] - 1;
	if (r < 0 || r > 15)
	{
		unvalid_only_step(m, p);
		return ;
	}
	p->rg[r] = m->map[(p->index + 2) % MS];
	p->rg[r] = p->rg[r] << 8;
	p->rg[r] = p->rg[r] + (m->map[(p->index + 3) % MS]);
	p->rg[r] = p->rg[r] << 8;
	p->rg[r] = p->rg[r] + (m->map[(p->index + 4) % MS]);
	p->rg[r] = p->rg[r] << 8;
	p->rg[r] = p->rg[r] + (m->map[(p->index + 5) % MS]);
	if (p->rg[r])
		p->carry = 0;
	else
		p->carry = 1;
	p->index = (p->index + ft_step_pc(m, m->map[p->index % MS])) % MS;
}

static	void	fun_ld_ind(t_main *m, t_process *p)
{
	int			r;
	short int	long_way;

	r = m->map[(p->index + 1 + 2 + 1) % MS] - 1;
	if (r < 0 || r > 15)
	{
		unvalid_only_step(m, p);
		return ;
	}
	long_way = m->map[(p->index + 2) % MS] << 8;
	long_way = m->map[(p->index + 3) % MS];
	long_way = p->index + long_way % IDX_MOD;
	if (long_way < 0)
		long_way = MS + long_way;
	p->rg[r] = 0;
	p->rg[r] = (p->rg[r] | m->map[(long_way + 0) % MS]) << 8;
	p->rg[r] = (p->rg[r] | m->map[(long_way + 1) % MS]) << 8;
	p->rg[r] = (p->rg[r] | m->map[(long_way + 2) % MS]) << 8;
	p->rg[r] = (p->rg[r] | m->map[(long_way + 3) % MS]);
	if (p->rg[r])
		p->carry = 0;
	else
		p->carry = 1;
	p->index = (p->index + ft_step_pc(m, m->map[p->index % MS])) % MS;
}

void			fun_ld(t_main *m, t_process *p)
{
	if (m->arg[0] == 2 && m->arg[1] == 1 && m->arg[2] == 0)
		fun_ld_dir(m, p);
	else if (m->arg[0] == 3 && m->arg[1] == 1 && m->arg[2] == 0)
		fun_ld_ind(m, p);
	else
		unvalid_only_step(m, p);
}
