/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 07:04:25 by kshyshki          #+#    #+#             */
/*   Updated: 2017/09/02 15:52:30 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		to_base(long int *tmp, int base)
{
	int buf;

	buf = *tmp % base;
	*tmp = *tmp / base;
	if (base > 9 && buf > 9)
		return (buf + '7');
	else
		return (buf + '0');
}

char			*ft_itoa_base(int value, int base)
{
	long int	tmp;
	int			size;
	char		*res;

	size = (value < 0 && base == 10) ? 2 : 1;
	tmp = value;
	(tmp < 0) ? (tmp = -tmp) : 0;
	while (tmp /= base)
		size++;
	if (!(res = ft_strnew(size)))
		return (NULL);
	res[size] = '\0';
	(value < 0 && base == 10) ? (res[0] = '-') : 0;
	tmp = (value < 0) ? -(tmp + value) : value;
	(value == 0) ? (res[--size] = to_base(&tmp, base)) : 0;
	while (tmp)
		res[--size] = to_base(&tmp, base);
	return (res);
}
