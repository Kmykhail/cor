/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:45:40 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/24 19:45:42 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

static	void	fun_add_go(t_main *m, t_process *p)
{
	int			num_reg_1;
	int			num_reg_2;
	int			num_reg_3;

	num_reg_1 = m->map[(p->index + 2) % MS] - 1;
	num_reg_2 = m->map[(p->index + 3) % MS] - 1;
	num_reg_3 = m->map[(p->index + 4) % MS] - 1;
	if ((num_reg_1 < 0 || num_reg_1 > 15) || (num_reg_2 < 0 ||
		num_reg_2 > 15) || (num_reg_3 < 0 || num_reg_3 > 15))
	{
		unvalid_only_step(m, p);
		return ;
	}
	p->rg[num_reg_3] = p->rg[num_reg_1] + p->rg[num_reg_2];
	if (p->rg[num_reg_3])
		p->carry = 0;
	else
		p->carry = 1;
	p->index = (p->index + STPC) % MS;
}

void			fun_add(t_main *m, t_process *p)
{
	if (m->arg[0] == 1 && m->arg[1] == 1 && m->arg[2] == 1)
		fun_add_go(m, p);
	else
		unvalid_only_step(m, p);
}
