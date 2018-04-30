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

void		fun_sti(t_main *main)
{
    int     step;

	test_show_me_label_arg(main);
    ready_arg(main);
    step = main->pc + ((main->ready_arg[1][0] + main->ready_arg[2][0]) % IDX_MOD);
    main->map[main->pc + step] = main->ready_arg[0][0];
   	//printf(">>>>>>main->pc + step: %d\n", main->pc + step);
}
