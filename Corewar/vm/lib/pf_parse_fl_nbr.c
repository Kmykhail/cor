/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_fl_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:56:59 by kshyshki          #+#    #+#             */
/*   Updated: 2018/01/29 19:11:28 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			parse_fl_nbr(t_res *s)
{
	intmax_t		len;
	unsigned char	*tmp_res;

	if (check_zero(s) == ER)
		return (ER);
	if (s->pre >= 0 && (len = s->pre - s->res_len) >= 0)
		if (parse_nul_sign(s, len, 1) == ER)
			return (ER);
	if (s->fl_pl && *(s->res) != '-' && (tmp_res = s->res))
	{
		if (!(s->res = (UCH*)ft_strjoin("+", (CCH*)s->res)))
			return (error_handler((char**)&tmp_res));
		ft_strdel((char**)&tmp_res);
	}
	if (parse_width_nbr(s) == ER)
		return (ER);
	if (s->fl_sp && (s->res[0] != '-' && s->res[0] != '+' && s->res[0] != ' '))
	{
		tmp_res = s->res;
		if (!(s->res = (UCH*)ft_strjoin(" ", (CCH*)s->res)))
			return (error_handler((char**)&tmp_res));
		ft_strdel((char**)&tmp_res);
	}
	s->res_len = ft_strlen((CCH*)s->res);
	return (OK);
}

int			parse_fl_unbr(t_res *s)
{
	intmax_t		len;
	unsigned char	*tmp;

	if (check_zero(s) == ER)
		return (ER);
	if (s->pre >= 0 && (len = s->pre - s->res_len) > 0)
	{
		if (add_zero_left(len, &tmp, s) == ER)
			return (ER);
	}
	if (s->width && (len = s->width - ft_strlen((CCH*)s->res)) > 0)
	{
		if (parse_nul_uxo(len, s) == ER)
			return (ER);
	}
	s->res_len = ft_strlen((CCH*)s->res);
	return (OK);
}

int			parse_fl_x(t_res *s)
{
	intmax_t		len;
	unsigned char	*tmp;

	if (check_zero(s) == ER)
		return (ER);
	if (s->pre >= 0 && (len = s->pre - s->res_len) > 0)
	{
		if (add_zero_left(len, &tmp, s) == ER ||
			(s->fl_octo && parse_fl_okto(s) == ER))
			return (OK);
	}
	if (s->pre < 0 && s->fl_octo && s->fl_nul < 0 && parse_fl_okto(s) == OK)
		s->width += 2;
	else if (s->pre < 0 && s->fl_octo && s->fl_nul < 0)
		return (ER);
	if (s->width && (len = s->width - (ft_strlen((CCH*)s->res))) > 0)
	{
		(s->fl_octo && s->pre < 0) ? len -= 2 : 0;
		if (parse_nul_uxo(len, s) == ER)
			return (ER);
	}
	if (s->pre < 0 && s->fl_octo && s->fl_nul >= 0 && parse_fl_okto(s) == ER)
		return (ER);
	s->res_len = ft_strlen((CCH*)s->res);
	return (OK);
}

int			parse_fl_o(t_res *s)
{
	intmax_t		len;
	unsigned char	*tmp;

	if (check_zero(s) == ER)
		return (ER);
	if (s->pre >= 0 && (len = s->pre - s->res_len) > 0)
	{
		if (add_zero_left(len, &tmp, s) == ER ||
			(s->fl_octo && parse_fl_okto(s) == ER))
			return (ER);
	}
	if (s->pre <= 0 && s->fl_octo && s->fl_nul < 0 && parse_fl_okto(s) == OK)
		(s->pre < 0) ? s->width += 1 : 0;
	else if (s->pre <= 0 && s->fl_octo && s->fl_nul < 0)
		return (ER);
	if (s->width && (len = s->width - (ft_strlen((CCH*)s->res))) > 0)
	{
		(s->fl_octo && s->pre < 0) ? len -= 1 : 0;
		if (parse_nul_uxo(len, s) == ER)
			return (ER);
	}
	if (s->pre < 0 && s->fl_octo && s->fl_nul >= 0 && parse_fl_okto(s) == ER)
		return (ER);
	s->res_len = ft_strlen((CCH*)s->res);
	return (OK);
}

int			parse_fl_p(t_res *s)
{
	intmax_t		len;
	unsigned char	*tmp;

	if (check_zero(s) == ER)
		return (ER);
	if (s->pre >= 0 && (((len = s->pre - s->res_len) > 0)))
	{
		if (add_zero_left(len, &tmp, s) == ER)
			return (ER);
	}
	if (parse_fl_okto(s) == ER)
		return (ER);
	if (s->width && (len = s->width - (ft_strlen((CCH*)s->res))) > 0)
	{
		if (!(tmp = (UCH*)ft_strnew((size_t)len)))
			return (ER);
		(s->fl_nul >= 0 && s->pre < 0 && !s->fl_min) ?
		ft_memset(tmp, '0', (size_t)len) : ft_memset(tmp, ' ', (size_t)len);
		if (!(parse_fl_min(s, tmp)))
			return (error_handler((char**)&tmp));
	}
	s->res_len = ft_strlen((CCH*)s->res);
	return (OK);
}
