/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 15:18:14 by giabanji          #+#    #+#             */
/*   Updated: 2018/04/30 15:18:20 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_split(char **arr)
{
	int		i;

	if (!arr)
		return ;
	i = -1;
	while (arr[++i] != NULL)
		free((char*)arr[i]);
	free((char*)arr);
}

int		count_split(char *str, char c)
{
	int		i;
	char	**exp;

	exp = ft_strsplit(str, c);
	i = 0;
	while (exp[i] != NULL)
		i++;
	free_split(exp);
	return (i);
}

void	make_array(void)
{
	g_com = (char**)malloc(sizeof(char*) * 17);
	g_com[0] = ft_strdup("live");
	g_com[1] = ft_strdup("ld");
	g_com[2] = ft_strdup("st");
	g_com[3] = ft_strdup("add");
	g_com[4] = ft_strdup("sub");
	g_com[5] = ft_strdup("and");
	g_com[6] = ft_strdup("or");
	g_com[7] = ft_strdup("xor");
	g_com[8] = ft_strdup("zjmp");
	g_com[9] = ft_strdup("ldi");
	g_com[10] = ft_strdup("sti");
	g_com[11] = ft_strdup("fork");
	g_com[12] = ft_strdup("lld");
	g_com[13] = ft_strdup("lldi");
	g_com[14] = ft_strdup("lfork");
	g_com[15] = ft_strdup("aff");
	g_com[16] = 0;
}

int		nb_com(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (g_com[i] != NULL)
	{
		if (ft_strequ(g_com[i], str))
			return (i + 1);
		i++;
	}
	return (0);
}
