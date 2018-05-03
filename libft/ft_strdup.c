/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:17:24 by kshyshki          #+#    #+#             */
/*   Updated: 2017/10/31 18:37:02 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new_str;
	char	*tmp;

	if (!s1)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	tmp = new_str;
	if (new_str)
	{
		while (*s1)
			*new_str++ = *s1++;
		*new_str = '\0';
	}
	return (tmp);
}
