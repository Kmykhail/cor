/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bots.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:05:14 by kshyshki          #+#    #+#             */
/*   Updated: 2018/04/18 12:05:16 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	find_idex_to_start(t_main *main)
{
	int		size;
	int		coor;
	int		players;

	coor = 0;
	players = 0;
	size = MEM_SIZE;
	main->nbr_proc = main->cnt_pl;
	ft_memset(main->coor_of_p, 0, 4);
	size = size / main->cnt_pl;
	main->coor_of_p[players++] = 0;
	while (players < main->cnt_pl)
	{
		coor += size;
		main->coor_of_p[players++] = coor;
	}
}

void	check_magic_num(t_main *main, int *num, unsigned char *buff, int cnt)
{
	char	*free;

	free = NULL;
	if (cnt <= 3)
	{
		free = ft_itoa_base(buff[0], 10);
		*num += ft_atoi(free);
		ft_strdel(&free);
	}
	(cnt < 3) ? (*num = *num << 8) : 0;
	if (cnt == 3)
	{
		ERROR = (*num != COREWAR_EXEC_MAGIC) ? \
		print_error(MAGIC, main->filename[main->itr], 0) : 0;
		*num = 0;
	}
}

void	take_exec_code(t_main *main, t_player *pl, int cnt, unsigned char *buff)
{
	char *free;

	free = NULL;
	if (cnt >= PROG_NAME_LENGTH + 8 && cnt < PROG_NAME_LENGTH + 12 && !ERROR)
	{
		if (!pl->exec_code && buff[0] != 0 && cnt < PROG_NAME_LENGTH + 11)
		{
			free = ft_itoa_base(buff[0], 10);
			pl->exec_code += ft_atoi(free);
			pl->exec_code = pl->exec_code << 8;
		}
		else
		{
			free = ft_itoa_base(buff[0], 10);
			pl->exec_code += ft_atoi(free);
		}
		ft_strdel(&free);
	}
	if ((!pl->exec_code || pl->exec_code == CHAMP_MAX_SIZE) && \
	cnt == PROG_NAME_LENGTH + 12 && !ERROR)
		ERROR = print_error(SIZE_DIFFER, main->filename[main->itr], 0);
}

void	read_bots_helper(t_main *main, int cnt, t_player *pl, int num)
{
	ERROR += (cnt < TOTAL_SIZE && !ERROR) ? \
	print_error(EXEC_CODE_NULL, main->filename[main->itr], 0) : 0;
	if (!ERROR && ((num - main->coor_of_p[main->itr]) - pl->exec_code))
		ERROR = print_error(SIZE_DIFFER, main->filename[main->itr], 0);
	(!ERROR) ? init_vizual(main, main->itr, num - 1) : 0;
}

void	read_bots(t_main *main, t_player *pl, int i, int fd)
{
	int				num;
	int				cnt;
	unsigned char	buff[1];

	num = 0;
	cnt = 0;
	while ((read(fd, buff, 1) > 0) && !ERROR)
	{
		check_magic_num(main, &num, buff, cnt);
		if (cnt > 3 && cnt <= PROG_NAME_LENGTH && !ERROR)
		{
			pl->player_name[num++] = (cnt < PROG_NAME_LENGTH) ? buff[0] : '\0';
			num = (cnt == PROG_NAME_LENGTH) ? 0 : num;
		}
		take_exec_code(main, pl, cnt, buff);
		(LOOK_NAME) ? (pl->comment[num++] = buff[0]) : 0;
		if (cnt >= 2192 && !ERROR)
		{
			(!num || cnt == 2192) ? (num = main->coor_of_p[i]) : 0;
			main->map[num++] = buff[0];
		}
		cnt++;
	}
	read_bots_helper(main, cnt, pl, num);
}
