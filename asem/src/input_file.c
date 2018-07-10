/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 15:26:19 by giabanji          #+#    #+#             */
/*   Updated: 2018/05/03 15:26:21 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_arg(char **exp, int i, int fd)
{
	short int	b;
	char		**tmp;
	char		*as;

	if (exp[i][0] == 'r')
	{
		tmp = ft_strsplit(exp[i], 'r');
		ft_putchar_fd(ft_atoi(tmp[0]), fd);
		free_split(tmp);
	}
	else if (exp[i][0] == '%')
		write_arg_dir(exp[i], fd);
	else
	{
		b = (short int)ft_atoi(exp[i]);
		if (exp[i][0] == ':')
		{
			tmp = ft_strsplit(exp[i], ':');
			b = (short int)(ret_url(tmp[0]) - g_url_com);
			free_split(tmp);
		}
		as = (char*)&b;
		ft_putchar_fd(as[1], fd);
		ft_putchar_fd(as[0], fd);
	}
}

void	write_com(char **exp, int i, int fd)
{
	char	c;
	int		bit;

	count_bytes(exp, i);
	ft_putchar_fd(nb_com(exp[i]), fd);
	c = 0;
	bit = 7;
	while (exp[++i] != NULL && nb_com(exp[i]) == 0)
	{
		if (exp[i][0] == 'r')
			c |= 1 << (bit - 1);
		else if (exp[i][0] == '%')
			c |= 1 << bit;
		else
		{
			c |= 1 << bit;
			c |= 1 << (bit - 1);
		}
		bit -= 2;
	}
	if (g_int != 1 && g_int != 9 && g_int != 12 && g_int != 15)
		ft_putchar_fd(c, fd);
}

void	write_com_bin(int fd)
{
	t_ls	*p;
	char	**exp;
	int		i;

	p = g_list;
	while (p != NULL)
	{
		exp = ft_strsplit(p->com, ' ');
		g_url_com = ret_url(p->name);
		g_bytes = 0;
		i = -1;
		while (exp[++i] != NULL && exp[i][0] != '\0')
		{
			if (nb_com(exp[i]) > 0)
			{
				g_url_com += g_bytes;
				g_int = nb_com(exp[i]);
				write_com(exp, i, fd);
			}
			else
				write_arg(exp, i, fd);
		}
		free_split(exp);
		p = p->next;
	}
}

void	write_file2(int fd)
{
	t_ls	*p;
	int		i;
	char	*str;

	p = g_list;
	g_head.prog_size = 0;
	while (p != NULL)
	{
		g_head.prog_size += p->size;
		p = p->next;
	}
	str = (char*)&g_head.prog_size;
	i = 4;
	while (--i >= 0)
		ft_putchar_fd(str[i], fd);
	i = -1;
	while (++i < COMMENT_LENGTH)
		ft_putchar_fd(g_head.comment[i], fd);
	i = -1;
	while (++i < 4)
		ft_putchar_fd('\0', fd);
	write_com_bin(fd);
}

void	write_file(void)
{
	char	*bin_file;
	int		fd;
	int		i;
	char	*str;
	int		magic;

	bin_file = ft_strjoin(g_bin, "cor");
	fd = open(bin_file, O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU | S_IRWXG);
	magic = COREWAR_EXEC_MAGIC;
	str = (char*)&magic;
	i = 4;
	while (--i >= 0)
		ft_putchar_fd(str[i], fd);
	i = -1;
	while (++i < PROG_NAME_LENGTH)
		ft_putchar_fd(g_head.prog_name[i], fd);
	i = -1;
	while (++i < 4)
		ft_putchar_fd('\0', fd);
	write_file2(fd);
	close(fd);
	free(bin_file);
}
