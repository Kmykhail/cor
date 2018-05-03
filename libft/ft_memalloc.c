/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 20:56:27 by kshyshki          #+#    #+#             */
/*   Updated: 2017/10/31 17:49:04 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*new_mem;

	if ((new_mem = (void *)malloc(sizeof(void) * size)))
	{
		ft_bzero(new_mem, size);
		return (new_mem);
	}
	return (NULL);
}
