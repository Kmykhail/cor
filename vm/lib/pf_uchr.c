/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_uchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 19:54:55 by kshyshki          #+#    #+#             */
/*   Updated: 2017/12/05 14:27:01 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned char	*first_check(wchar_t chr)
{
	unsigned char	*res;

	if (chr <= MAX_ASCII || chr > MAX_UNI)
	{
		if ((chr > MAX_UNI))
			return (NULL);
		else
		{
			if (!(res = (UCH*)ft_strnew(1)))
				return (NULL);
			*res = (unsigned char)chr;
			return (res);
		}
	}
	else
		return (NULL);
}

static unsigned char	*fillres(wchar_t chr, unsigned int cnt)
{
	unsigned char	*res;
	int				i;

	i = 0;
	if (!(res = (UCH*)ft_strnew(cnt)))
		return (NULL);
	while (cnt)
		res[cnt--] = (UCH)(MASK_SEC | (MASK_SEL & (chr >> (6 * i++))));
	return (res);
}

unsigned char			*pf_uchr(wchar_t chr)
{
	unsigned int	cnt;
	unsigned char	*res;

	cnt = 0;
	if (chr < 0)
		return (NULL);
	if ((res = first_check(chr)))
		return (res);
	if (MB_CUR_MAX == 1)
	{
		if (!(res = (UCH*)ft_strnew(1)))
			return (NULL);
		res[0] = (UCH)((char)chr);
	}
	else if (++cnt && !(intmax_t)(chr >> ((cnt * 6) + (6 - cnt))) &&
			(res = fillres(chr, cnt)))
		res[0] = (UCH)MASK1_MAIN | (UCH)(chr >> ((cnt) * 6));
	else if (++cnt && !(chr >> ((cnt * 6) + (6 - cnt))) &&
			(res = fillres(chr, cnt)))
		res[0] = (UCH)MASK2_MAIN | (UCH)(chr >> ((cnt) * 6));
	else if (++cnt && !(chr >> ((cnt * 6) + (6 - cnt))) &&
			(res = fillres(chr, cnt)))
		res[0] = (UCH)MASK3_MAIN | (UCH)(chr >> ((cnt) * 6));
	return (res);
}
