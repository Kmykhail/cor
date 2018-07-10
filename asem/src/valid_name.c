/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 16:29:47 by giabanji          #+#    #+#             */
/*   Updated: 2018/05/24 16:29:50 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	valid_after_text(char *str, int i)
{
	while (str[++i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\v')
		{
			ft_putstr("Error\n");
			exit(1);
		}
	}
}

void	valid_text(char *str, int i)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	if (str[i] == '"')
		a = 1;
	while (str[++i])
	{
		if (str[i] == '"')
		{
			b = 1;
			break ;
		}
	}
	if (a == 0 || b == 0)
	{
		ft_putstr("Error\n");
		exit(1);
	}
	valid_after_text(str, i);
}

void	valid_name(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	if (ft_strstr(str, ".name"))
		tmp = ft_strdup(".name");
	else
		tmp = ft_strdup(".comment");
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v')
		i++;
	j = -1;
	while (tmp[++j])
	{
		if (tmp[j] != str[i])
		{
			ft_putstr("Error\n");
			exit(1);
		}
		i++;
	}
	ft_memdel((void**)&tmp);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v')
		i++;
	valid_text(str, i);
}
