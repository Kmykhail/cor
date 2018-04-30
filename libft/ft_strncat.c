/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:19:19 by kshyshki          #+#    #+#             */
/*   Updated: 2017/10/31 18:39:44 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*tmp_s1;

	if (!s1 || !s2)
		return (NULL);
	tmp_s1 = s1;
	while (*s1)
		s1++;
	while (n-- && *s2)
		*s1++ = (*s2) ? *s2++ : '\0';
	*s1 = '\0';
	return (tmp_s1);
}
