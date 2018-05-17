/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_current.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 11:08:41 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/24 11:08:42 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../main.h"

int     ft_step_pc(t_main *main, int num, t_process *proc)
{
	int     step;

    step = 2;
	if (main->arg[0])
	{
		if (main->arg[0] == 1)
			step += 1;
		if (main->arg[0] == 2)
			step += main->label[num - 1][3];
		if (main->arg[0] == 3)
			step += 2;
	}
	if (main->arg[1])
	{
		if (main->arg[1] == 1)
			step += 1;
		if (main->arg[1] == 2)
			step += main->label[num - 1][3];
		if (main->arg[1] == 3)
			step += 2;
	}
	if (main->arg[2])
	{
		if (main->arg[2] == 1)
			step += 1;
		if (main->arg[2] == 2)
			step += main->label[num - 1][3];
	}
	main->arg[0] = 0;
	main->arg[1] = 0;
	main->arg[2] = 0;
	return (step);
}

void    check_codage(t_main *main, uint8_t num)
{
	int     i;
	int		k;

	i = 1;
	k = 0;
    main->arg[0] = 0;
    main->arg[1] = 0;
    main->arg[2] = 0;
	while (k < 6)
	{
		if ((i == 1 || i == 2))
		{
			main->arg[0] = main->arg[0] << 1;
			main->arg[0] += (num >= 128) ? 1 : 0;
		}
		if (i == 3 || i == 4)
		{
			main->arg[1] = main->arg[1] << 1;
			main->arg[1] += (num >= 128) ? 1 : 0;
		}
		if (i == 5 || i == 6)
		{
			main->arg[2] = main->arg[2] << 1;
			main->arg[2] += (num >= 128) ? 1 :0;
		}
		if (num == 0)
			break ;
		num = num << 1;
		i++;
		k++;
	}
}

