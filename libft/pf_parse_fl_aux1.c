/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_fl_aux1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:56:59 by kshyshki          #+#    #+#             */
/*   Updated: 2017/11/27 20:46:56 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		error_handler(char **tmp)
{
	ft_strdel(tmp);
	return (ER);
}

int		error_handler_both(char **tmp, char **tmp_res)
{
	ft_strdel(tmp_res);
	ft_strdel(tmp);
	return (ER);
}

int		add_zero_left(intmax_t len, unsigned char **tmp, t_res *s)
{
	unsigned char *tmp_res;

	(s->fl_octo && s->pre > 0 && O(*s->mod)) ? len -= 1 : 0;
	tmp_res = s->res;
	if (!(*tmp = (UCH*)ft_strnew((size_t)len)))
		return (ER);
	ft_memset(*tmp, '0', (size_t)len);
	if (!(s->res = (UCH*)ft_strjoin((CCH*)*tmp, (CCH*)s->res)))
		return (error_handler_both((char**)tmp, (char**)tmp_res));
	ft_strdel((char**)&tmp_res);
	ft_strdel((char**)tmp);
	return (OK);
}

int		check_zero(t_res *s)
{
	if (s->pre == 0 && s->res_len == 1 && (*(s->res) == '0'))
	{
		ft_strdel((char**)&s->res);
		if (!(s->res = (UCH*)ft_strnew(0)))
			return (ER);
		return (OK);
	}
	return (OK);
}

int		parse_fl_okto(t_res *s)
{
	unsigned char	*tmp;

	tmp = s->res;
	if (X(*(s->mod)) || P(*(s->mod)))
	{
		if (!(s->res = (UCH*)ft_strjoin((CCH*)((*(s->mod) == 'x' ||
				*(s->mod) == 'p') ? &ZEROX : &ZEROLX), (CCH*)s->res)))
			return (error_handler((char**)&tmp));
		ft_strdel((char**)&tmp);
	}
	else if (O(*(s->mod)))
	{
		if (!(s->res = (UCH*)ft_strjoin("0", (CCH*)s->res)))
			return (error_handler((char**)&tmp));
		ft_strdel((char**)&tmp);
	}
	return (OK);
}
