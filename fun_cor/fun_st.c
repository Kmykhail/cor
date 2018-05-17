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

static	void	fun_st_second_reg(t_main *main, t_process *proc)
{
	int		num_reg_1;
	int		num_reg_2;

	num_reg_1 = main->map[ ( proc->index + 1 + 1     ) % MEM_SIZE ] - 1;
	num_reg_2 = main->map[ ( proc->index + 1 + 1 + 1 ) % MEM_SIZE ] - 1;

	proc->rg[num_reg_2] = proc->rg[num_reg_1];
}

static	void	fun_st_second_ind(t_main *main, t_process *proc)
{
	short int	res;
	int			num_reg;
	int			step;
	int			start;
	int			end;
	int			tmp; // ?? 0 0 0 0

	num_reg = main->map[ ( proc->index + 1 + 1 ) % MEM_SIZE ] - 1;

	res = 0;
	res = res | ( main->map[ ( proc->index + 1 + 1 + 1     ) % MEM_SIZE ] );
	res = res << 8;
	res = res | ( main->map[ ( proc->index + 1 + 1 + 1 + 1 ) % MEM_SIZE ] );
	
	step = proc->index + ( res % IDX_MOD );


    if (step < 0)
        step = MEM_SIZE + step;

    start = step;

	tmp = proc->rg[num_reg];

    main->map[ ( step + 3 ) % MEM_SIZE ] = tmp;
    tmp = tmp >> 8;

    main->map[ ( step + 2 ) % MEM_SIZE ] = tmp;
    tmp = tmp >> 8;

    main->map[ ( step + 1 ) % MEM_SIZE ] = tmp;
    tmp = tmp >> 8;

    main->map[ ( step + 0 ) % MEM_SIZE ] = tmp;

    end =  ( step + 3 ) % MEM_SIZE ;
    
    lst_newchanges(main, proc, start, end, 1);
}

void	fun_st(t_main *main, t_process *proc)
{
	if (main->arg[1] == 1)
		fun_st_second_reg(main, proc);

	if (main->arg[1] == 3)
		fun_st_second_ind(main, proc);

	proc->index += ft_step_pc(main, main->map[proc->index], proc);
}