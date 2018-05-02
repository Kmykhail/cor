/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_zjmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:14:48 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/24 18:14:50 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

/*
** CARRY 
*/

void	fun_zjmp(t_main *main, t_process *proc)
{
	int		carry;
	int		num;

	carry = 0;
	num = 0;
	if (carry == 1)
	{
		ready_arg(main, proc);
		num = main->ready_arg[0][0] % IDX_MOD;
		proc->pc = proc->pc + num;
	}

}