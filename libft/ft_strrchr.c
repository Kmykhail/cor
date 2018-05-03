/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:20:24 by kshyshki          #+#    #+#             */
/*   Updated: 2017/10/31 18:41:24 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *res;

	res = NULL;
	if (!s)
		return (NULL);
	while (*s)
		(*s == (char)c) ? (res = (char *)s++) : s++;
	((char)c == '\0') ? (res = (char *)s) : 0;
	return (res);
}
