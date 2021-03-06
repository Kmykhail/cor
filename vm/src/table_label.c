/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 09:18:35 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/24 09:18:37 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

int			ft_set_value(int i, int c)
{
	int		val;

	val = 0;
	if (!c)
		val = 0;
	else if (c == 1)
		val = (!i || i == 8 || i == 11 || i == 14) ? 0 : 1;
	else if (c == 2)
	{
		(i == 0 || i == 3 || i == 4 || i == 12) ? (val = 9) : 0;
		(i == 1 || i == 2) ? (val = 4) : 0;
		(i >= 5 && i <= 7) ? (val = 5) : 0;
		(i == 8) ? (val = 19) : 0;
		(i == 9 || i == 10) ? (val = 24) : 0;
		(i == 11) ? (val = 799) : 0;
		(i == 13) ? (val = 49) : 0;
		(i == 14) ? (val = 999) : 0;
		(i == 15) ? (val = 1) : 0;
	}
	else if (c == 3)
		val = (c == 3 && ((i >= 0 && i < 8) || i == 12 || i == 15)) ? 4 : 2;
	return (val);
}

void		ft_table_label(t_main *main)
{
	int		i;
	int		c;

	i = 0;
	while (i < 16)
	{
		c = 0;
		while (c < 4)
		{
			main->label[i][c] = ft_set_value(i, c);
			c++;
		}
		i++;
	}
}
