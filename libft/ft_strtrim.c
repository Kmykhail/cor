/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 21:21:06 by kshyshki          #+#    #+#             */
/*   Updated: 2017/10/31 18:42:36 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new_str;
	size_t	size;

	if (!s)
		return (NULL);
	while ((*s == ' ' || *s == '\n' || *s == '\t') && *s != '\0')
		s++;
	if (!(size = ft_strlen(s)))
		return (new_str = ft_strnew(size));
	while (*(s + size - 1) == ' ' || *(s + size - 1) == '\n' ||
			*(s + size - 1) == '\t')
		size--;
	if (!(new_str = ft_strnew(size)))
		return (NULL);
	ft_strncpy(new_str, s, size);
	return (new_str);
}
