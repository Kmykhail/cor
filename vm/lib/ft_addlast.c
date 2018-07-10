/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:01:54 by kshyshki          #+#    #+#             */
/*   Updated: 2017/11/06 15:11:55 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_addlast(char *str, char **str_arr, size_t len)
{
	if (!str || !str_arr || !len)
		return ;
	str_arr[len] = NULL;
	str_arr[--len] = ft_strnew_cpy(str);
}
