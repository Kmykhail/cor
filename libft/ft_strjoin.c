/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 21:17:06 by kshyshki          #+#    #+#             */
/*   Updated: 2017/11/23 17:54:51 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;

	if (!(new_str = ft_strnew(((s1) ? ft_strlen(s1) : 0) +
					((s2) ? ft_strlen(s2) : 0))))
		return (NULL);
	(s1) ? (ft_strcpy(new_str, s1)) : 0;
	(s2) ? (ft_strcat(new_str, s2)) : 0;
	return (new_str);
}
