/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_sign_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 19:54:55 by kshyshki          #+#    #+#             */
/*   Updated: 2017/12/05 14:27:01 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_get_sign_arg(char *len, int dbl, va_list *ap, intmax_t *res)
{
	intmax_t nbr;

	nbr = 0;
	if (!len)
		nbr = va_arg(*ap, int);
	else if (*len == 'l')
		nbr = (dbl) ? va_arg(*ap, long long int) : va_arg(*ap, long int);
	else if (*len == 'h')
	{
		nbr = va_arg(*ap, int);
		nbr = (dbl) ? (signed char)nbr : (short int)nbr;
	}
	else if (*len == 'j')
		nbr = va_arg(*ap, intmax_t);
	else if (*len == 'z')
		nbr = va_arg(*ap, size_t);
	*res = nbr;
	return (OK);
}

int	pf_get_usign_arg(char *len, int dbl, va_list *ap, uintmax_t *res)
{
	uintmax_t nbr;

	nbr = 0;
	if (!len)
		nbr = va_arg(*ap, unsigned int);
	else if (*len == 'l')
		nbr = (dbl) ? va_arg(*ap, unsigned long long int)
					: va_arg(*ap, unsigned long int);
	else if (*len == 'h')
	{
		nbr = va_arg(*ap, unsigned int);
		nbr = (dbl) ? (unsigned char)nbr : (unsigned short int)nbr;
	}
	else if (*len == 'j')
		nbr = va_arg(*ap, uintmax_t);
	else if (*len == 'z')
		nbr = va_arg(*ap, size_t);
	*res = nbr;
	return (OK);
}
