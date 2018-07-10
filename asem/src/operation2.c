/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:48:12 by giabanji          #+#    #+#             */
/*   Updated: 2018/05/02 16:48:15 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_size_com(void)
{
	t_ls	*p;

	p = g_list;
	while (p->next != NULL)
		p = p->next;
	if (g_int != 1 && g_int != 9 && g_int != 12 && g_int != 15)
		p->size += 2;
	else
		p->size += 1;
}

void	add_label(char *str)
{
	t_ls	*p;
	t_ls	*a;

	if (!g_list)
	{
		g_list = (t_ls*)malloc(sizeof(t_ls));
		g_list->next = NULL;
		g_list->com = ft_strnew(0);
		g_list->size = 0;
		g_list->name = ft_strdup(str);
	}
	else
	{
		p = g_list;
		while (p->next != NULL)
			p = p->next;
		a = p;
		p = (t_ls*)malloc(sizeof(t_ls));
		p->next = NULL;
		p->com = ft_strnew(0);
		p->size = 0;
		p->name = ft_strdup(str);
		a->next = p;
	}
}

void	add_arg(char *str)
{
	t_ls	*p;
	char	*tmp;

	p = g_list;
	while (p->next != NULL)
		p = p->next;
	tmp = ft_strjoin(p->com, " ");
	ft_memdel((void**)&p->com);
	p->com = ft_strjoin(tmp, str);
	ft_memdel((void**)&tmp);
	if (str[0] == 'r')
		p->size += 1;
	else if (str[0] == '%')
	{
		if ((g_int > 0 && g_int < 9) || g_int == 13 || g_int == 16)
			p->size += 4;
		else
			p->size += 2;
	}
	else
		p->size += 2;
}

void	add_com(char *str)
{
	t_ls	*p;
	char	*tmp;

	if (!g_list)
	{
		g_list = (t_ls*)malloc(sizeof(t_ls));
		g_list->next = NULL;
		g_list->com = ft_strnew(0);
		g_list->size = 0;
		g_list->name = ft_strnew(0);
	}
	p = g_list;
	while (p->next != NULL)
		p = p->next;
	if (!p->com)
		p->com = ft_strdup(str);
	else
	{
		tmp = ft_strjoin(p->com, " ");
		ft_memdel((void**)&p->com);
		p->com = ft_strjoin(tmp, str);
		ft_memdel((void**)&tmp);
	}
	g_int = nb_com(str);
	add_size_com();
}
