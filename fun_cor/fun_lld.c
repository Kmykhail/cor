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

#include "../main.h"

void	 fun_lld(t_main *main, t_process *proc)
{
	int			num_reg;
	short int	long_way;


	if (main->arg[0] == 2 && main->arg[1] == 1 && main->arg[2] == 0)
	{
		num_reg = main->map[ ( proc->index + 1 + 4 + 1 ) % MEM_SIZE ] - 1;

		if (num_reg < 0 || num_reg > 15)
		{
			unvalid_only_step(main, proc);
			return ;
		}

		proc->rg[num_reg] = main->map[ ( proc->index + 1 + 1             ) % MEM_SIZE];
		proc->rg[num_reg] = proc->rg[num_reg] << 8;

		proc->rg[num_reg] = proc->rg[num_reg] | main->map[ ( proc->index + 1 + 1 + 1         ) % MEM_SIZE];
		proc->rg[num_reg] = proc->rg[num_reg] << 8;

		proc->rg[num_reg] = proc->rg[num_reg] | main->map[ ( proc->index + 1 + 1 + 1 + 1     ) % MEM_SIZE];
		proc->rg[num_reg] = proc->rg[num_reg] << 8;

		proc->rg[num_reg] = proc->rg[num_reg] | main->map[ ( proc->index + 1 + 1 + 1 + 1 + 1 ) % MEM_SIZE];
	
		if (proc->rg[num_reg])
			proc->carry = 0;
		else
			proc->carry = 1;

		proc->index += ft_step_pc(main, main->map[proc->index], proc);
	}
	if (main->arg[0] == 3 && main->arg[1] == 1 && main->arg[2] == 0)
	{
		num_reg = main->map[ ( proc->index + 1 + 2 + 1 ) % MEM_SIZE ] - 1;

		if (num_reg < 0 || num_reg > 15)
		{
			unvalid_only_step(main, proc);
			return ;
		}
		long_way = main->map[ ( proc->index + 1 + 1     ) % MEM_SIZE ];
		long_way = long_way << 8;
		long_way = main->map[ ( proc->index + 1 + 1 + 1 ) % MEM_SIZE ];

		long_way = proc->index + long_way;

		if (long_way < 0)
        	long_way = MEM_SIZE + long_way;

		proc->rg[num_reg] = main->map[ ( long_way + 0 ) % MEM_SIZE ];
		proc->rg[num_reg] = proc->rg[num_reg] << 8;

		proc->rg[num_reg] = proc->rg[num_reg] | main->map[ ( long_way + 1 ) % MEM_SIZE ];
		proc->rg[num_reg] = proc->rg[num_reg] << 8;

		proc->rg[num_reg] = proc->rg[num_reg] | main->map[ ( long_way + 2 ) % MEM_SIZE ];
		proc->rg[num_reg] = proc->rg[num_reg] << 8;

		proc->rg[num_reg] = proc->rg[num_reg] | main->map[ ( long_way + 3 ) % MEM_SIZE ];
	
		if (proc->rg[num_reg])
			proc->carry = 0;
		else
			proc->carry = 1;

		proc->index += ft_step_pc(main, main->map[proc->index], proc);
	}
	else
		unvalid_only_step(main, proc);
}

