/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:19:36 by kshyshki          #+#    #+#             */
/*   Updated: 2017/11/06 17:47:51 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dst_buf;
	const char	*src_buf;
	size_t		len;
	size_t		len_dst;

	dst_buf = dst;
	src_buf = src;
	len = size;
	while (*dst_buf && len--)
		dst_buf++;
	len_dst = dst_buf - dst;
	len = size - len_dst;
	if (!len)
		return (len_dst + ft_strlen(src_buf));
	while (*src_buf)
	{
		if (len != 1)
		{
			*dst_buf++ = *src_buf;
			len--;
		}
		src_buf++;
	}
	*dst_buf = '\0';
	return (len_dst + (src_buf - src));
}
