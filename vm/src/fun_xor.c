/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_xor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 11:08:12 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/24 11:08:13 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void			fun_xor(t_main *m, t_process *p)
{
	if (m->arg[0] == 1 && m->arg[1] == 1 && m->arg[2] == 1)
		fun_xor_reg_reg(m, p);
	else if (m->arg[0] == 1 && m->arg[1] == 2 && m->arg[2] == 1)
		fun_xor_reg_dir(m, p);
	else if (m->arg[0] == 1 && m->arg[1] == 3 && m->arg[2] == 1)
		fun_xor_reg_ind(m, p);
	else if (m->arg[0] == 2 && m->arg[1] == 1 && m->arg[2] == 1)
		fun_xor_dir_reg(m, p);
	else if (m->arg[0] == 2 && m->arg[1] == 2 && m->arg[2] == 1)
		fun_xor_dir_dir(m, p);
	else if (m->arg[0] == 2 && m->arg[1] == 3 && m->arg[2] == 1)
		fun_xor_dir_ind(m, p);
	else if (m->arg[0] == 3 && m->arg[1] == 1 && m->arg[2] == 1)
		fun_xor_ind_reg(m, p);
	else if (m->arg[0] == 3 && m->arg[1] == 2 && m->arg[2] == 1)
		fun_xor_ind_dir(m, p);
	else if (m->arg[0] == 3 && m->arg[1] == 3 && m->arg[2] == 1)
		fun_xor_ind_ind(m, p);
	else
		unvalid_only_step(m, p);
}
