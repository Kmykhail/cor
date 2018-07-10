/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:07:29 by kshyshki          #+#    #+#             */
/*   Updated: 2017/10/31 18:32:07 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char ch;

	if (!b)
		return (NULL);
	ch = c;
	if (b)
	{
		while (len--)
			((unsigned char*)b)[len] = ch;
	}
	return (b);
}
