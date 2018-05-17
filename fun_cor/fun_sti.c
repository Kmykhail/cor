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

static  void    fun_sti_reg_reg(t_main *main, t_process *proc)
{
    int     first;
    int	    second;
    int	    third;
    int     num_reg_1;
    int     num_reg_2;
    int     num_reg_3;
    int     step;
    int     start;
    int     end;
    int	    tmp;

    num_reg_1 = main->map[ ( proc->index + 1 + 1         ) % MEM_SIZE ] - 1;
    num_reg_2 = main->map[ ( proc->index + 1 + 1 + 1     ) % MEM_SIZE ] - 1;
    num_reg_3 = main->map[ ( proc->index + 1 + 1 + 1 + 1 ) % MEM_SIZE ] - 1;

    if ((num_reg_1 < 0 || num_reg_1 > 15) || (num_reg_2 < 0 || num_reg_2 > 15) || (num_reg_3 < 0 || num_reg_3 > 15))
    {
        unvalid_only_step(main, proc);
        return ;
    }

    second = proc->rg[num_reg_2];

    third  = proc->rg[num_reg_3];

    step = proc->index + ((second + third) % IDX_MOD);

    if (step < 0)
        step = MEM_SIZE + step;

    start = step % MEM_SIZE;

    tmp = proc->rg[num_reg_1];

    main->map[ ( step + 3 ) % MEM_SIZE ] = tmp;
    tmp = tmp >> 8;

    main->map[ ( step + 2 ) % MEM_SIZE ] = tmp;
    tmp = tmp >> 8;

    main->map[ ( step + 1 ) % MEM_SIZE ] = tmp;
    tmp = tmp >> 8;

    main->map[ ( step + 0 ) % MEM_SIZE ] = tmp;

    end = ( step + 3 ) % MEM_SIZE ;


    lst_newchanges(main, proc, start, end, 1);
}

static  void    fun_sti_dir_reg(t_main *main, t_process *proc)
{
    int             first;
    short int       second;
    int    			third;
    int             num_reg_1;
    int             num_reg_2;
    int             step;
    int             start;
    int             end;
   	int				tmp;

    num_reg_1 = main->map[ ( proc->index + 1 + 1         ) % MEM_SIZE ] - 1;
    num_reg_2 = main->map[ ( proc->index + 1 + 1 + 2 + 1 ) % MEM_SIZE ] - 1;

    if ((num_reg_1 < 0 || num_reg_1 > 15) || (num_reg_2 < 0 || num_reg_2 > 15))
    {
        unvalid_only_step(main, proc);
        return ;
    }

    second = 0;
    second = second | ( main->map[ ( proc->index + 1 + 1 + 1     ) % MEM_SIZE ] ) ;
    second = second << 8;
    second = second | ( main->map[ ( proc->index + 1 + 1 + 1 + 1 ) % MEM_SIZE ] ) ;

    third = proc->rg[num_reg_2];

    step = proc->index + ((second + third) % IDX_MOD);

    if (step < 0)
        step = MEM_SIZE + step;

    
    start = step % MEM_SIZE;

    tmp = proc->rg[num_reg_1];

    main->map[ ( step + 3 ) % MEM_SIZE ] = (unsigned char)tmp;
    tmp = tmp >> 8;

    main->map[ ( step + 2 ) % MEM_SIZE ] = (unsigned char)tmp;
    tmp = tmp >> 8;

    main->map[ ( step + 1 ) % MEM_SIZE ] = (unsigned char)tmp;
    tmp = tmp >> 8;

    main->map[ ( step + 0 ) % MEM_SIZE ] = (unsigned char)tmp;

    end = ( step + 3 ) % MEM_SIZE ;

    lst_newchanges(main, proc, start, end, 1);

}

