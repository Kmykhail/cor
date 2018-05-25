/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_fl_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:56:59 by kshyshki          #+#    #+#             */
/*   Updated: 2017/11/27 20:46:56 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_fl_s(t_res *s)
{
	unsigned char	*tmp;
	intmax_t		len;

	if (s->pre >= 0 && ((size_t)s->pre < s->res_len) && (S(*(s->mod))))
	{
		if (s->res_len >= (size_t)s->pre)
			while (s->res[s->pre - 1] >= MAX_ASCII &&
					s->res[s->pre] <= MASK1_MAIN)
				s->pre--;
		s->res[s->pre] = '\0';
		s->res_len = (size_t)s->pre;
	}
	if (s->width && (len = s->width - s->res_len) > 0)
	{
		if (!(tmp = (UCH*)ft_strnew((size_t)len)))
			return (ER);
		(s->fl_nul >= 0 && !s->fl_min) ? ft_memset(tmp, '0', (size_t)len) :
		ft_memset(tmp, ' ', (size_t)len);
		if (!(parse_fl_min(s, tmp)))
			return (error_handler((char**)&tmp));
		s->res_len += len;
	}
	return (OK);
}
