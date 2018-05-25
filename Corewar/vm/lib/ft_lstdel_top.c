/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 21:59:50 by kshyshki          #+#    #+#             */
/*   Updated: 2017/11/07 17:25:38 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel_top(t_list **alst)
{
	t_list *new_top;
	t_list *tmp;

	if (alst)
	{
		if (*alst)
		{
			tmp = *alst;
			new_top = tmp->next;
			free(tmp->content);
			free(tmp);
			*alst = NULL;
			*alst = new_top;
		}
	}
}
