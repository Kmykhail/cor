/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:56:59 by kshyshki          #+#    #+#             */
/*   Updated: 2017/11/27 20:46:56 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_c(t_res *s, va_list *ap)
{
	unsigned char	ch;

	if (!s->len || (s->len && s->dbl_len))
	{
		ch = (unsigned char)va_arg(*ap, int);
		if (!(s->res = (UCH*)ft_strnew(1)))
			return (ER);
		*(s->res) = ch;
	}
	else
	{
		if (parse_lc(s, ap) == ER)
			return (ER);
	}
	if (!(s->res_len = ft_strlen((CCH*)s->res)))
		s->res_len = 1;
	return (OK);
}

int	parse_s(t_res *s, va_list *ap)
{
	char	*str1;

	if (!s->len || (s->len && s->dbl_len))
	{
		if (!(str1 = va_arg(*ap, char*)))
			str1 = "(null)";
		s->res = (UCH*)ft_strnew_cpy(str1);
	}
	else
	{
		if (parse_ls(s, ap) == ER)
			return (ER);
	}
	s->res_len = ft_strlen((CCH*)s->res);
	return (OK);
}

int	parse_lc(t_res *s, va_list *ap)
{
	wint_t			wch;

	wch = va_arg(*ap, wint_t);
	if (!(s->res = pf_uchr((wchar_t)wch)))
		return (ER);
	s->res_len = ft_strlen((const char*)s->res);
	if (s->res != NULL && MB_CUR_MAX == 1)
		return (ER_PR);
	return (OK);
}

int	parse_ls(t_res *s, va_list *ap)
{
	unsigned char	*str1;
	unsigned char	*str2;
	wchar_t			*ustr;

	if (!(ustr = va_arg(*ap, wchar_t*)))
	{
		if (!(s->res = (UCH*)ft_strnew_cpy((char*)NULL_STR)))
			return (ER);
		s->res_len = ft_strlen((CCH*)s->res);
		return (OK);
	}
	if (!(s->res = (UCH*)ft_strnew(0)))
		return (ER);
	while (*ustr)
	{
		str1 = s->res;
		if (!(str2 = pf_uchr(*ustr++)))
			return (error_handler((char**)&str1));
		if (!(s->res = (UCH*)ft_strjoin((CCH*)s->res, (CCH*)str2)))
			return (error_handler_both((char**)&str1, (char**)&str2));
		ft_strdel((char**)&str1);
		ft_strdel((char**)&str2);
		s->res_len = ft_strlen((CCH*)s->res);
	}
	return (OK);
}
