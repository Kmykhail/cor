#include "main.h"

int		print_error(int code, char *text, int *res)
{
	if (code == _USAGE)
	{
		ft_putstr("Usage: ./corewar [-dump N -v N | -n <some_player.cor> <...>\n");
		ft_putstr("#### TEXT OUTPUT MODE ##################################\n");
		ft_putstr(" -dump N : Dumps memory after N (>= 0) cycles then exits\n");
		ft_putstr(" -v N 	: Verbosity levels, can be added together to enable several\n");
		ft_putstr("		- 0 : Show only essentials\n");
		ft_putstr("		- 1 : Show lives\n");
		ft_putstr("		- 2 : Show cycles\n");
		ft_putstr("		- 4 : Show operations (Params are NOT litteral ...)\n");
		ft_putstr("		- 8 : Show deaths\n");
		ft_putstr("		- 16 : Show PC movements (Except for jumps)\n");
		ft_putstr("#### NCURSES OUTPUT MODE ###############################\n");
		ft_putstr(" -n      : Ncurses output mode\n");
		ft_putstr("########################################################\n");
		*res = -1;
	}
	if (code == NO_READ_FILE)
	{
		ft_putstr("Can't read source file ");
		ft_putstr(text);
		ft_putstr("\n");
	}
	if (code == MAGIC)
	{
		ft_putstr("Error: File ");
		ft_putstr(text);
		ft_putstr(" has an invalid header\n");
	}
	if (code == EXEC_CODE_NULL)
	{
		ft_putstr("Error: File ");
		ft_putstr(text);
		ft_putstr(" is too small to be a champion\n");
	}
	if (code == SIZE_DIFFER)
	{
		//Error: File test.cor has a code size that differ from what its header says
		ft_putstr("Error: File ");
		ft_putstr(text);
		ft_putstr(" has a code size that differ from what its header says\n");
	}
	return (1);
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
/*
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
}*/
/*
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
		print_error(NO_READ_FILE, NULL, 0);
	while (cnt < TOTAL_SIZE && !main->error)
	{
		val += ft_atoi(ft_itoa_base(buff[cnt], 10));
		(cnt < 3) ? (val = val << 8) : 0;
		if (cnt == 3)
		{
			main->error += (val != COREWAR_EXEC_MAGIC) ? print_error(MAGIC, main->filename[i], 0) : 0;
			val = 0;
		}
		if (cnt > 3 && cnt < PROG_NAME_LENGTH && val && !main->error)
		{
			pl->player_name[c] = buff[cnt];
			pl->bot_name = 1;
			c++;
		}
		if (cnt == PROG_NAME_LENGTH - 1 && !main->error)
		{
			val = 0;
			printf("^^^pl->player_name[c]: %d\n", pl->player_name[c]);
			pl->player_name[c] = -1;
			printf("!!!pl->player_name[c]: %d\n", pl->player_name[c]);
			c = 0;
		}
		if (cnt >= PROG_NAME_LENGTH && val && !main->error)
		{
			pl->comment[c] = buff[cnt];
			pl->comm = 1;
			c++;
		}
		cnt++;
	}
	if (main->error)
		return ;
	pl->comment[c] = -1;
	if (!pl->bot_name || !pl->comm)
	{
		(!pl->bot_name) ? print_error(BOT_NAME, NULL, 0) : print_error(COMM, NULL, 0);
		return ;
	}
	pl->cnt_bot = push_code_tomass(main, fd, i);
}
*/

void	read_bots(t_main *main, t_player *pl, int i, int fd)
{
	int				num;
	int				cnt;
	unsigned char	buff[BUFFSIZE];

	num = 0;
	cnt = 0;
	while ((read(fd, buff, BUFFSIZE) > 0) && !ERROR)
	{
		if (cnt <= 3)
			num += ft_atoi(ft_itoa_base(buff[0], 10));
		(cnt < 3) ? (num = num << 8) : 0;
		if (cnt == 3)
		{
			ERROR = (num != COREWAR_EXEC_MAGIC) ? print_error(MAGIC, main->filename[i], 0) : 0;
			num = 0;
		}
		if (cnt > 3 && cnt < PROG_NAME_LENGTH && !ERROR)
			pl->player_name[num++] = buff[0];
		if (cnt == PROG_NAME_LENGTH && !ERROR)
		{
			pl->player_name[num] = '\0';
			num = 0;
		}
		if (cnt >= PROG_NAME_LENGTH + 8 && cnt < PROG_NAME_LENGTH + 12 && !ERROR)
		{
			if (!EXEC_CODE && buff[0] != 0 && cnt < PROG_NAME_LENGTH + 11)
			{
				EXEC_CODE += ft_atoi(ft_itoa_base(buff[0], 10));
				EXEC_CODE = EXEC_CODE << 8;	
			}
			else
				EXEC_CODE += ft_atoi(ft_itoa_base(buff[0], 10));
		}
		if (!EXEC_CODE && cnt == PROG_NAME_LENGTH + 12 && !ERROR)
			ERROR = print_error(SIZE_DIFFER, main->filename[i], 0);
		if (cnt >= 2192 && !ERROR)
		{
			(!num) ? (num = main->coor_of_p[i]) : 0;
			main->map[num++] = buff[0];
			EXEC_CODE--;
		}
		cnt++;
	}
	ERROR += (cnt < TOTAL_SIZE && !ERROR) ? print_error(EXEC_CODE_NULL, main->filename[i], 0) : 0;
	(!ERROR && EXEC_CODE != 0) ? (ERROR = print_error(SIZE_DIFFER, main->filename[i], 0)) : 0;
	(!ERROR) ? init_vizual(main, i, num - 1) : 0;
}

int		valid_bots(t_main *main, int ac, char **av)
{
	int	fd;
	int i;
	int c;

	i = 0;
	c = 0;
	fd = 0;
	while(ac-- > 1)
	{
		av++;
		if (ft_strcmp(*av, "-dump") && ft_strcmp(*av, "-n") && !is_numeric(*av))
			main->filename[c++] = ft_strdup(*av);
	}
	main->filename[c] = NULL;
	main->cnt_pl = c;
	find_idex_to_start(main);
	while (main->filename[i] && !main->error)
	{
		init_players(main, i);
		if ((fd = open(main->filename[i], O_RDONLY)) < 0)
	 		main->error = print_error(NO_READ_FILE, main->filename[i], 0);
		(!main->error) ? read_bots(main, main->players[i], i,  fd) : 0;
		(!main->error) ? close(fd) : 0;
		i++;
	}
	return ((main->error) ? 1 : 0);
}