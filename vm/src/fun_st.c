/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_st.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 09:54:20 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/26 09:54:22 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

static	void	fun_st_second_reg(t_main *m, t_process *p)
{
	int		num_reg_1;
	int		num_reg_2;

	num_reg_1 = m->map[(p->index + 1 + 1) % MEM_SIZE] - 1;
	num_reg_2 = m->map[(p->index + 1 + 1 + 1) % MEM_SIZE] - 1;
	if (num_reg_1 < 0 || num_reg_1 > 15 || num_reg_2 < 0 || num_reg_2 > 15)
	{
		unvalid_only_step(m, p);
		return ;
	}
	p->rg[num_reg_2] = p->rg[num_reg_1];
	p->index = (p->index + STPC) % MEM_SIZE;
}

static	void	fun_st_second_ind_go(t_main *m, t_process *p, int num_reg)
{
	short int	res;
	int			step;
	int			tmp;

	m->ch = 1;
	res = m->map[(p->index + 1 + 1 + 1) % MEM_SIZE];
	res = res << 8;
	res = res | (m->map[(p->index + 1 + 1 + 1 + 1) % MEM_SIZE]);
	step = p->index + (res % IDX_MOD);
	step = (step < 0) ? (MS + step) : step;
	tmp = p->rg[num_reg];
	m->map[(step + 3) % MEM_SIZE] = tmp;
	tmp = tmp >> 8;
	m->map[(step + 2) % MEM_SIZE] = tmp;
	tmp = tmp >> 8;
	m->map[(step + 1) % MEM_SIZE] = tmp;
	tmp = tmp >> 8;
	m->map[(step + 0) % MEM_SIZE] = tmp;
	lst_newchanges(m, p, step % MEM_SIZE, (step + 3) % MEM_SIZE);
	p->index = (p->index + STPC) % MEM_SIZE;
}

static	void	fun_st_second_ind(t_main *m, t_process *p)
{
	int			num_reg;

	num_reg = m->map[(p->index + 1 + 1) % MEM_SIZE] - 1;
	if (num_reg < 0 || num_reg > 15)
	{
		unvalid_only_step(m, p);
		return ;
	}
	else
		fun_st_second_ind_go(m, p, num_reg);
}

void			fun_st(t_main *m, t_process *p)
{
	if (m->arg[0] == 1 && m->arg[1] == 1 && m->arg[2] == 0)
		fun_st_second_reg(m, p);
	else if (m->arg[0] == 1 && m->arg[1] == 3 && m->arg[2] == 0)
		fun_st_second_ind(m, p);
	else
		unvalid_only_step(m, p);
}
