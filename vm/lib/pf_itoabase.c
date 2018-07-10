/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 19:54:55 by kshyshki          #+#    #+#             */
/*   Updated: 2017/12/05 14:27:01 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		to_base(uintmax_t *tmp, int base)
{
	uintmax_t buf;

	buf = *tmp % base;
	*tmp = *tmp / base;
	if (base > 9 && buf > 9)
		return ((char)(buf + 'W'));
	else
		return ((char)(buf + '0'));
}

unsigned char	*pf_itoabase(intmax_t value, int base)
{
	uintmax_t		tmp;
	size_t			size;
	unsigned char	*res;

	size = (value < 0 && base == 10) ? 2 : 1;
	tmp = (uintmax_t)((value < 0) ? -value : value);
	while (tmp /= base)
		size++;
	res = (UCH*)ft_strnew(size);
	(value < 0 && base == 10) ? (res[0] = '-') : 0;
	tmp = (uintmax_t)((value < 0) ? -value : value);
	if (value != 0)
		res[--size] = (UCH)to_base(&tmp, base);
	else
		res[0] = '0';
	while (tmp)
		res[--size] = (UCH)to_base(&tmp, base);
	return (res);
}

unsigned char	*pf_uitoabase(uintmax_t value, int base)
{
	uintmax_t		tmp;
	size_t			size;
	unsigned char	*res;

	size = 1;
	tmp = value;
	while (tmp /= base)
		size++;
	res = (UCH*)ft_strnew(size);
	tmp = value;
	res[0] = (value == 0) ? (UCH)to_base(&tmp, base) : (UCH)'0';
	while (tmp)
		res[--size] = (UCH)to_base(&tmp, base);
	return (res);
}
