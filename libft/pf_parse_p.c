/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:56:59 by kshyshki          #+#    #+#             */
/*   Updated: 2017/11/27 20:46:56 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_p(t_res *s, va_list *ap)
{
	uintmax_t		nbr;
	unsigned char	*tmp;

	nbr = va_arg(*ap, long unsigned int);
	if (!(tmp = pf_uitoabase(nbr, 16)))
		return (ER);
	s->res = tmp;
	s->res_len = ft_strlen((const char*)s->res);
	return (OK);
}
