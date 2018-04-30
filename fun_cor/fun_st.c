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

#include "../main.h"

static	void	fun_st_second_reg(t_main *main)
{
	int		r;
	int		res;
	int		num_reg;

	res = main->ready_arg[0][0];
	r = 4;
	num_reg = main->ready_arg[1][1];
	while (r--)
	{
		main->rg[num_reg][r] = res;
		res = res >> 8;
	}
}

/*
** не понятно в какую ячейку надо делать запись ? T_REG или T_DIR !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

static	void	fun_st_second_ind(t_main *main)
{
	main->pc = main->pc; // ????? что тут может быть ячейкой?регистр или дир ?? или все 4 ячейки;
}

void	fun_st(t_main *main)
{
	ready_arg(main);
	if (main->arg[1] == 1)
		fun_st_second_reg(main);
	if (main->arg[1] == 3)
		fun_st_second_ind(main);
}