/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_lld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 11:00:15 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/26 11:00:17 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

static	void	fun_lld_dir(t_main *m, t_process *p)
{
	int			nr;

	nr = m->map[(p->index + 1 + 4 + 1) % MS] - 1;
	if (nr < 0 || nr > 15)
	{
		unvalid_only_step(m, p);
		return ;
	}
	p->rg[nr] = m->map[(p->index + 2) % MS];
	p->rg[nr] = p->rg[nr] << 8;
	p->rg[nr] |= m->map[(p->index + 3) % MS];
	p->rg[nr] = p->rg[nr] << 8;
	p->rg[nr] |= m->map[(p->index + 4) % MS];
	p->rg[nr] = p->rg[nr] << 8;
	p->rg[nr] |= m->map[(p->index + 5) % MS];
	p->carry = (p->rg[nr]) ? 0 : 1;
	p->index = (p->index + ft_step_pc(m, m->map[p->index % MS])) % MS;
}

static	void	fun_lld_ind(t_main *m, t_process *p)
{
	int			nr;
	short int	long_way;

	nr = m->map[(p->index + 1 + 2 + 1) % MS] - 1;
	if (nr < 0 || nr > 15)
	{
		unvalid_only_step(m, p);
		return ;
	}
	long_way = m->map[(p->index + 2) % MS];
	long_way = long_way << 8;
	long_way = m->map[(p->index + 3) % MS];
	long_way = p->index + long_way;
	long_way = (long_way < 0) ? (MS + long_way) : long_way;
	p->rg[nr] = m->map[(long_way + 0) % MS];
	p->rg[nr] = p->rg[nr] << 8;
	p->rg[nr] |= m->map[(long_way + 1) % MS];
	p->rg[nr] = p->rg[nr] << 8;
	p->rg[nr] |= m->map[(long_way + 2) % MS];
	p->rg[nr] = p->rg[nr] << 8;
	p->rg[nr] |= m->map[(long_way + 3) % MS];
	p->carry = (p->rg[nr]) ? 0 : 1;
	p->index = (p->index + ft_step_pc(m, m->map[p->index % MS])) % MS;
}

void			fun_lld(t_main *m, t_process *p)
{
	if (m->arg[0] == 2 && m->arg[1] == 1 && m->arg[2] == 0)
		fun_lld_dir(m, p);
	if (m->arg[0] == 3 && m->arg[1] == 1 && m->arg[2] == 0)
		fun_lld_ind(m, p);
	else
		unvalid_only_step(m, p);
}
