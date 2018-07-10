/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 22:02:47 by kshyshki          #+#    #+#             */
/*   Updated: 2017/10/31 18:28:18 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*res;

	if (!lst || !f)
		return (NULL);
	if (!(res = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new = f(lst);
	res = ft_lstnew(new->content, new->content_size);
	if (lst->next)
		res->next = ft_lstmap(lst->next, f);
	free(new);
	return (res);
}
