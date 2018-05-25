/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:09:30 by giabanji          #+#    #+#             */
/*   Updated: 2018/04/19 18:09:35 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_name_comment(char *str)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = NULL;
	if (ft_strstr(str, ".name"))
	{
		tmp = ft_strsub(str, find_sym(str, '"') + 1, ft_strlen(str) - 6);
		while (++i <= PROG_NAME_LENGTH)
			g_head.prog_name[i] = '\0';
		i = -1;
		while (++i < (int)ft_strlen(tmp) - 1 && tmp[i] != '"')
			g_head.prog_name[i] = tmp[i];
	}
	else if (ft_strstr(str, ".comment"))
	{
		tmp = ft_strsub(str, find_sym(str, '"') + 1, ft_strlen(str) - 9);
		while (++i <= COMMENT_LENGTH)
			g_head.comment[i] = '\0';
		i = -1;
		while (++i < (int)ft_strlen(tmp) - 1 && tmp[i] != '"')
			g_head.comment[i] = tmp[i];
	}
	if (tmp)
		free(tmp);
}

void	route_comm(char *str)
{
	char	**exp;
	int		i;

	if (str[ft_strlen(str) - 1] == ':')
	{
		exp = ft_strsplit(str, ':');
		add_label(exp[0]);
		free_split(exp);
	}
	else if (nb_com(str) > 0)
		add_com(str);
	else if (str[0] == 'r' || str[0] == '%' || str[0] == '-'
		|| (str[0] >= '0' && str[0] <= '9') || str[0] == ':')
	{
		exp = ft_strsplit(str, ',');
		i = -1;
		while (exp[++i] != NULL)
			add_arg(exp[i]);
		free_split(exp);
	}
	else
	{
		ft_putstr("Error\n");
		exit(1);
	}
}

void	add_data(char *str)
{
	int		i;
	char	*comm;

	i = -1;
	comm = NULL;
	while (str[++i])
	{
		if (comm && (str[i] == '\t' || str[i] == '\v' || str[i] == ' '))
		{
			route_comm(comm);
			ft_memdel((void**)&comm);
		}
		else if (str[i] != '\t' && str[i] != '\v' && str[i] != ' '
			&& str[i] != '#' && str[i] != ';')
			comm = add_sym(comm, str[i]);
		else if (str[i] == '#' || str[i] == ';')
			break ;
	}
	if (comm)
	{
		route_comm(comm);
		ft_memdel((void**)&comm);
	}
}

void	read_file(int fd)
{
	char	*str;
	int		gnl;

	g_head.magic = 4;
	g_head.prog_size = 0;
	make_array();
	while ((gnl = get_next_line(fd, &str)) > 0)
	{
		if (ft_strstr(str, ".name") || ft_strstr(str, ".comment"))
		{
			valid_name(str);
			add_name_comment(str);
		}
		else if (str[0] != '\0' && str[0] != '#' && str[0] != ';')
			add_data(str);
		free(str);
	}
	if (gnl == -1)
		ft_putstr("GNL error\n");
	if (gnl == -1)
		exit(1);
	write_file();
}

int		main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
	{
		ft_putstr("Many arguments or issue arguments\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (argv[1][ft_strlen(argv[1]) - 1] != 's' ||
		argv[1][ft_strlen(argv[1]) - 2] != '.' || fd < 1 ||
		ft_strlen(argv[1]) < 3)
	{
		ft_putstr("File error\n");
		return (0);
	}
	g_bin = ft_strsub(argv[1], 0, ft_strlen(argv[1]) - 1);
	read_file(fd);
	close(fd);
	ft_putstr("Writing output program to ");
	ft_putstr(g_bin);
	ft_putstr("cor\n");
	return (0);
}
