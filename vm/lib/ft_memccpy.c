/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:13:22 by kshyshki          #+#    #+#             */
/*   Updated: 2017/11/18 14:12:57 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *tmp_src;

	if (!dst || !src)
		return (NULL);
	tmp_src = (unsigned char *)src;
	while (n--)
	{
		if (*tmp_src == (unsigned char)c)
			return (ft_memcpy(dst, tmp_src, 1) + 1);
		else
			dst = (ft_memcpy(dst, tmp_src++, 1)) + 1;
	}
	return (NULL);
}
