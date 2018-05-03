/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:20:05 by kshyshki          #+#    #+#             */
/*   Updated: 2017/10/31 18:35:11 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*res;

	res = NULL;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s++ == (char)c)
			return ((char *)s - 1);
	}
	((char)c == '\0') ? (res = (char *)s) : 0;
	return (res);
}
