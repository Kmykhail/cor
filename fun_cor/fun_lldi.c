/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_lldi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 11:02:01 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/26 11:02:04 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

/*
** в таблице сказано что T_IND  Перейдёт на число указаное в T_IND от PC и считает 4 байта
** но в описании функции сказано другое - 4 байта считаные с позиции ((T_IND % IDX_MOD) плюс текущая позиция PC)."
** выполнит первый пунк, а затем второй?
** или выполнить второй без первого
*/

static void		fun_lldi_wright_to_reg(t_main *main, int res, t_process *proc)
{
	int     i;
    int     num_reg;
    int		carry;

    carry = 0;
	i = 4;
	if (res)
		carry = 0;
	else
		carry = 1;
   	num_reg = main->ready_arg[2][1];
    while (i--)
    {
        proc->rg[num_reg][i] = res;
        res = res >> 8;
    }

}

void	fun_lldi(t_main *main, t_process *proc)
{
	int		step;
	int		r;
	int		num;


	step = 0;
	ready_arg(main, proc);
	step = (main->ready_arg[0][0] + main->ready_arg[1][0]) + proc->pc;
	num = 0;
	r = 0;
	while (r < 4)
	{
		num = num << 8;
		num = num | main->map[step + r];
		r++;
	}
	fun_lldi_wright_to_reg(main, num, proc);
	proc->index += ft_step_pc(main, main->map[proc->index], proc);//изменить step на indx
}