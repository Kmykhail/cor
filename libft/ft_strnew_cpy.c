/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_cpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:56:32 by kshyshki          #+#    #+#             */
/*   Updated: 2017/11/06 15:00:03 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew_cpy(char *str)
{
	char	*new;

	if (!str)
		return (NULL);
	if (!(new = ft_strnew(ft_strlen(str))))
		return (NULL);
	ft_strcpy(new, str);
	return (new);
}
