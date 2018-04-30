/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 21:37:21 by kshyshki          #+#    #+#             */
/*   Updated: 2017/10/31 18:27:39 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	size_res(int nbr)
{
	unsigned int	size;

	size = (nbr < 0) ? 2 : 1;
	while ((nbr /= 10) != 0)
		size++;
	return (size);
}

char				*ft_itoa(int n)
{
	unsigned int	nbr;
	unsigned int	size;
	char			*res;

	size = size_res(n);
	if (!(res = ft_strnew(size)))
		return (NULL);
	(n < 0) ? (*res = '-') : 0;
	nbr = (n < 0) ? -n : n;
	if (nbr == 0)
		*res = '0';
	while (nbr)
	{
		*(res + --size) = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (res);
}
