/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:04:59 by kshyshki          #+#    #+#             */
/*   Updated: 2017/10/31 18:41:03 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;

	if (!haystack || !needle)
		return (NULL);
	if (!(len_needle = ft_strlen(needle)))
		return ((char *)haystack);
	while (*haystack && len-- >= len_needle)
	{
		if (*haystack == *needle && !(ft_memcmp(haystack, needle, len_needle)))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
