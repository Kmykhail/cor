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
	proc->index = (proc->index + ft_step_pc(main, main->map[proc->index % MEM_SIZE], proc)) % MEM_SIZE;
}

