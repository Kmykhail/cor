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

#include "main.h"

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

void	read_bots(t_main *main, t_player *pl, int i, int fd)
{
	int				num;
	int				cnt;
	unsigned char	buff[1];
	char			*free;

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
		(cnt >= PROG_NAME_LENGTH + 12 && cnt < 2188 && !ERROR) ? \
		(pl->comment[num++] = buff[0]) : 0;
		if (cnt >= 2192 && !ERROR)
		{
			(!num || cnt == 2192) ? (num = main->coor_of_p[i]) : 0;
			main->map[num++] = buff[0];
		}
		cnt++;
	}
	ERROR += (cnt < TOTAL_SIZE && !ERROR) ? \
	print_error(EXEC_CODE_NULL, main->filename[i], 0) : 0;
	if (!ERROR && ((num - pl->exec_code) % main->cnt_pl))
		ERROR = print_error(SIZE_DIFFER, main->filename[i], 0);
	(!ERROR) ? init_vizual(main, i, num - 1) : 0;
}

int		valid_bots(t_main *main, int ac, char **av)
{
	int	fd;
	int i;

	i = 0;
	fd = 0;
	while (ac-- > 1)
	{
		av++;
		if (ft_strcmp(*av, "-dump") && ft_strcmp(*av, "-n") && !is_numeric(*av))
			main->filename[main->cnt_pl++] = ft_strdup(*av);
	}
	main->filename[main->cnt_pl] = NULL;
	ERROR += (main->cnt_pl > MAX_PLAYERS) ? print_error(TOO_MANY, NULL, 0) : 0;
	(!ERROR) ? find_idex_to_start(main) : 0;
	while (main->filename[i] && !main->error)
	{
		main->itr = i;
		init_players(main, i);
		if ((fd = open(main->filename[i], O_RDONLY)) < 0)
			ERROR = print_error(NO_READ_FILE, main->filename[i], 0);
		(!ERROR) ? read_bots(main, main->players[i], i, fd) : 0;
		(!ERROR) ? close(fd) : 0;
		i++;
	}
	return ((main->error) ? 1 : 0);
}
