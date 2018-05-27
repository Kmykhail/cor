/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:52:48 by giabanji          #+#    #+#             */
/*   Updated: 2018/04/19 16:52:50 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "get_next_line.h"
# include "../../vm/lib/libft.h"
# include "../../vm/inc/op.h"

void			free_split(char **arr);
int				count_split(char *str, char c);
void			make_array(void);
int				nb_com(char *str);
void			add_data(char *str);
void			join_addr(char *str);
char			*add_sym(char *str, char c);
int				find_sym(char *str, char c);
void			add_label(char *str);
void			add_com(char *str);
void			add_arg(char *str);
void			write_file(void);
int				ret_url(char *str);
void			write_arg_dir(char *str, int fd);
void			count_bytes(char **exp, int i);
void			valid_name(char *str);

typedef struct	s_ls
{
	int			size;
	char		*name;
	char		*com;
	struct s_ls	*next;
}				t_ls;

t_header		g_head;
t_ls			*g_list;
char			*g_bin;
char			**g_com;
int				g_int;
int				g_url_com;
int				g_bytes;

#endif
