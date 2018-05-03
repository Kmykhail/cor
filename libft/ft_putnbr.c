/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 21:51:02 by kshyshki          #+#    #+#             */
/*   Updated: 2017/10/31 18:33:43 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	nbr;
	unsigned int	div;

	div = 1;
	(n < 0) ? (ft_putchar('-')) : 0;
	nbr = (n < 0) ? -n : n;
	while ((n /= 10) != 0)
		div *= 10;
	while (div > 0)
	{
		ft_putchar((nbr / div) + '0');
		nbr %= div;
		div /= 10;
	}
}
