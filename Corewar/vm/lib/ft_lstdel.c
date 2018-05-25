/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 21:59:50 by kshyshki          #+#    #+#             */
/*   Updated: 2017/11/07 17:25:38 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_delrec(t_list *lst, void (*del)(void *, size_t))
{
	if (lst->next)
		ft_delrec(lst->next, del);
	del(lst->content, lst->content_size);
	free(lst);
}

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst && del)
	{
		if (*alst)
		{
			ft_delrec(*alst, del);
			*alst = NULL;
		}
	}
}
