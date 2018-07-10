/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:56:59 by kshyshki          #+#    #+#             */
/*   Updated: 2018/01/29 19:11:52 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_i(t_res *s, va_list *ap)
{
	intmax_t		nbr;
	unsigned char	*tmp;

	if (pf_get_sign_arg(s->len, s->dbl_len, ap, &nbr) == ER)
		return (ER);
	if (!(s->res = pf_itoabase(nbr, 10)))
		return (ER);
	if (nbr > 0 && s->fl_sp && !(s->fl_pl) && s->pre < 0
			&& s->pre < 0 && s->width && !s->fl_nul)
	{
		tmp = s->res;
		if (!(s->res = (UCH*)ft_strjoin((CCH*)" ", (CCH*)s->res)))
			return (ER);
		ft_strdel((char**)&tmp);
	}
	s->res_len = ft_strlen((CCH*)s->res);
	return (OK);
}

int	parse_ld(t_res *s, va_list *ap)
{
	intmax_t	nbr;

	nbr = va_arg(*ap, long int);
	if (!(s->res = pf_itoabase(nbr, 10)))
		return (ER);
	s->res_len = ft_strlen((CCH*)s->res);
	return (OK);
}

int	parse_x(t_res *s, va_list *ap)
{
	uintmax_t	nbr;
	int			i;

	if (pf_get_usign_arg(s->len, s->dbl_len, ap, &nbr) == ER)
		return (ER);
	if (!(s->res = pf_uitoabase(nbr, 16)))
		return (ER);
	(nbr == 0) ? s->fl_octo = 0 : 0;
	if (IS_BIG(*(s->mod)))
	{
		i = -1;
		while ((s->res)[++i])
			(s->res)[i] = (UCH)ft_toupper((s->res)[i]);
	}
	s->res_len = ft_strlen((CCH*)s->res);
	return (OK);
}

int	parse_u(t_res *s, va_list *ap)
{
	uintmax_t	nbr;

	if (pf_get_usign_arg(s->len, s->dbl_len, ap, &nbr) == ER)
		return (ER);
	if (!(s->res = pf_uitoabase(nbr, 10)))
		return (ER);
	s->res_len = ft_strlen((CCH*)s->res);
	return (OK);
}

int	parse_o(t_res *s, va_list *ap)
{
	uintmax_t	nbr;

	if (pf_get_usign_arg(s->len, s->dbl_len, ap, &nbr) == ER)
		return (ER);
	if (!(s->res = pf_uitoabase(nbr, 8)))
		return (ER);
	(nbr == 0 && s->pre < 0) ? s->fl_octo = 0 : 0;
	s->res_len = ft_strlen((CCH*)s->res);
	return (OK);
}
