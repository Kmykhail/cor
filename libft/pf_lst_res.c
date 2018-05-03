/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lst_res.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:56:59 by kshyshki          #+#    #+#             */
/*   Updated: 2017/12/05 18:11:58 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_mod(t_res *res, CCH *str, int *cnt)
{
	int		i;
	char	*tmp;

	i = -1;
	while (TMOD[++i])
	{
		if (!res->mod && (tmp = ft_strchr(str + 1, TMOD[i])))
			res->mod = tmp;
		else if ((tmp = ft_strnchr(str + 1, TMOD[i], (res->mod - str))))
			res->mod = tmp;
	}
	if (!res->mod && (tmp = ft_strnchr(str + 1, '%', ((res->mod) - (str + 1)))))
	{
		if (!(res->res = (UCH*)ft_strnew(1)))
			return (ER);
		res->res[0] = '%';
		res->res_len = 1;
		res->mod = tmp;
	}
	else if (!res->mod)
	{
		*cnt += 1;
		return (OK);
	}
	return (NEXT_STEP);
}

static int	find_len(t_res *res, CCH *str, int *cnt)
{
	int		i;
	char	*tmp;

	i = -1;
	while (LEN[++i])
		if ((tmp = ft_strnchr(str + 1, LEN[i], (res->mod - str))))
			res->len = tmp;
	*cnt += (res->mod - str) + 1;
	if (res->len && *(res->len) == 'h' && *(res->len + 1) == 'h' &&
		(!IS_OLD(*(res->mod))))
		res->dbl_len = 1;
	else if (IS_OLD(*(res->mod)))
		res->len = &LEN[1];
	else if (res->len && *(res->len) == 'l' && *(res->len + 1) == 'l')
		res->dbl_len = 1;
	i = 0;
	while ((ft_strchr(FLAGS, str[++i])))
	{
		(str[i] == '#') ? res->fl_octo = 1 : 0;
		(str[i] == '0') ? res->fl_nul = 1 : 0;
		(str[i] == '-') ? res->fl_min = 1 : 0;
		(str[i] == '+') ? res->fl_pl = 1 : 0;
		(str[i] == ' ') ? res->fl_sp = 1 : 0;
	}
	return (i);
}

static void	find_width(t_res *res, CCH *str, int i, va_list *ap)
{
	char	*tmp;

	res->width = ft_atoi(str + i);
	if ((tmp = ft_strnchr(str + 1, '*', (res->mod - str))))
	{
		if (res->width && *(tmp - 1) != '.')
		{
			res->width = va_arg(*ap, int);
			(res->width < 0) ? (res->fl_min = 1) : 0;
			res->width = ABS(res->width);
		}
		else if (!res->width && *(tmp - 1) != '.')
		{
			res->width = ft_atoi(str + i + 1);
			if (!res->width)
			{
				res->width = va_arg(*ap, int);
				(res->width < 0) ? (res->fl_min = 1) : 0;
				res->width = ABS(res->width);
			}
			else
				va_arg(*ap, int);
		}
	}
}

static void	find_precision(t_res *res, CCH *str, va_list *ap)
{
	char	*tmp;

	if ((tmp = ft_strnchr(str + 1, '.', (res->mod - str))))
		if (!(res->pre = ft_atoi(tmp + 1)))
			if (ft_strnchr(tmp, '*', (res->mod - tmp)))
				res->pre = va_arg(*ap, int);
}

int			parse_res_ap(const char *str, t_res *res, int *cnt, va_list *ap)
{
	int		i;
	t_f		func;
	t_fl	fl_func;

	if ((i = find_mod(res, str, cnt)) != NEXT_STEP)
		return (i);
	i = find_len(res, str, cnt);
	find_width(res, str, i, ap);
	find_precision(res, str, ap);
	if (*(res->mod) != '%')
	{
		if (!(func = find_func(*(res->mod))))
			return (ER);
		if ((i = func(res, ap)) == ER)
			return (ER);
		if (i == ER_PR)
			return (ER_PR);
	}
	fl_func = find_fl_func(*(res->mod));
	if (fl_func && fl_func(res) == ER)
		return (ER);
	return (OK);
}
