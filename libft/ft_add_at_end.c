/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_at_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:18:50 by kshyshki          #+#    #+#             */
/*   Updated: 2017/11/06 17:49:15 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_add_at_end(char **str_arr, char *str)
{
	char	**res;
	int		len_arr;

	if (str_arr && str)
	{
		len_arr = ft_len_arr_str((const char **)str_arr);
		if (!(res = (char**)malloc(sizeof(char*) * (len_arr + 1))))
			return (NULL);
		ft_addlast(str, res, len_arr--);
		while (len_arr--)
			res[len_arr] = ft_strnew_cpy(str_arr[len_arr]);
		ft_strdel(str_arr);
		return (res);
	}
	else if (str_arr && !str)
		return (str_arr);
	return (NULL);
}
