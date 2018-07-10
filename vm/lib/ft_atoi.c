/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:31:57 by kshyshki          #+#    #+#             */
/*   Updated: 2017/11/05 12:14:57 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	tmp;
	int					sign;

	tmp = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\b' ||
			*str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
		(*str++ == '-') ? sign = -1 : 0;
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		tmp = tmp * 10 + (*str++ - '0');
		if ((tmp >= 922337203685477580) && ((*str - '0') > 7))
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
	}
	return (tmp * sign);
}
