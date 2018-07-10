/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:05:29 by kshyshki          #+#    #+#             */
/*   Updated: 2017/10/31 18:41:49 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	len_needle;

	if (!haystack || !needle)
		return (NULL);
	if (!(len_needle = ft_strlen(needle)))
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle && !(ft_memcmp(haystack, needle, len_needle)))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
