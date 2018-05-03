/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 07:04:25 by kshyshki          #+#    #+#             */
/*   Updated: 2017/09/02 15:52:30 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_is_valid_hex(char *str, int nbr)
{
	char	*tmp;
	int		i;

	i = -1;
	if (!str)
		return (0);
	if (!(str = ft_strchr(str, 'x')))
		return (0);
	str++;
	while (*str == '0')
		str++;
	if (!(tmp = ft_itoa_base(nbr, 16)))
		return (0);
	while (str[++i])
		str[i] = ft_toupper(str[i]);
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
