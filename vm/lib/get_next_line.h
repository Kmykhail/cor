/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 14:16:25 by kshyshki          #+#    #+#             */
/*   Updated: 2017/11/26 18:23:00 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <sys/types.h>
# include "libft.h"

# define BUFF_SIZE 1

typedef struct		s_lststr
{
	char			*str;
	char			*tmp;
	int				fd;
	int				pos;
	struct s_lststr	*next;
}					t_lststr;

int					get_next_line(const int fd, char **line);

#endif
