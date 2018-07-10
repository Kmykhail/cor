/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:18:14 by kshyshki          #+#    #+#             */
/*   Updated: 2017/10/31 18:40:04 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*tmp_dst;

	if (!dst || !src)
		return (NULL);
	tmp_dst = dst;
	while (len--)
		*dst++ = (*src) ? *src++ : '\0';
	return (tmp_dst);
}
