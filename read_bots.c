#include "main.h"

int		print_error(int code, char *text, int *res)
{
	if (code == _USAGE)
	{
		ft_printf("Usage: ./corewar [-dump N -v N | -n <some_player.cor> <...>\n");
		ft_printf("#### TEXT OUTPUT MODE ##################################\n");
		ft_printf(" -dump N : Dumps memory after N (>= 0) cycles then exits\n");
		ft_printf(" -v N 	: Verbosity levels, can be added together to enable several\n");
		ft_printf("		- 0 : Show only essentials\n");
		ft_printf("		- 1 : Show lives\n");
		ft_printf("		- 2 : Show cycles\n");
		ft_printf("		- 4 : Show operations (Params are NOT litteral ...)\n");
		ft_printf("		- 8 : Show deaths\n");
		ft_printf("		- 16 : Show PC movements (Except for jumps)\n");
		ft_printf("#### NCURSES OUTPUT MODE ###############################\n");
		ft_printf(" -n      : Ncurses output mode\n");
		ft_printf("########################################################\n");
		*res = -1;
	}
	if (code == NO_READ_FILE)
		ft_printf("Can't read source file %s\n", text);
	if (code == MAGIC)
		ft_printf("Error: file %s has an invalid header\n", text);
	if (code == EXEC_CODE_NULL)
		ft_printf("Error: File %s is too small to be a champion\n", text);
	if (code == SIZE_DIFFER)
	{
		ft_printf("Error: File ");
		ft_printf("%s has a code size that differ from what its header says\n", text);
	}
	if (code == TOO_MANY)
		ft_printf("Too many champions\n");
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
	char			*free;

	num = 0;
	cnt = 0;
	while ((read(fd, buff, BUFFSIZE) > 0) && !ERROR)
	{
		if (cnt <= 3)
		{
			free = ft_itoa_base(buff[0], 10);
			num += ft_atoi(free);
			ft_strdel(&free);
		}
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
		if ((!pl->exec_code || pl->exec_code == CHAMP_MAX_SIZE) && cnt == PROG_NAME_LENGTH + 12 && !ERROR)
			ERROR = print_error(SIZE_DIFFER, main->filename[i], 0);
		(cnt >= PROG_NAME_LENGTH + 12 && cnt < 2188 && !ERROR) ? (pl->comment[num++] = buff[0]) : 0;
		if (cnt >= 2192 && !ERROR)
		{
			(!num || cnt == 2192) ? (num = main->coor_of_p[i]) : 0;
			main->map[num++] = buff[0];
		}
		cnt++;
	}
	ERROR += (cnt < TOTAL_SIZE && !ERROR) ? print_error(EXEC_CODE_NULL, main->filename[i], 0) : 0;
	if (!ERROR && ((num - pl->exec_code) % main->cnt_pl))
		ERROR = print_error(SIZE_DIFFER, main->filename[i], 0);
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
	ERROR += (c > MAX_PLAYERS) ? print_error(TOO_MANY, NULL, 0) : 0;
	main->cnt_pl = c;
	(!ERROR) ? find_idex_to_start(main) : 0;
	while (main->filename[i] && !main->error)
	{
		init_players(main, i);
		if ((fd = open(main->filename[i], O_RDONLY)) < 0)
	 		ERROR = print_error(NO_READ_FILE, main->filename[i], 0);
		(!ERROR) ? read_bots(main, main->players[i], i,  fd) : 0;
		(!ERROR) ? close(fd) : 0;
		i++;
	}
	return ((main->error) ? 1 : 0);
}