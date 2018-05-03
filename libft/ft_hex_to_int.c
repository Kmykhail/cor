/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:06:49 by kshyshki          #+#    #+#             */
/*   Updated: 2017/10/31 18:22:43 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_hex_to_int(char *hex)
{
	unsigned int	val;
	int				byte;

	val = 0;
	(hex && ft_strlen(hex) > 2 && hex[0] == '0' &&
			(hex[1] == 'x' || hex[1] == 'X')) ? hex += 2 : 0;
	if (hex)
	{
		while (*hex)
		{
			byte = *hex++;
			if (byte >= '0' && byte <= '9')
				byte = byte - '0';
			else if (byte >= 'a' && byte <= 'f')
				byte = byte - 'a' + 10;
			else if (byte >= 'A' && byte <= 'F')
				byte = byte - 'A' + 10;
			val = (val << 4) | (byte & 0xF);
		}
	}
	return (val);
}
