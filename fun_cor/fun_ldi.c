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

static	void	fun_ldi_reg_reg(t_main *main, t_process *proc)
{
	int		num_reg_1;
	int		num_reg_2;
	int		num_reg_3;
	int		dist_1;
	int		dist_2;

	num_reg_1 = main->map[ (proc->index + 1 + 1        ) % MEM_SIZE ] - 1;
	num_reg_2 = main->map[ (proc->index + 1 + 1 + 1    ) % MEM_SIZE ] - 1;
	num_reg_3 = main->map[ (proc->index + 1 + 1 + 1 + 1) % MEM_SIZE ] - 1;

	if ((num_reg_1 < 0 || num_reg_1 > 15) || (num_reg_2 < 0 || num_reg_2 > 15) || (num_reg_3 < 0 || num_reg_3 > 15))
	{
		unvalid_only_step(main, proc);
		return ;
	}

	dist_1 = proc->rg[num_reg_1];

	dist_2 = proc->rg[num_reg_2];

	proc->rg[num_reg_3] = main->map[ ( ( (dist_1 + dist_2) % IDX_MOD ) + proc->index + 0) % MEM_SIZE ];
	proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;
	proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( ( (dist_1 + dist_2) % IDX_MOD ) + proc->index + 1) % MEM_SIZE ] ) ;
	proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;
	proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( ( (dist_1 + dist_2) % IDX_MOD ) + proc->index + 2) % MEM_SIZE ] ) ;
	proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;
	proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( ( (dist_1 + dist_2) % IDX_MOD ) + proc->index + 3) % MEM_SIZE ] ) ;

}
static	void	fun_ldi_reg_dir(t_main *main, t_process *proc)
{
	int			num_reg_1;
	int			num_reg_3;
	int			dist_1;
	short int	dist_2;

	num_reg_1 = main->map[ ( proc->index + 1 + 1         ) % MEM_SIZE ] - 1;
	num_reg_3 = main->map[ ( proc->index + 1 + 1 + 2 + 1 ) % MEM_SIZE ] - 1;

	if ((num_reg_1 < 0 || num_reg_1 > 15) || (num_reg_3 < 0 || num_reg_3 > 15))
	{
		unvalid_only_step(main, proc);
		return ;
	}

	dist_1 = proc->rg[num_reg_1];

	dist_2 = 0;
	dist_2 = dist_2 | main->map[ ( proc->index + 1 + 1 + 1     ) % MEM_SIZE];
	dist_2 = dist_2 << 8;
	dist_2 = dist_2 | main->map[ ( proc->index + 1 + 1 + 1 + 1 ) % MEM_SIZE];

	proc->rg[num_reg_3] = main->map[ ( ( (dist_1 + dist_2) % IDX_MOD ) + proc->index + 0) % MEM_SIZE ];
	proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;
	proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( ( (dist_1 + dist_2) % IDX_MOD ) + proc->index + 1) % MEM_SIZE ] ) ;
	proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;
	proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( ( (dist_1 + dist_2) % IDX_MOD ) + proc->index + 2) % MEM_SIZE ] ) ;
	proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;
	proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( ( (dist_1 + dist_2) % IDX_MOD ) + proc->index + 3) % MEM_SIZE ] ) ;

	
}
static	void	fun_ldi_dir_reg(t_main *main, t_process *proc)
{
	int			num_reg_2;
	int			num_reg_3;
	short int	dist_1;
	int			dist_2;

	num_reg_2 = main->map[ ( proc->index + 1 + 2 + 1     ) % MEM_SIZE ] - 1;
	num_reg_3 = main->map[ ( proc->index + 1 + 2 + 1 + 1 ) % MEM_SIZE ] - 1;

	if ((num_reg_2 < 0 || num_reg_2 > 15) || (num_reg_3 < 0 || num_reg_3 > 15))
	{
		unvalid_only_step(main, proc);
		return ;
	}

	dist_1 = 0;
	dist_1 = dist_1 | main->map[ ( proc->index + 1 + 1     ) % MEM_SIZE];

	dist_1 = dist_1 << 8;
	dist_1 = dist_1 | main->map[ ( proc->index + 1 + 1 + 1 ) % MEM_SIZE];

	dist_2 = proc->rg[num_reg_2];

	proc->rg[num_reg_3] = main->map[ ( ( (dist_1 + dist_2) % IDX_MOD ) + proc->index + 0) % MEM_SIZE ];
	proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;
	proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( ( (dist_1 + dist_2) % IDX_MOD ) + proc->index + 1) % MEM_SIZE ] );
	proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;
	proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( ( (dist_1 + dist_2) % IDX_MOD ) + proc->index + 2) % MEM_SIZE ] );
	proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;
	proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( ( (dist_1 + dist_2) % IDX_MOD ) + proc->index + 3) % MEM_SIZE ] );
}
static	void	fun_ldi_dir_dir(t_main *main, t_process *proc)
{
	int			num_reg_3;
	short int	dist_1;
	short int	dist_2;

	num_reg_3 = main->map[ ( proc->index + 1 + 2 + 2 + 1 ) % MEM_SIZE ] - 1;

	if (num_reg_3 < 0 || num_reg_3 > 15)
	{
		unvalid_only_step(main, proc);
		return ;
	}

	dist_1 = 0;
	dist_1 = dist_1 | main->map[ ( proc->index + 1 + 1     ) % MEM_SIZE];
	dist_1 = dist_1 << 8;
	dist_1 = dist_1 | main->map[ ( proc->index + 1 + 1 + 1 ) % MEM_SIZE];

	dist_2 = 0;
	dist_2 = dist_2 | main->map[ ( proc->index + 1 + 2 + 1     ) % MEM_SIZE];
	dist_2 = dist_2 << 8;
	dist_2 = dist_2 | main->map[ ( proc->index + 1 + 2 + 1 + 1 ) % MEM_SIZE];

	proc->rg[num_reg_3] = main->map[ ( ( (dist_1 + dist_2) % IDX_MOD ) + proc->index + 0) % MEM_SIZE ];
	proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;
	proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( ( (dist_1 + dist_2) % IDX_MOD ) + proc->index + 1) % MEM_SIZE ] ) ;
	proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;
	proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( ( (dist_1 + dist_2) % IDX_MOD ) + proc->index + 2) % MEM_SIZE ] ) ;
	proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;
	proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( ( (dist_1 + dist_2) % IDX_MOD ) + proc->index + 3) % MEM_SIZE ] ) ;
}
static	void	fun_ldi_ind_reg(t_main *main, t_process *proc)
{
	int			num_reg_2;
	int			num_reg_3;
	short int	short_ind;
	int			dist_1;
	int			dist_2;

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

	short_ind = proc->index + ( short_ind % IDX_MOD );

	if (short_ind < 0)
		short_ind = MEM_SIZE + short_ind;

	dist_1 = 0;
	dist_1 = dist_1 | main->map[ ( short_ind + 0 ) % MEM_SIZE ];
	dist_1 = dist_1 << 8;
	dist_1 = dist_1 | main->map[ ( short_ind + 1 ) % MEM_SIZE ];
	dist_1 = dist_1 << 8;
	dist_1 = dist_1 | main->map[ ( short_ind + 2 ) % MEM_SIZE ];
	dist_1 = dist_1 << 8;
	dist_1 = dist_1 | main->map[ ( short_ind + 3 ) % MEM_SIZE ];

	dist_2 = proc->rg[num_reg_2];

	proc->rg[num_reg_3] = main->map[ ( ( (dist_1 + dist_2) % IDX_MOD ) + proc->index + 0) % MEM_SIZE ];
	proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;
	proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( ( (dist_1 + dist_2) % IDX_MOD ) + proc->index + 1) % MEM_SIZE ] ) ;
	proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;
	proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( ( (dist_1 + dist_2) % IDX_MOD ) + proc->index + 2) % MEM_SIZE ] ) ;
	proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;
	proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( ( (dist_1 + dist_2) % IDX_MOD ) + proc->index + 3) % MEM_SIZE ] ) ;
}
static	void	fun_ldi_ind_dir(t_main *main, t_process *proc)
{
	int			num_reg_3;
	short int	short_ind;
	int			dist_1;
	short int	dist_2;

	num_reg_3 = main->map[ ( proc->index + 1 + 2 + 2 + 1 ) % MEM_SIZE ] - 1;

	if (num_reg_3 < 0 || num_reg_3 > 15)
	{
		unvalid_only_step(main, proc);
		return ;
	}

	short_ind = 0;
	short_ind = short_ind | main->map[ ( proc->index + 1 + 1     ) % MEM_SIZE ];
	short_ind = short_ind << 8;
	short_ind = short_ind | main->map[ ( proc->index + 1 + 1 + 1 ) % MEM_SIZE ];

	short_ind = proc->index + ( short_ind % IDX_MOD );

	if (short_ind < 0)
		short_ind = MEM_SIZE + short_ind;

	dist_1 = 0;
	dist_1 = dist_1 | main->map[ ( short_ind + 0 ) % MEM_SIZE ];
	dist_1 = dist_1 << 8;
	dist_1 = dist_1 | main->map[ ( short_ind + 1 ) % MEM_SIZE ];
	dist_1 = dist_1 << 8;
	dist_1 = dist_1 | main->map[ ( short_ind + 2 ) % MEM_SIZE ];
	dist_1 = dist_1 << 8;
	dist_1 = dist_1 | main->map[ ( short_ind + 3 ) % MEM_SIZE ];

	dist_2 = 0;
	dist_2 = dist_2 | main->map[ ( proc->index + 1 + 2 + 1    ) % MEM_SIZE];
	dist_2 = dist_2 << 8;
	dist_2 = dist_2 | main->map[ ( proc->index + 1 + 2 + 1 + 1) % MEM_SIZE];

	proc->rg[num_reg_3] = main->map[ ( ( (dist_1 + dist_2) % IDX_MOD ) + proc->index + 0) % MEM_SIZE ];
	proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;
	proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( ( (dist_1 + dist_2) % IDX_MOD ) + proc->index + 1) % MEM_SIZE ] ) ;
	proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;
	proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( ( (dist_1 + dist_2) % IDX_MOD ) + proc->index + 2) % MEM_SIZE ] ) ;
	proc->rg[num_reg_3] = proc->rg[num_reg_3] << 8;
	proc->rg[num_reg_3] = proc->rg[num_reg_3] | ( main->map[ ( ( (dist_1 + dist_2) % IDX_MOD ) + proc->index + 3) % MEM_SIZE ] ) ;
}


void	fun_ldi(t_main *main, t_process *proc)
{
	if (main->arg[0] == 1 && main->arg[1] == 1 && main->arg[2] == 1)
		fun_ldi_reg_reg(main, proc);
	else if (main->arg[0] == 1 && main->arg[1] == 2 && main->arg[2] == 1)
		fun_ldi_reg_dir(main, proc);
	else if (main->arg[0] == 2 && main->arg[1] == 1 && main->arg[2] == 1)
		fun_ldi_dir_reg(main, proc);
	else if (main->arg[0] == 2 && main->arg[1] == 2 && main->arg[2] == 1)
		fun_ldi_dir_dir(main, proc);
	else if (main->arg[0] == 3 && main->arg[1] == 1 && main->arg[2] == 1)
		fun_ldi_ind_reg(main, proc);
	else if (main->arg[0] == 3 && main->arg[1] == 2 && main->arg[2] == 1)
		fun_ldi_ind_dir(main, proc);
	else
	{
		unvalid_only_step(main, proc);
		return ;
	}
	proc->index += ft_step_pc(main, main->map[proc->index], proc);//изменить step на indx
}

