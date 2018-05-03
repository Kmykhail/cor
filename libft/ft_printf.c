/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:56:59 by kshyshki          #+#    #+#             */
/*   Updated: 2017/12/05 18:11:58 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	delrec(t_res *lst)
{
	if (lst->next)
		delrec(lst->next);
	ft_strdel((char**)&lst->res);
	lst->res = NULL;
	lst->fl_pl = 0;
	lst->fl_min = 0;
	lst->fl_octo = 0;
	lst->fl_nul = 0;
	lst->fl_sp = 0;
	lst->len = NULL;
	lst->dbl_len = 0;
	lst->pre = 0;
	lst->res_len = 0;
	lst->mod = NULL;
	lst->width = 0;
	lst->next = NULL;
	lst->kos = 0;
	free(lst);
}

void		free_res(t_res **res)
{
	if (res)
	{
		if (*res)
		{
			delrec(*res);
			*res = NULL;
		}
	}
}

static int	inspect(const char *str, int *cnt, t_res *res, va_list *ap)
{
	int result;

	if (*str != '%' || *(str + 1) == '%')
		result = add_lst_str((*str != '%') ? str : (str + 1), cnt, res);
	else
		result = add_lst_ap(str, cnt, res, ap);
	return (result);
}

static int	print_res(t_res *res)
{
	t_res	*tmp;
	int		cnt;

	tmp = res;
	cnt = 0;
	while (tmp)
	{
		if (tmp->res)
		{
			if (tmp->kos && C(*(tmp->mod)))
				cnt += write(1, "\0", 1);
			else if (tmp->res_len == 0 && C(*(tmp->mod)))
				tmp->res_len = 1;
			cnt += write(1, tmp->res, tmp->res_len);
		}
		tmp = tmp->next;
	}
	return (cnt);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	t_res	*res;
	int		cnt;
	int		out;
	int		status;

	cnt = 0;
	status = 0;
	if (!format)
		return (0);
	if (!(res = new_res()))
		return (ER);
	va_start(ap, format);
	if (*format == '\0')
		return (0);
	while (*(format + cnt) != '\0')
	{
		out = inspect(format + cnt, &cnt, res, &ap);
		(out == ER || out == ER_PR) ? status = -1 : 0;
	}
	va_end(ap);
	out = print_res(res);
	free_res(&res);
	return ((status == -1) ? status : out);
}
