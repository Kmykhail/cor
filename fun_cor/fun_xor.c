/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_xor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 11:08:12 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/24 11:08:13 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static void     fun_xor_reg_reg(t_main *main, t_process *proc)
{
    int     num_reg_1;
    int     num_reg_2;
    int     num_reg_3;

    num_reg_1 = main->map[ ( proc->index + 1 + 1         ) % MEM_SIZE ] - 1;
    num_reg_2 = main->map[ ( proc->index + 1 + 1 + 1     ) % MEM_SIZE ] - 1;
    num_reg_3 = main->map[ ( proc->index + 1 + 1 + 1 + 1 ) % MEM_SIZE ] - 1;

    if ((num_reg_1 < 0 || num_reg_1 > 15) || (num_reg_2 < 0 || num_reg_2 > 15) || (num_reg_3 < 0 || num_reg_3 > 15))
    {
        unvalid_only_step(main, proc);
        return ;
    }

    proc->rg[num_reg_3] = proc->rg[num_reg_1] ^ proc->rg[num_reg_2];

    if (proc->rg[num_reg_3])
        proc->carry = 0;
    else
        proc->carry = 1;
}

static void     fun_xor_reg_dir(t_main *main, t_process *proc)
{
    int     num_reg_1;
    int     num_reg_3;
    int     res;


    num_reg_1 = main->map[ ( proc->index + 1 + 1         ) % MEM_SIZE ] - 1;
    num_reg_3 = main->map[ ( proc->index + 1 + 1 + 4 + 1 ) % MEM_SIZE ] - 1;

    if ((num_reg_1 < 0 || num_reg_1 > 15) || (num_reg_3 < 0 || num_reg_3 > 15))
    {
        unvalid_only_step(main, proc);
        return ;
    }

    res = 0;

    proc->rg[num_reg_3] = proc->rg[num_reg_1] ^ main->map[ ( proc->index + 1 + 1 + 1             ) % MEM_SIZE];
    proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;

    proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( proc->rg[num_reg_1] ^ main->map[ ( proc->index + 1 + 1 + 1 + 1         ) % MEM_SIZE] );
    proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;

    proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( proc->rg[num_reg_1] ^ main->map[ ( proc->index + 1 + 1 + 1 + 1 + 1     ) % MEM_SIZE] );
    proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;

    proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( proc->rg[num_reg_1] ^ main->map[ ( proc->index + 1 + 1 + 1 + 1 + 1 + 1 ) % MEM_SIZE] );

    if (proc->rg[num_reg_3])
        proc->carry = 0;
    else
        proc->carry = 1;


}

static void     fun_xor_reg_ind(t_main *main, t_process *proc)
{
    int         num_reg_1;
    int         num_reg_3;
    short int   short_ind;

    num_reg_1 = main->map[ ( proc->index + 1 + 1         ) % MEM_SIZE ] - 1;
    num_reg_3 = main->map[ ( proc->index + 1 + 1 + 2 + 1 ) % MEM_SIZE ] - 1;

    if ((num_reg_1 < 0 || num_reg_1 > 15) || (num_reg_3 < 0 || num_reg_3 > 15))
    {
        unvalid_only_step(main, proc);
        return ;
    }

    short_ind = 0;
    short_ind = short_ind | main->map[ ( proc->index + 1 + 1 + 1     ) % MEM_SIZE ];
    short_ind = short_ind << 8;
    short_ind = short_ind | main->map[ ( proc->index + 1 + 1 + 1 + 1 ) % MEM_SIZE ];

    short_ind = proc->index + (short_ind % IDX_MOD);

    if (short_ind < 0)
        short_ind = MEM_SIZE + short_ind;

    proc->rg[num_reg_3] = proc->rg[num_reg_1] ^ main->map[ ( short_ind + 0 ) % MEM_SIZE ];
    proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;

    proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( proc->rg[num_reg_1] ^ main->map[ ( short_ind + 1 ) % MEM_SIZE ] ) ;
    proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;

    proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( proc->rg[num_reg_1] ^ main->map[ ( short_ind + 2 ) % MEM_SIZE ] ) ;
    proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;

    proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( proc->rg[num_reg_1] ^ main->map[ ( short_ind + 3 ) % MEM_SIZE ] ) ;

    if (proc->rg[num_reg_3])
        proc->carry = 0;
    else
        proc->carry = 1;
}

