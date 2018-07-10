/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lst_ctr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:56:59 by kshyshki          #+#    #+#             */
/*   Updated: 2017/12/05 18:11:58 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			create_res(const char *str, t_res *res, int *cnt)
{
	size_t i;

	i = 0;
	while ((*(str + i) != '%' || i == 0) && *(str + i) != '\0')
		i++;
	if (!(res->res = (UCH*)ft_strnew(i)))
		return (ER);
	ft_memmove(res->res, str, i);
	res->mod = ft_strchr(TMOD, 's');
	res->res_len = (int)i;
	*cnt += (*str == '%') ? (i + 1) : i;
	return (OK);
}

int			add_lst_str(const char *str, int *cnt, t_res *res)
{
	t_res	*tmp;

	tmp = res;
	if (res->res == NULL)
		return (create_res(str, res, cnt));
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_res();
		tmp = tmp->next;
		return (create_res(str, tmp, cnt));
	}
}

int			add_lst_ap(const char *str, int *cnt, t_res *res, va_list *ap)
{
	t_res	*tmp;

	tmp = res;
	if (!(res->mod))
		return (parse_res_ap(str, res, cnt, ap));
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_res();
		tmp = tmp->next;
		return (parse_res_ap(str, tmp, cnt, ap));
	}
}

t_res		*new_res(void)
{
	t_res *res;

	if (!(res = (t_res*)malloc(sizeof(t_res))))
		return (NULL);
	res->res = NULL;
	res->fl_pl = 0;
	res->fl_min = 0;
	res->fl_octo = 0;
	res->fl_nul = -1;
	res->fl_sp = 0;
	res->len = NULL;
	res->dbl_len = 0;
	res->pre = -1;
	res->res_len = 0;
	res->mod = NULL;
	res->width = 0;
	res->next = NULL;
	res->kos = 0;
	return (res);
}
