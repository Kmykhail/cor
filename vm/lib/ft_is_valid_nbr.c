/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:06:49 by kshyshki          #+#    #+#             */
/*   Updated: 2017/10/31 18:22:43 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_is_valid_nbr(char *str, int nbr)
{
	char *tmp;

	if (!str)
		return (0);
	tmp = ft_itoa(nbr);
	if (!ft_strcmp(tmp, str))
	{
		ft_strdel(&tmp);
		return (1);
	}
	else
	{
		ft_strdel(&tmp);
		return (0);
	}
}
