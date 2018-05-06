#include "main.h"

int		ft_print_error(int code)
{
	if (code == 1)
	{
		ft_putstr("Usage: ./corewar [-d N -s N -v N | -b --stealth | -n --stealth] [-a] <champion1.cor> <...>\n");
	}
	else if (code == 2)
		ft_putstr("Too many champions\n");
	else if (code == 3)
		ft_putstr("File not exist\n");
	else if (code == 4)
		ft_putstr("Can't read file\n");
	(code > 0) ? exit(1) : 0;
	return (0);
}

void 	find_idex_to_start(t_main *main)
{
	int 	k;
	int 	size;
	int 	coor;
	int 	players;

	k = 0;
	coor = 0;
	players = 0;
	size = 4096;
	main->cnt_pl = main->cnt_pl + 1;
	main->nbr_proc = main->cnt_pl;
	while (k < 4)
		main->coor_of_p[k++] = 0;
	size = size / main->cnt_pl;
	main->coor_of_p[players++] = 0;
	while (players < main->cnt_pl)
	{
		coor += size;
		main->coor_of_p[players++] = coor;
	}
}

int		push_code_tomass(t_main *main, int fd, int i)
{
	int c;
	int	l;
	unsigned char ch;

	c = 0;
	l = main->coor_of_p[i];
	while (read(fd, &ch, 1))
	{
		if (ch != 0)
			c = 1;
		if (c)
		{
			main->map[l] = ch;
			l++;
		}
	}
	init_vizual(main, i, l - 1);
	return (l);
}

void	read_bots(t_main *main, t_player *pl, int i,  int fd)
{
	int c;
	int cnt;
	int val;
	unsigned char buff[TOTAL_SIZE];

	cnt = 0;
	c = 0;
	val = 0;
	if (read(fd, buff, TOTAL_SIZE) < 0)
		ft_print_error(2);
	while (cnt < TOTAL_SIZE)
	{
		val += ft_atoi(ft_itoa_base(buff[cnt], 10));
		(cnt < 3) ? (val = val << 8) : 0;
		if (cnt == 3)
		{
			if (val != COREWAR_EXEC_MAGIC)
				ft_print_error(3);
			val = 0;
		}
		if (cnt > 3 && cnt < PROG_NAME_LENGTH && val)
		{
			pl->player_name[c] = buff[cnt];
			pl->bot_name = 1;
			c++;
		}
		if (cnt == PROG_NAME_LENGTH - 1)
		{
			val = 0;
			pl->player_name[c] = -1;
			c = 0;
		}
		if (cnt >= PROG_NAME_LENGTH && val)
		{
			pl->comment[c] = buff[cnt];
			pl->comm = 1;
			c++;
		}
		cnt++;
	}
	pl->comment[c] = -1;
	if (!pl->bot_name || !pl->comm)
		ft_print_error(4);
	pl->cnt_bot = push_code_tomass(main, fd, i);
}

void	valid_bots(t_main *main, int ac, char **av)
{
	int	fd;
	int i;
	int c;

	i = 0;
	c = 0;
	fd = 0;
	while(ac-- > 1)
	{
		if (av[c + 1][0] != '-')
		{
			main->filename[c] = ft_strdup(av[c + 1]);
			c++;
		}
	}
	main->cnt_pl = c - 1;
	find_idex_to_start(main);
	while (main->filename[i])
	{
		init_players(main, i);
		if ((fd = open(main->filename[i], O_RDONLY)) < 0)
			ft_print_error(1);
		/*СМОТРИ ДЛЫНЫ ДЛЯ ИМЕН, КОМЕНТОВ, ДОЛЖНО БЫТЬ ВЫРАВНИВАЮЩИЙ
		БАЙТЫ МЕЖДУ ИМЕНЕМ И КОМЕНТОМ (КАКИХ ТО 4-РИ БАЙТА)*/
		read_bots(main, main->players[i], i,  fd);
		close(fd);
		i++;
	}
}