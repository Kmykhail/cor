/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_fl_aux2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:56:59 by kshyshki          #+#    #+#             */
/*   Updated: 2017/11/27 20:46:56 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_fl_min(t_res *s, unsigned char *tmp)
{
	unsigned char	*tmp_res;

	tmp_res = s->res;
	(s->res[0] == 0 && s->fl_min && C(*s->mod)) ? (s->kos = 1) : 0;
	(s->kos) ? --s->res_len : 0;
	s->res = (UCH*)((s->fl_min || (*s->mod == 'p' && s->fl_nul == 1)) ?
					ft_strjoin((CCH*)s->res, (CCH*)tmp) :
					ft_strjoin((CCH*)tmp, (CCH*)s->res));
	if (!(s->res))
		return (error_handler((char**)&tmp_res));
	ft_strdel((char**)&tmp_res);
	ft_strdel((char**)&tmp);
	return (OK);
}

int		parse_nul_sign(t_res *s, intmax_t len, int fl_pre)
{
	int				sign;
	unsigned char	*tmp;
	unsigned char	*tmp_res;

	sign = (*(s->res) == '-' || *(s->res) == '+') ? *(s->res) : 0;
	(sign && fl_pre) ? ++len : len;
	if (sign)
	{
		if (!(tmp = (UCH*)ft_strnew((size_t)len)))
			return (ER);
		ft_memset(tmp, '0', (size_t)len);
		tmp_res = s->res;
		if (!(s->res = (UCH*)ft_strjoin((CCH*)tmp, (CCH*)++(s->res))))
			return (error_handler_both((char**)&tmp, (char**)&tmp_res));
		ft_strdel((char**)&tmp);
		ft_strdel((char**)&tmp_res);
		tmp_res = s->res;
		if (!(s->res = (UCH*)ft_strjoin((char*)&sign, (CCH*)s->res)))
			return (error_handler((char**)tmp_res));
		ft_strdel((char**)&tmp_res);
		return (OK);
	}
	if (add_zero_left(len, &tmp, s) == ER)
		return (ER);
	return (OK);
}

int		parse_width_nbr(t_res *s)
{
	unsigned char	*tmp;
	intmax_t		len;

	if (s->width && (len = s->width - ft_strlen((CCH*)s->res)) > 0)
	{
		(s->fl_sp && s->pre < 0 && s->fl_nul > 0) ? (len--) : 0;
		if (!(tmp = (UCH*)ft_strnew((size_t)len)))
			return (ER);
		if (s->fl_nul >= 0 && s->pre < 0 && !s->fl_min)
		{
			if (!(parse_nul_sign(s, len, 0)))
				return (ER);
		}
		else
			ft_memset(tmp, ' ', (size_t)len);
		if (!(parse_fl_min(s, tmp)))
			return (error_handler((char**)&tmp));
	}
	return (OK);
}

int		parse_nul_uxo(intmax_t len, t_res *s)
{
	unsigned char *tmp;

	if (!(tmp = (UCH*)ft_strnew((size_t)len)))
		return (ER);
	(s->fl_nul >= 0 && (s->pre < 0 || *s->mod == '%') && !s->fl_min) ?
	ft_memset(tmp, '0', (size_t)len) : ft_memset(tmp, ' ', (size_t)len);
	if (!(parse_fl_min(s, tmp)))
		return (error_handler((char**)&tmp));
	return (OK);
}
