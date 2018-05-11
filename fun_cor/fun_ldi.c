/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_ldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:50:04 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/24 19:50:06 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

/*
** в таблице сказано что T_IND  Перейдёт на число указаное в T_IND от PC и считает 4 байта
** но в описании функции сказано другое - 4 байта считаные с позиции ((T_IND % IDX_MOD) плюс текущая позиция PC)."
** выполнит первый пунк, а затем второй?
** или выполнить второй без первого
*/

void	fun_ldi(t_main *main, t_process *proc)
{
	int		step;
	int		r;
    int     num_reg;


	step = 0;
	ready_arg(main, proc);
	dprintf(FD, "ТЕСТ fun_ldi 0a\n");
	dprintf(FD, "main->ready_arg[0][0] = %d\nmain->ready_arg[1][0] = %d\nproc->index = %d\n", main->ready_arg[0][0], main->ready_arg[1][0], proc->index);
	step = (main->ready_arg[0][0] + main->ready_arg[1][0]) % IDX_MOD + proc->index;
	
	dprintf(FD, "step = %d\n", step);

   	num_reg = main->ready_arg[2][1] - 1;
	r = 0;
	while (r < 4)
	{
		proc->rg[num_reg][r] = main->map[step + r];
		r++;
	}
	proc->index += ft_step_pc(main, main->map[proc->index], proc);//изменить step на indx
}