static  void    fun_sti_ind_reg(t_main *main, t_process *proc)
{
    int             first;
    short int       coor_second;
    int             second;
    int   			third;
    int             num_reg_1;
    int             num_reg_2;
    int             step;
    int             step_ind;
    int             start;
    int             end;
    int   			tmp;

    num_reg_1 = main->map[ ( proc->index + 1 + 1         ) % MEM_SIZE ] - 1;
    num_reg_2 = main->map[ ( proc->index + 1 + 1 + 2 + 1 ) % MEM_SIZE ] - 1;

    if ((num_reg_1 < 0 || num_reg_1 > 15) || (num_reg_2 < 0 || num_reg_2 > 15))
    {
        unvalid_only_step(main, proc);
        return ;
    }

    coor_second = 0;
    coor_second = coor_second | ( main->map[ ( proc->index + 1 + 1 + 1     ) % MEM_SIZE ] );
    coor_second = coor_second << 8;
    coor_second = coor_second | ( main->map[ ( proc->index + 1 + 1 + 1 + 1 ) % MEM_SIZE ] );

    step_ind = proc->index + coor_second % IDX_MOD;

    if (step_ind < 0)
        step_ind = MEM_SIZE + step_ind;

    second = 0;
    second = second | ( main->map[ ( step_ind + 0 ) % MEM_SIZE ] );
    second = second << 8;
    second = second | ( main->map[ ( step_ind + 1 ) % MEM_SIZE ] );
    second = second << 8;
    second = second | ( main->map[ ( step_ind + 2 ) % MEM_SIZE ] );
    second = second << 8;
    second = second | ( main->map[ ( step_ind + 3 ) % MEM_SIZE ] );

    third = proc->rg[num_reg_2];

    step = proc->index + ((second + third) % IDX_MOD);

    if (step < 0)
        step = MEM_SIZE + step;

    start = step % MEM_SIZE;

    tmp = proc->rg[num_reg_1];

    main->map[ ( step + 3 ) % MEM_SIZE ] = tmp;
    tmp = tmp >> 8;

    main->map[ ( step + 2 ) % MEM_SIZE ] = tmp;
    tmp = tmp >> 8;

    main->map[ ( step + 1 ) % MEM_SIZE ] = tmp;
    tmp = tmp >> 8;

    main->map[ ( step + 0 ) % MEM_SIZE ] = tmp;

    end = ( step + 3 ) % MEM_SIZE ;

    lst_newchanges(main, proc, start, end, 1);
}

static  void    fun_sti_reg_dir(t_main *main, t_process *proc)
{
    int             first;
    int        		second;
    short int       third;
    int             num_reg_1;
    int             num_reg_2;
    int             step;
    int             start;
    int             end;
    int	tmp;

    num_reg_1 = main->map[ ( proc->index + 1 + 1     ) % MEM_SIZE ] - 1;
    num_reg_2 = main->map[ ( proc->index + 1 + 1 + 1 ) % MEM_SIZE ] - 1;

    if ((num_reg_1 < 0 || num_reg_1 > 15) || (num_reg_2 < 0 || num_reg_2 > 15))
    {
        unvalid_only_step(main, proc);
        return ;
    }

    second = proc->rg[num_reg_2];

    third  = 0;
    third = third | ( main->map[ ( proc->index + 1 + 1 + 1 + 1     ) % MEM_SIZE ] );
    third = third << 8;
    third = third | ( main->map[ ( proc->index + 1 + 1 + 1 + 1 + 1 ) % MEM_SIZE ] );

    step = proc->index + ((second + third) % IDX_MOD);

    if (step < 0)
        step = MEM_SIZE + step;

    start = step % MEM_SIZE;

    tmp = proc->rg[num_reg_1];

    main->map[ ( step + 3 ) % MEM_SIZE ] = tmp;
    tmp = tmp >> 8;

    main->map[ ( step + 2 ) % MEM_SIZE ] = tmp;
    tmp = tmp >> 8;

    main->map[ ( step + 1 ) % MEM_SIZE ] = tmp;
    tmp = tmp >> 8;

    main->map[ ( step + 0 ) % MEM_SIZE ] = tmp;

    end = ( step + 3 ) % MEM_SIZE ;

    lst_newchanges(main, proc, start, end, 1);
}

static  void    fun_sti_dir_dir(t_main *main, t_process *proc)
{
    int         	first;
    short int   	second;
    short int   	third;
    int         	num_reg_1;
    int         	step;
    int         	start;
    int        	 	end;
    int	tmp;

    num_reg_1 = main->map[ ( proc->index + 1 + 1 ) % MEM_SIZE ] - 1;

    if (num_reg_1 < 0 || num_reg_1 > 15)
    {
        unvalid_only_step(main, proc);
        return ;
    }

    second = 0;
    second = second | ( main->map[ ( proc->index + 1 + 1 + 1     ) % MEM_SIZE ] ) ;
    second = second << 8;
    second = second | ( main->map[ ( proc->index + 1 + 1 + 1 + 1 ) % MEM_SIZE ] ) ;

    third  = 0;
    third  = third  | ( main->map[ ( proc->index + 1 + 1 + 1 + 1 + 1     ) % MEM_SIZE ] ) ;
    third  = third  << 8;
    third  = third  | ( main->map[ ( proc->index + 1 + 1 + 1 + 1 + 1 + 1 ) % MEM_SIZE ] ) ;
    
    step = proc->index + ((second + third) % IDX_MOD);
    
    if (step < 0)
        step = MEM_SIZE + step;

    start = step % MEM_SIZE;

    tmp = proc->rg[num_reg_1];

    main->map[ ( step + 3 ) % MEM_SIZE ] = tmp;
    tmp = tmp >> 8;

    main->map[ ( step + 2 ) % MEM_SIZE ] = tmp;
    tmp = tmp >> 8;

    main->map[ ( step + 1 ) % MEM_SIZE ] = tmp;
    tmp = tmp >> 8;

    main->map[ ( step + 0 ) % MEM_SIZE ] = tmp;

    end = ( step + 3 ) % MEM_SIZE ;

    lst_newchanges(main, proc, start, end, 1);
}

