/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:24:50 by kshyshki          #+#    #+#             */
/*   Updated: 2017/10/31 18:40:16 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len_s1;
	size_t	len_s2;

	if (n == 0)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (len_s1 >= len_s2 && len_s1 <= n)
		return (ft_memcmp(s1, s2, len_s1));
	else if (len_s2 >= len_s1 && len_s2 <= n)
		return (ft_memcmp(s1, s2, len_s2));
	else
		return (ft_memcmp(s1, s2, n));
}
