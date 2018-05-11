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
    int		num_reg;
    int     cnt;
    int     start;
    int     end;
    int     tmp;

    step = 0;
    cnt = 0;

	// test_show_me_label_arg(main);

    ready_arg(main, proc);

    // dprintf(FD, "__________________________\n");
    // dprintf(FD, "proc->index = %d\n", proc->index);
    // dprintf(FD, "main->ready_arg[1][0] = %d\n", main->ready_arg[1][0]);
    // dprintf(FD, "main->ready_arg[2][0] = %d\n", main->ready_arg[2][0]);
    // dprintf(FD, "__________________________\n");
    num_reg = main->ready_arg[0][1] - 1;

    step = proc->index + ((main->ready_arg[1][0] + main->ready_arg[2][0]) % IDX_MOD);

    dprintf(FD, "STEP____proc->index:%d\n", proc->index);
    dprintf(FD, "STEP____ b step = %d\n", step);

    if (step < 0)
        step = MEM_SIZE + step;
    start = step;
    tmp = 0;
    while (cnt < 4)
    {
        if (step + cnt >= MEM_SIZE)
        {
            tmp = cnt;
            step = (step + cnt) - MEM_SIZE;
        }
        main->map[step + cnt - tmp] = proc->rg[num_reg][cnt];
        cnt++;
    }
    end = step + cnt - 1 - tmp;
    lst_newchanges(main, proc, start, end, 1);
    /*while (cnt < 4)
    {
        if (step + cnt >= MEM_SIZE)
        {
            step = (step + cnt) % MEM_SIZE;
        }
        cnt -= (!step) ? 1 : 0;
        main->map[step + cnt] = proc->rg[num_reg][cnt];
        dprintf(FD, "STEP___>>>>_STEP:%d\n", step + cnt);
        lst_newchanges(main, proc, step + cnt, step + cnt, 1);
        cnt++;
    }*/
    // dprintf(FD, "proc->index + step = %d\n", proc->index + step);
    // dprintf(FD, "proc->index + step + 3 = %d\n", proc->index + step + 3);
    // dprintf(FD, "\n", );
    // dprintf(FD, "\n", );

    // lst_newchanges(main, proc, step, step + 3, 1);

   	//printf(">>>>>>proc->index + step: %d\n", proc->index + step);
   	
        // main->map[step + 0] = proc->rg[num_reg][0];
        // main->map[step + 1] = proc->rg[num_reg][1];
        // main->map[step + 2] = proc->rg[num_reg][2];
        // main->map[step + 3] = proc->rg[num_reg][3];




    /*main->map[step + 0] = proc->rg[num_reg][0];
    dprintf(FD, "11111\n");
    lst_newchanges(main, proc, step ,step, 1);
    dprintf(FD, "22222\n");
    if (step + 1>= 4096)
    {
        dprintf(FD, ">>>>>>>>>>>1A<<<<<<<<:%d\n", step);
        step = (step + 1) - 4096;
        dprintf(FD, ">>>>>>>>>>>2A<<<<<<<<:%d\n", step);
        main->map[step] = proc->rg[num_reg][1];
        lst_newchanges(main, proc, step, step, 1);
    }
    else
    {
        dprintf(FD, ">>>>>>>>>>>3A<<<<<<<<:%d\n", step);
        main->map[step + 1] = proc->rg[num_reg][1];
        dprintf(FD, ">>>>>>>>>>>4A<<<<<<<<:%d\n", step);
        lst_newchanges(main, proc, step + 1, step + 1, 1);
    }


    if (step + 2 >= 4096)
    {
                dprintf(FD, ">>>>>>>>>>>1B<<<<<<<<:%d\n", step);
        step = (step + 2) - 4096;
                dprintf(FD, ">>>>>>>>>>>2B<<<<<<<<:%d\n", step);
        main->map[step] = proc->rg[num_reg][2];
        lst_newchanges(main, proc, step, step, 1);
    }
    else
    {
        dprintf(FD, ">>>>>>>>>>>3B<<<<<<<<:%d\n", step);
        main->map[step + 2] = proc->rg[num_reg][2];
    dprintf(FD, ">>>>>>>>>>>4B<<<<<<<<:%d\n", step);
    lst_newchanges(main, proc, step + 2, step + 2, 1);
    }


    if (step + 3 >= 4096)
    {
        dprintf(FD, ">>>>>>>>>>>1c<<<<<<<<:%d\n", step);
        step = (step + 3) - 4096;
        dprintf(FD, ">>>>>>>>>>>2C<<<<<<<<:%d\n", step);
        main->map[step] = proc->rg[num_reg][3];
        lst_newchanges(main, proc, step, step, 1);
    }
    else
    {
        dprintf(FD, ">>>>>>>>>>>1D<<<<<<<<:%d\n", step);
        main->map[step + 3] = proc->rg[num_reg][3];
        dprintf(FD, ">>>>>>>>>>>1D<<<<<<<<:%d\n", step);
        lst_newchanges(main, proc, step + 3, step + 3, 1);
    }*/
   	proc->index += ft_step_pc(main, main->map[proc->index], proc);//изменить step на indx
}




    // if (step < 0)
    //     step = MEM_SIZE + step;
    // r = 0;
    // while (r < 4)
    // {
    //     if (step + r >= 0 && step + r < MEM_SIZE)
    //     {
    //         main->map[step + r] = proc->rg[num_reg][r];
    //     }
    //     else
    //          main->map[step + r - MEM_SIZE] = proc->rg[num_reg][r];
    //     r++;
    // }