/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 17:02:04 by giabanji          #+#    #+#             */
/*   Updated: 2018/04/30 17:02:07 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	count_bytes(char **exp, int i)
{
	g_bytes = 0;
	while (exp[++i] != NULL && nb_com(exp[i]) == 0)
	{
		if (exp[i][0] == 'r')
			g_bytes++;
		else if (exp[i][0] == '%')
		{
			g_bytes += 2;
			if ((g_int > 0 && g_int < 9) || g_int == 13 || g_int == 16)
				g_bytes += 2;
		}
		else
			g_bytes += 2;
	}
	if (g_int != 1 && g_int != 9 && g_int != 12 && g_int != 15)
		g_bytes++;
	g_bytes++;
}

void	write_arg_dir(char *str, int fd)
{
	char	**exp;
	char	*tmp;
	int		a;
	int		i;

	exp = ft_strsplit(str, '%');
	if (exp[0][0] == ':')
	{
		tmp = ft_strsub(exp[0], 1, ft_strlen(str) - 1);
		a = ret_url(tmp) - g_url_com;
		ft_memdel((void**)&tmp);
	}
	else
		a = ft_atoi(exp[0]);
	i = 2;
	if ((g_int > 0 && g_int < 9) || g_int == 13 || g_int == 16)
		i = 4;
	tmp = (char*)&a;
	while (--i >= 0)
		ft_putchar_fd(tmp[i], fd);
	free_split(exp);
}

int		ret_url(char *str)
{
	t_ls	*p;
	int		len;

	p = g_list;
	len = 0;
	while (p != NULL)
	{
		if (ft_strequ(p->name, str) == 0)
			len += p->size;
		else
			break ;
		p = p->next;
	}
	return (len);
}

int		find_sym(char *str, char c)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (i);
	}
	return (-1);
}

char	*add_sym(char *str, char c)
{
	char	*line;
	int		i;
	int		j;

	if (!str)
	{
		line = (char*)malloc(sizeof(char) * 2);
		line[0] = c;
		line[1] = '\0';
		return (line);
	}
	i = (int)ft_strlen(str);
	line = (char*)malloc(sizeof(char) * (i + 2));
	j = -1;
	while (++j < i)
		line[j] = str[j];
	line[j] = c;
	line[j + 1] = '\0';
	free(str);
	return (line);
}
