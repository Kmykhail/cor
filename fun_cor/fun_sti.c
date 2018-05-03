/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_sti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:51:00 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/24 15:51:02 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

/*
** Значение T_REG (первый аргумент) записывается в ячейку, по адресу (ячейка это один байт а в reg 4 байта или запись во все 4 байта от step);
*/

void		fun_sti(t_main *main, t_process *proc)
{
    int     step;

    step = 0;
	// test_show_me_label_arg(main);
    ready_arg(main, proc);
    dprintf(FD, "__________________________\n");
    dprintf(FD, "proc->index = %d\n", proc->index);
    dprintf(FD, "main->ready_arg[1][0] = %d\n", main->ready_arg[1][0]);
    dprintf(FD, "main->ready_arg[2][0] = %d\n", main->ready_arg[2][0]);
    dprintf(FD, "__________________________\n");
    step = proc->index + ((main->ready_arg[1][0] + main->ready_arg[2][0]) % IDX_MOD);
    main->map[step + 0] = proc->rg[0][0];
    main->map[step + 1] = proc->rg[0][1];
    main->map[step + 2] = proc->rg[0][2];
    main->map[step + 3] = proc->rg[0][3];
    // dprintf(FD, "proc->index + step = %d\n", proc->index + step);
    // dprintf(FD, "proc->index + step + 3 = %d\n", proc->index + step + 3);
    // dprintf(FD, "\n", );
    // dprintf(FD, "\n", );
    lst_newchanges(main, proc, step, step + 3, 1);
   	//printf(">>>>>>proc->index + step: %d\n", proc->index + step);
   	proc->index += ft_step_pc(main, main->map[proc->index], proc);//изменить step на indx
}
