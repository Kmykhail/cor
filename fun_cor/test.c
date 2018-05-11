//
//  test.c
//  corewar
//
//  Created by Oleg ZHARKO on 4/20/18.
//  Copyright © 2018 Oleg ZHARKO. All rights reserved.
//

#include "../main.h"

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
    dprintf(FD, "_____________test_show_me_label_arg__________________________\n");

    int i;
    int k;
    
    i = 0;

    while (i < 16)
    {
        k = 0;
        while (k < 4)
        {
            dprintf(FD, "[%2d] ", proc->rg[i][k]);
            k++;
        }
        dprintf(FD, "\n");
        i++;
    }
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
