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


    // printf("\nmian->pc = %d   ", proc->pc);
    // printf("ready[0][0] =  %d ||| ", main->ready_arg[0][0]);
    // printf("ready[1][0] =  %d ||| ", main->ready_arg[1][0]);
    // printf("ready[2][0] = %d |||", main->ready_arg[2][0]);
    ready_arg(main, proc);
    step = proc->pc + ((main->ready_arg[1][0] + main->ready_arg[2][0]) % IDX_MOD);
    main->map[proc->pc + step + 0] = proc->rg[0][0];
    main->map[proc->pc + step + 1] = proc->rg[0][1];
    main->map[proc->pc + step + 2] = proc->rg[0][2];
    main->map[proc->pc + step + 3] = proc->rg[0][3];
    dprintf(FD, "main->lst_changes %p\n", main->lst_changes);
    printf("%d\n", proc->pc + step);
    lst_newchanges(main, proc, proc->pc + step, proc->pc + step + 3);
   	//printf(">>>>>>proc->pc + step: %d\n", proc->pc + step);
   	// STEP += 1 + main->arg[0] + main-s>arg[1] + main->arg[2];
}
