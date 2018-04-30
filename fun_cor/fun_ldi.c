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

/*
** в таблице сказано что T_IND  Перейдёт на число указаное в T_IND от PC и считает 4 байта
** но в описании функции сказано другое - 4 байта считаные с позиции ((T_IND % IDX_MOD) плюс текущая позиция PC)."
** выполнит первый пунк, а затем второй?
** или выполнить второй без первого
*/

static void		fun_ldi_wright_to_reg(t_main *main, int res)
{
	int     i;
    int     num_reg;

	i = 4;
   	num_reg = main->ready_arg[2][1];
    while (i--)
    {
        main->rg[num_reg][i] = res;
        res = res >> 8;
    }
}

void	fun_ldi(t_main *main)
{
	int		step;
	int		r;
	int		num;


	step = 0;
	ready_arg(main);
	step = (main->ready_arg[0][0] + main->ready_arg[1][0]) % IDX_MOD + main->pc;
	num = 0;
	r = 0;
	while (r < 4)
	{
		num = num << 8;
		num = num | main->map[step + r];
		r++;
	}
	fun_ldi_wright_to_reg(main, num);
}