static  void    fun_sti_ind_dir(t_main *main, t_process *proc)
{
    int         	first;
    short int   	coor_second;
    int         	second;
    short int   	third;
    int         	num_reg_1;
    int         	step;
    int         	step_ind;
    int         	start;
    int         	end;
    int				tmp;

    num_reg_1 = main->map[ ( proc->index + 1 + 1 ) % MEM_SIZE ] - 1;

    if (num_reg_1 < 0 || num_reg_1 > 15)
    {
        unvalid_only_step(main, proc);
        return ;
    }

    coor_second = 0;
    coor_second = coor_second | ( main->map[ ( proc->index + 1 + 1 + 1     ) % MEM_SIZE ] ) ;
    coor_second = coor_second << 8;
    coor_second = coor_second | ( main->map[ ( proc->index + 1 + 1 + 1 + 1 ) % MEM_SIZE ] ) ;

    step_ind = proc->index + coor_second % IDX_MOD;

    if (step_ind < 0)
        step_ind = MEM_SIZE + step_ind;

    second = 0;
    second = second | ( main->map[ ( step_ind + 0 ) % MEM_SIZE ] );
    second = second << 8;
    second = second | ( main->map[ ( step_ind + 1 ) % MEM_SIZE ] );
    second = second << 8;
    second = second | ( main->map[ ( step_ind + 2 ) % MEM_SIZE ] );
    second = second << 8;
    second = second | ( main->map[ ( step_ind + 3 ) % MEM_SIZE ] );

    third  = 0;
    third  = third  | ( main->map[ ( proc->index + 1 + 1 + 1 + 1 + 1     ) % MEM_SIZE ] ) ;
    third  = third  << 8;
    third  = third  | ( main->map[ ( proc->index + 1 + 1 + 1 + 1 + 1 + 1 ) % MEM_SIZE ] ) ;

    step = proc->index + ((second + third) % IDX_MOD);

    if (step < 0)
        step = MEM_SIZE + step;
    
    start = step % MEM_SIZE;

    tmp = proc->rg[num_reg_1];

    main->map[ ( step + 3 ) % MEM_SIZE ] = tmp;
    tmp = tmp >> 8;

    main->map[ ( step + 2 ) % MEM_SIZE ] = tmp;
    tmp = tmp >> 8;

    main->map[ ( step + 1 ) % MEM_SIZE ] = tmp;
    tmp = tmp >> 8;

    main->map[ ( step + 0 ) % MEM_SIZE ] = tmp;

    end = ( step + 3 ) % MEM_SIZE ;

    lst_newchanges(main, proc, start, end, 1);
}



void    fun_sti(t_main *main, t_process *proc)
{
    if (main->arg[0] == 1 && main->arg[1] == 1 && main->arg[2] == 1)
        fun_sti_reg_reg(main, proc);
    else if (main->arg[0] == 1 && main->arg[1] == 1 && main->arg[2] == 2)
        fun_sti_reg_dir(main, proc);
    else if (main->arg[0] == 1 && main->arg[1] == 2 && main->arg[2] == 1)
        fun_sti_dir_reg(main, proc);
    else if (main->arg[0] == 1 && main->arg[1] == 2 && main->arg[2] == 2)
        fun_sti_dir_dir(main, proc);
    else if (main->arg[0] == 1 && main->arg[1] == 3 && main->arg[2] == 1)
        fun_sti_ind_reg(main, proc);
    else if (main->arg[0] == 1 && main->arg[1] == 3 && main->arg[2] == 2)
        fun_sti_ind_dir(main, proc);
    else
    {
        unvalid_only_step(main, proc);
        return ;
    }
    proc->index += ft_step_pc(main, main->map[proc->index], proc);
}
