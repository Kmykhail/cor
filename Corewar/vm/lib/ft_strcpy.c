/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:17:47 by kshyshki          #+#    #+#             */
/*   Updated: 2017/10/31 18:36:01 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*tmp_dst;

	if (!dst)
		return (NULL);
	tmp_dst = dst;
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (tmp_dst);
}