static void     fun_xor_dir_reg(t_main *main, t_process *proc)
{
    int         num_reg_2;
    int         num_reg_3;

    num_reg_2 = main->map[ ( proc->index + 1 + 4 + 1     ) % MEM_SIZE ] - 1;
    num_reg_3 = main->map[ ( proc->index + 1 + 4 + 1 + 1 ) % MEM_SIZE ] - 1;

    if ((num_reg_2 < 0 || num_reg_2 > 15) || (num_reg_3 < 0 || num_reg_3 > 15))
    {
        unvalid_only_step(main, proc);
        return ;
    }

    proc->rg[num_reg_3] = main->map[ ( proc->index + 1 + 1             ) % MEM_SIZE ] ^ proc->rg[num_reg_2];
    proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;

    proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( proc->index + 1 + 1 + 1         ) % MEM_SIZE ] ^ proc->rg[num_reg_2] ) ;
    proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;

    proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( proc->index + 1 + 1 + 1 + 1     ) % MEM_SIZE ] ^ proc->rg[num_reg_2] ) ;
    proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;

    proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( proc->index + 1 + 1 + 1 + 1 + 1 ) % MEM_SIZE ] ^ proc->rg[num_reg_2] ) ;

    if (proc->rg[num_reg_3])
        proc->carry = 0;
    else
        proc->carry = 1;
}

static void     fun_xor_dir_dir(t_main *main, t_process *proc)
{
    int         num_reg_3;

    num_reg_3 = main->map[ ( proc->index + 1 + 4 + 4 + 1 ) % MEM_SIZE ] - 1;

    if (num_reg_3 < 0 || num_reg_3 > 15)
    {
        unvalid_only_step(main, proc);
        return ;
    }

    proc->rg[num_reg_3] = main->map[ ( proc->index + 1 + 1             ) % MEM_SIZE ] ^ main->map[ ( proc->index + 1 + 4 + 1             ) % MEM_SIZE];
    proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;

    proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( proc->index + 1 + 1 + 1         ) % MEM_SIZE ] ^ main->map[ ( proc->index + 1 + 4 + 1 + 1         ) % MEM_SIZE] );
    proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;

    proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( proc->index + 1 + 1 + 1 + 1     ) % MEM_SIZE ] ^ main->map[ ( proc->index + 1 + 4 + 1 + 1 + 1     ) % MEM_SIZE] );
    proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;

    proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( proc->index + 1 + 1 + 1 + 1 + 1 ) % MEM_SIZE ] ^ main->map[ ( proc->index + 1 + 4 + 1 + 1 + 1 + 1 ) % MEM_SIZE] );

    if (proc->rg[num_reg_3])
        proc->carry = 0;
    else
        proc->carry = 1;
}

static void     fun_xor_dir_ind(t_main *main, t_process *proc)
{
    int         num_reg_3;
    short int   short_ind;

    num_reg_3 = main->map[ ( proc->index + 1 + 4 + 2 + 1 ) % MEM_SIZE ] - 1;

    if (num_reg_3 < 0 || num_reg_3 > 15)
    {
        unvalid_only_step(main, proc);
        return ;
    }

    short_ind = 0;
    short_ind = short_ind | main->map[ ( proc->index + 1 + 4 + 1     ) % MEM_SIZE ];
    short_ind = short_ind << 8;
    short_ind = short_ind | main->map[ ( proc->index + 1 + 4 + 1 + 1 ) % MEM_SIZE ];

    short_ind = proc->index + (short_ind % IDX_MOD);

    if (short_ind < 0)
        short_ind = MEM_SIZE + short_ind;

    proc->rg[num_reg_3] = main->map[ ( proc->index + 1 + 1             ) % MEM_SIZE ] ^ main->map[ ( short_ind + 0 ) % MEM_SIZE ];
    proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;

    proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( proc->index + 1 + 1 + 1         ) % MEM_SIZE ] ^ main->map[ ( short_ind + 1 ) % MEM_SIZE ] );
    proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;

    proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( proc->index + 1 + 1 + 1 + 1     ) % MEM_SIZE ] ^ main->map[ ( short_ind + 2 ) % MEM_SIZE ] );
    proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;

    proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( proc->index + 1 + 1 + 1 + 1 + 1 ) % MEM_SIZE ] ^ main->map[ ( short_ind + 3 ) % MEM_SIZE ] );

    if (proc->rg[num_reg_3])
        proc->carry = 0;
    else
        proc->carry = 1;

}

