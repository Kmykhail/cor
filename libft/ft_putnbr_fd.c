/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 21:51:37 by kshyshki          #+#    #+#             */
/*   Updated: 2017/10/31 18:33:53 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;
	unsigned int	div;

	if (fd < 0)
		return ;
	div = 1;
	(n < 0) ? (ft_putchar_fd('-', fd)) : 0;
	nbr = (n < 0) ? -n : n;
	while ((n /= 10) != 0)
		div *= 10;
	while (div > 0)
	{
		ft_putchar_fd(((nbr / div) + '0'), fd);
		nbr %= div;
		div /= 10;
	}
}
