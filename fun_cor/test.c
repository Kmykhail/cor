//
//  test.c
//  corewar
//
//  Created by Oleg ZHARKO on 4/20/18.
//  Copyright © 2018 Oleg ZHARKO. All rights reserved.
//

#include "../main.h"

void     show_ld(t_main *main, t_process *proc)
{
    // dprintf(FD, "________________START____________\n");
    // while (proc)
    // {
    //     dprintf(FD, "cmd_cycle = %d\npc = %d\nindex; = %d\nnbr_pl = %d\nlive = %d\ncarry = %d\nproc->next = %p\nADD proc->rg = %p\n", proc->cmd_cycle, proc->pc, proc->index, proc->nbr_pl, proc->live, proc->carry, proc->next, proc->rg);
    //     test_show_me_label_arg(main, proc);
    //     proc = proc->next;
    //     dprintf(FD, "\nNEXT______NEXT_____NEXT\n\n");
    // }
    // dprintf(FD, "main->steper = %d\nmain->cp_cl_to_die = %d\nmain->cnt_p = %d\nmain->cur_cycle = %d\nmain->cl_to_die = %d\nmain->mx_check = %d\nmain->lst_proc = %p\nmain->nbr_proc = %d\nmain->lst_changes = %p\nmain->last_live_player = %p\nmain->finish = %d\nmain->ddddd = %d\n ",main->steper, main->cp_cl_to_die, main->cnt_pl, main->cur_cycle, main->cl_to_die, main->mx_check, main->lst_proc, main->nbr_proc, main->lst_changes, main->last_live_player, main->finish, main->ddddd );
    

    // int i;
    // int j;

    // i = 0;
    // dprintf(FD, "________________PROC_LABEL_______________\n");
    // dprintf(FD, "ADD main->label = %p\n", main->label);
    // while ( i < 16)
    // {
    //     j = 0;
    //     while (j < 4)
    //     {
    //         dprintf(FD, "[%4d]", main->label[i][j]);
    //         j++;
    //     }
    //     dprintf(FD, "\n");
    //     i++;
    // }
    // dprintf(FD, "__________________________END\n");
    // dprintf(FD, "arg[0] = %d\n", main->arg[0]);
    // dprintf(FD, "arg[1] = %d\n", main->arg[1]);
    // dprintf(FD, "arg[2] = %d\n", main->arg[2]);
    // dprintf(FD, "\n");
    // dprintf(FD, "ready_arg[0][0] = %d\n", main->ready_arg[0][0]);
    // dprintf(FD, "ready_arg[0][1] = %d\n", main->ready_arg[0][1]);
    // dprintf(FD, "\n");
    // dprintf(FD, "ready_arg[1][0] = %d\n", main->ready_arg[1][0]);
    // dprintf(FD, "ready_arg[1][1] = %d\n", main->ready_arg[1][1]);
    // dprintf(FD, "\n");
    // dprintf(FD, "ready_arg[2][0] = %d\n", main->ready_arg[2][0]);
    // dprintf(FD, "ready_arg[2][1] = %d\n", main->ready_arg[2][1]);
    // dprintf(FD, "\n");
    // dprintf(FD, "ADD ready_arg = %p\n", main->ready_arg);
    // dprintf(FD, "\n");
    // dprintf(FD, "coor_of_p[0] = %d\n", main->coor_of_p[0]);
    // dprintf(FD, "coor_of_p[1] = %d\n", main->coor_of_p[1]);
    // dprintf(FD, "coor_of_p[2] = %d\n", main->coor_of_p[2]);
    // dprintf(FD, "coor_of_p[3] = %d\n", main->coor_of_p[3]);
    // dprintf(FD, "ADD lst_changes = %p\n", main->lst_changes);
    // dprintf(FD, "\n");

}

void    test_open(t_main *main)
{
    // main->fd =  open("/Users/ozharko/Desktop/corewar/corewar/src/test.txt", O_RDONLY | O_WRONLY | O_TRUNC, 0644);
}

// int     ft_find_command(int find)
// {
//     int res;
//     int i;

//     i = 0;
//     res = 0;
//     while (i < 16)
//     {
//         if (find - 1 == i)
//         {
//             return (i);
//         }
//         i++;
//     }
//     return (res);
// }


void    test_show_part_of_map(t_main *main, t_process *proc)
{
    /*dprintf(FD, "@main->map[%d] = %x\n",proc->index, main->map[proc->index + 0]);
    dprintf(FD, "@main->map[%d] = %x\n",proc->index, main->map[proc->index + 1]);
    dprintf(FD, "@main->map[%d] = %x\n",proc->index, main->map[proc->index + 2]);
    dprintf(FD, "@main->map[%d] = %x\n",proc->index, main->map[proc->index + 3]);
    dprintf(FD, "@main->map[%d] = %x\n",proc->index, main->map[proc->index + 4]);
    dprintf(FD, "@main->map[%d] = %x\n",proc->index, main->map[proc->index + 5]);
    dprintf(FD, "@main->map[%d] = %x\n",proc->index, main->map[proc->index + 6]);*/
}

void    test_show_me_label_arg(t_main *main, t_process *proc)
{
    dprintf(FD4, "____test_show_me_label_arg___\n");

    int i;
    int k;
    int tmp;
    
    i = 0;

    dprintf(FD, "It is now cycle = %d\n", main->cur_cycle);
    while (i < 16)
    {
        k = 0;
        tmp = proc->rg[i];
            dprintf(FD, "%d ", proc->rg[i]);
        i++;
    }
        dprintf(FD, "---CARRY---%d\n\n", proc->carry);

    //dprintf(FD, "______________,,,,,,,,,,,,,,,,,,,,,,,,,,_________________________\n");
    // i = 0;
    // while (i < 16)
    // {
    //     k = 0;
    //     dprintf(FD, "%2i ", i);
    //     while (k < 4)
    //     {

    //         dprintf(FD, "[%4d] ", main->label[i][k]);
    //         k++;
    //     }
    //     dprintf(FD, "\n");
    //     i++;
    // }
    // dprintf(FD, "_______________________________________\n");
}