static void     fun_xor_ind_reg(t_main *main, t_process *proc)
{
    int         num_reg_2;
    int         num_reg_3;
    short int   short_ind;

    num_reg_2 = main->map[ ( proc->index + 1 + 2 + 1     ) % MEM_SIZE ] - 1;
    num_reg_3 = main->map[ ( proc->index + 1 + 2 + 1 + 1 ) % MEM_SIZE ] - 1;

    if ((num_reg_2 < 0 || num_reg_2 > 15) || (num_reg_3 < 0 || num_reg_3 > 15))
    {
        unvalid_only_step(main, proc);
        return ;
    }

    short_ind = 0;
    short_ind = short_ind | main->map[ ( proc->index + 1 + 1     ) % MEM_SIZE ];
    short_ind = short_ind << 8;
    short_ind = short_ind | main->map[ ( proc->index + 1 + 1 + 1 ) % MEM_SIZE ];

    short_ind = proc->index + (short_ind % IDX_MOD);

    if (short_ind < 0)
        short_ind = MEM_SIZE + short_ind;

    proc->rg[num_reg_3] = main->map[ ( short_ind + 0 ) % MEM_SIZE ] ^ proc->rg[num_reg_2];
    proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;

    proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( short_ind + 1 ) % MEM_SIZE ] ^ proc->rg[num_reg_2] ) ;
    proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;

    proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( short_ind + 2 ) % MEM_SIZE ] ^ proc->rg[num_reg_2] ) ;
    proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;

    proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( short_ind + 3 ) % MEM_SIZE ] ^ proc->rg[num_reg_2] ) ;

    if (proc->rg[num_reg_3])
        proc->carry = 0;
    else
        proc->carry = 1;

}

static void     fun_xor_ind_dir(t_main *main, t_process *proc)
{
    int         num_reg_3;
    short int   short_ind;

    num_reg_3 = main->map[ ( proc->index + 1 + 2 + 4 + 1 ) % MEM_SIZE ] - 1;

    if (num_reg_3 < 0 || num_reg_3 > 15)
    {
        unvalid_only_step(main, proc);
        return ;
    }

    short_ind = 0;
    short_ind = short_ind | main->map[ ( proc->index + 1 + 1     ) % MEM_SIZE ];
    short_ind = short_ind << 8;
    short_ind = short_ind | main->map[ ( proc->index + 1 + 1 + 1 ) % MEM_SIZE ];

    short_ind = proc->index + (short_ind % IDX_MOD);

    if (short_ind < 0)
        short_ind = MEM_SIZE + short_ind;

    proc->rg[num_reg_3] = main->map[ ( short_ind + 0 ) % MEM_SIZE ] ^ main->map[ ( proc->index + 1 + 2 + 1              ) % MEM_SIZE ];
    proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;

    proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( short_ind + 1 ) % MEM_SIZE ] ^ main->map[ ( proc->index + 1 + 2 + 1 + 1          ) % MEM_SIZE ] ) ;
    proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;

    proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( short_ind + 2 ) % MEM_SIZE ] ^ main->map[ ( proc->index + 1 + 2 + 1 + 1 + 1      ) % MEM_SIZE ] ) ;
    proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;

    proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( short_ind + 3 ) % MEM_SIZE ] ^ main->map[ ( proc->index + 1 + 2 + 1 + 1  + 1 + 1 ) % MEM_SIZE ] ) ;

    if (proc->rg[num_reg_3])
        proc->carry = 0;
    else
        proc->carry = 1;
}

