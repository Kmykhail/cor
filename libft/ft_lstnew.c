/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 21:58:02 by kshyshki          #+#    #+#             */
/*   Updated: 2017/11/04 19:03:15 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*cpy_cont(void const *cont, size_t size)
{
	void	*new_cont;

	if (cont)
	{
		new_cont = (void *)malloc(size);
		ft_memcpy(new_cont, cont, size);
		return (new_cont);
	}
	else
		return (NULL);
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlst;

	if (!(newlst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	newlst->next = NULL;
	newlst->content = (content) ? cpy_cont(content, content_size) : NULL;
	newlst->content_size = (newlst->content) ? content_size : 0;
	return (newlst);
}
