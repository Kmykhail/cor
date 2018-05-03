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


void    test_show_me_label_arg(t_main *main, t_process *proc)
{
    // int     num;

    // num = CODE_OF_BOT[head->pc];
    // dprintf(FD, "_______________\n");
    // dprintf(FD, "label[06][0] = %d\n", main->label[num][0]);
    // dprintf(FD, "label[06][1] = %d\n", main->label[num][1]);
    // dprintf(FD, "label[06][2] = %d\n", main->label[num][2]);
    // dprintf(FD, "label[06][3] = %d\n", main->label[num][3]);
    // dprintf(FD, "_______________\n");
    // dprintf(FD, "step = %d\n", main->steper);
    // dprintf(FD, "_______________\n");
    // dprintf(FD, "arg[0] = %d\n", main->arg[0]);
    // dprintf(FD, "arg[1] = %d\n", main->arg[1]);
    // dprintf(FD, "arg[2] = %d\n", main->arg[2]);
    
    int i;
    int k;
    
    i = 0;
    while (proc->next)
    {
        dprintf(FD, "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP\n");
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
        dprintf(FD, "ppppppppppppppppppppppppppppppppppp\n");
        proc = proc->next;
    }
    dprintf(FD, "_______________________________________\n");
    i = 0;
    while (i < 16)
    {
        k = 0;
        dprintf(FD, "%2i ", i);
        while (k < 4)
        {

            dprintf(FD, "[%4d] ", main->label[i][k]);
            k++;
        }
        dprintf(FD, "\n");
        i++;
    }
    dprintf(FD, "_______________________________________\n");
}
