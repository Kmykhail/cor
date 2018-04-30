/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:14:32 by kshyshki          #+#    #+#             */
/*   Updated: 2017/11/05 12:08:48 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *src_buf;
	char *dst_buf;

	if (!dst || !src)
		return (NULL);
	src_buf = (char*)src;
	dst_buf = (char*)dst;
	if (src_buf < dst_buf)
	{
		src_buf += (len - 1);
		dst_buf += (len - 1);
		while (len-- > 0)
			*dst_buf-- = *src_buf--;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
