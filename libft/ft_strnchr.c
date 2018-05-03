/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:20:05 by kshyshki          #+#    #+#             */
/*   Updated: 2017/10/31 18:35:11 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(const char *s, int c, unsigned long len)
{
	if (!s || !len)
		return (NULL);
	while (*s && len > 0)
	{
		if (*s++ == (char)c)
			return ((char *)s - 1);
		len--;
	}
	return (NULL);
}