static void     fun_xor_ind_ind(t_main *main, t_process *proc)
{
    int         num_reg_3;
    short int   short_ind_1;
    short int   short_ind_2;

    num_reg_3 = main->map[ ( proc->index + 1 + 2 + 2 + 1 ) % MEM_SIZE ] - 1;

    if (num_reg_3 < 0 || num_reg_3 > 15)
    {
        unvalid_only_step(main, proc);
        return ;
    }

    short_ind_1 = 0;
    short_ind_1 = short_ind_1 | main->map[ ( proc->index + 1 + 1     ) % MEM_SIZE ];
    short_ind_1 = short_ind_1 << 8;
    short_ind_1 = short_ind_1 | main->map[ ( proc->index + 1 + 1 + 1 ) % MEM_SIZE ];

    short_ind_1 = proc->index + (short_ind_1 % IDX_MOD);

    if (short_ind_1 < 0)
        short_ind_1 = MEM_SIZE + short_ind_1;

    short_ind_2 = 0;
    short_ind_2 = short_ind_2 | main->map[ ( proc->index + 1 + 2 + 1     ) % MEM_SIZE ];
    short_ind_2 = short_ind_2 << 8;
    short_ind_2 = short_ind_2 | main->map[ ( proc->index + 1 + 2 + 1 + 1 ) % MEM_SIZE ];

    short_ind_2 = proc->index + (short_ind_2 % IDX_MOD);

    if (short_ind_2 < 0)
        short_ind_2 = MEM_SIZE + short_ind_2;

    proc->rg[num_reg_3] = main->map[ ( short_ind_1 + 0 ) % MEM_SIZE ] ^  main->map[ ( short_ind_2 + 0 ) % MEM_SIZE ];
    proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;

    proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( short_ind_1 + 1 ) % MEM_SIZE ] ^  main->map[ ( short_ind_2 + 1 ) % MEM_SIZE ] ) ;
    proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;

    proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( short_ind_1 + 2 ) % MEM_SIZE ] ^  main->map[ ( short_ind_2 + 2 ) % MEM_SIZE ] ) ;
    proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;

    proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( short_ind_1 + 3 ) % MEM_SIZE ] ^  main->map[ ( short_ind_2 + 3 ) % MEM_SIZE ] ) ;

    if (proc->rg[num_reg_3])
        proc->carry = 0;
    else
        proc->carry = 1;
}

void    fun_xor(t_main *main, t_process *proc)
{

    if (main->arg[0] == 1 && main->arg[1] == 1 && main->arg[2] == 1)
        fun_xor_reg_reg(main, proc);
    else if (main->arg[0] == 1 && main->arg[1] == 2 && main->arg[2] == 1)
        fun_xor_reg_dir(main, proc);
    else if (main->arg[0] == 1 && main->arg[1] == 3 && main->arg[2] == 1)
        fun_xor_reg_ind(main, proc);
    else if (main->arg[0] == 2 && main->arg[1] == 1 && main->arg[2] == 1)
        fun_xor_dir_reg(main, proc);
    else if (main->arg[0] == 2 && main->arg[1] == 2 && main->arg[2] == 1)
        fun_xor_dir_dir(main, proc);
    else if (main->arg[0] == 2 && main->arg[1] == 3 && main->arg[2] == 1)
        fun_xor_dir_ind(main, proc);
    else if (main->arg[0] == 3 && main->arg[1] == 1 && main->arg[2] == 1)
        fun_xor_ind_reg(main, proc);
    else if (main->arg[0] == 3 && main->arg[1] == 2 && main->arg[2] == 1)
        fun_xor_ind_dir(main, proc);
    else if (main->arg[0] == 3 && main->arg[1] == 3 && main->arg[2] == 1)
        fun_xor_ind_ind(main, proc);
    else
    {
        unvalid_only_step(main, proc);
        return ;
    }
    proc->index += ft_step_pc(main, main->map[proc->index], proc);
}

