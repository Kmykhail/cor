/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 21:05:44 by kshyshki          #+#    #+#             */
/*   Updated: 2017/10/31 18:39:19 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	char	*res;

	if (!s || !f)
		return (NULL);
	if (!(new_str = ft_strnew(ft_strlen(s))))
		return (NULL);
	res = new_str;
	while (s && *s)
		*new_str++ = f(*s++);
	return (res);
}
