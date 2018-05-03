/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_aff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 11:11:52 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/26 11:11:53 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	fun_aff(t_main *main, t_process *proc)
{
	unsigned char	res;

	res = 0;
	ready_arg(main, proc);
	res = main->ready_arg[0][0] % 256;
	proc->index += ft_step_pc(main, main->map[proc->index], proc);//изменить step на indx
}
