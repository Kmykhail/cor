/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:02:31 by kshyshki          #+#    #+#             */
/*   Updated: 2017/11/26 18:20:32 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_lststr	*create_lststr(int fd)
{
	t_lststr	*lst;

	if (!(lst = (t_lststr*)malloc(sizeof(t_lststr))))
		return (NULL);
	if (!(lst->str = ft_strnew(0)))
		return (NULL);
	lst->tmp = lst->str;
	lst->fd = fd;
	lst->pos = 0;
	lst->next = NULL;
	return (lst);
}

static t_lststr	*search_fd(t_lststr **lst, int fd)
{
	t_lststr	*tmp;

	if (lst && !*lst)
	{
		*lst = create_lststr(fd);
		return (*lst);
	}
	else if (lst && *lst)
	{
		tmp = *lst;
		while (tmp->next || tmp->fd == fd)
		{
			if (tmp->fd != fd)
				tmp = tmp->next;
			else
			{
				tmp->tmp = tmp->str;
				return (tmp);
			}
		}
		return (tmp->next = create_lststr(fd));
	}
	else
		return (NULL);
}

static t_lststr	*dell_fd_node(t_lststr **lst, int fd)
{
	t_lststr	*tmp;

	if ((*lst)->fd == fd)
	{
		ft_strdel(&((*lst)->str));
		(*lst)->tmp = NULL;
		tmp = (*lst)->next;
		free(*lst);
		*lst = NULL;
		return (tmp);
	}
	else if ((*lst)->next)
	{
		(*lst)->next = dell_fd_node(&(*lst)->next, fd);
		return (*lst);
	}
	else
		return (*lst);
}

static int		if_n(t_lststr *fd_l, char **line, t_lststr **lst, int r)
{
	char	*n_p;

	if (fd_l->str && (n_p = ft_strchr(fd_l->str, '\n')))
	{
		fd_l->pos = n_p - fd_l->str;
		*line = ft_memmove(ft_strnew(fd_l->pos), fd_l->str, fd_l->pos);
		fd_l->tmp = fd_l->str;
		fd_l->str = ft_strsub(fd_l->str, fd_l->pos + 1,
				ft_strlen(fd_l->str) - fd_l->pos);
		ft_strdel(&fd_l->tmp);
		fd_l->tmp = fd_l->str;
		fd_l->pos = 0;
		return (1);
	}
	else if (fd_l->str && *(fd_l->str) && !r)
	{
		*line = ft_strcpy(ft_strnew(ft_strlen(fd_l->str)), fd_l->str);
		*lst = dell_fd_node(lst, fd_l->fd);
		return (1);
	}
	(!r) ? *lst = dell_fd_node(lst, fd_l->fd) : 0;
	fd_l->tmp = fd_l->str;
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_lststr	*lst;
	char			*buf;
	int				rd_cnt;
	t_lststr		*fd_l;

	if (fd < 0 || !line || !(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	fd_l = search_fd(&lst, fd);
	while ((rd_cnt = read(fd, buf, BUFF_SIZE)) > 0)
	{
		fd_l->pos += rd_cnt;
		fd_l->str = ft_strjoin(fd_l->str, buf);
		ft_strdel(&(fd_l->tmp));
		ft_bzero(buf, BUFF_SIZE);
		if (if_n(fd_l, line, &lst, rd_cnt))
		{
			ft_strdel(&buf);
			return (1);
		}
	}
	ft_strdel(&buf);
	if (if_n(fd_l, line, &lst, rd_cnt))
		return (1);
	return ((rd_cnt < 0) ? (-1) : (0));
}
