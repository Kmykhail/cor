/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dell_arr_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 10:16:49 by kshyshki          #+#    #+#             */
/*   Updated: 2018/02/22 10:16:54 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dell_arr_str(char ***spl_data)
{
	int i;

	i = 0;
	while ((*spl_data)[i])
		ft_strdel(&(*spl_data)[i++]);
	free(*spl_data);
	return (1);
}
