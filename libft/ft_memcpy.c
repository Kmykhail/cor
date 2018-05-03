/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:11:26 by kshyshki          #+#    #+#             */
/*   Updated: 2017/10/31 18:31:47 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*tmp_src;
	char	*tmp_dst;

	if (!dst || !src)
		return (NULL);
	tmp_dst = (char *)dst;
	tmp_src = (char *)src;
	while (n--)
		*tmp_dst++ = *tmp_src++;
	return (dst);
}
