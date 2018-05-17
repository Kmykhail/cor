/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_header.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:05:14 by kshyshki          #+#    #+#             */
/*   Updated: 2018/04/18 12:05:16 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "visual.h"

int 	is_numeric(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

void	print_dump(t_main *main)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		((i % 64 == 0) && i != 0) ? ft_printf("\n") : 0;
		if (main->map[i] < 10 || (main->map[i] >= 0x0a && main->map[i] <= 0x0f))
			(i == MEM_SIZE - 1) ? ft_printf("0%x", main->map[i]) : ft_printf("0%x ", main->map[i]);
		else
			(i == MEM_SIZE - 1) ? ft_printf("%x", main->map[i]) : ft_printf("%x ", main->map[i]);
		i++;
	}
	ft_printf("\n");
}

int		check_args(char **av, int ac, int *cycle)
{
	int i;
	int res;

	i = 0;
	res = 0;
	if (ac == 1)
		print_error(_USAGE, NULL, &res);
	while (++i < ac && ac > 1 && res >= 0)
	{
		if (i == 1 && !ft_strcmp(av[i], "-dump"))
			(i + 1 < ac && is_numeric(av[i + 1])) ? (res = 1) : print_error(_USAGE, NULL, &res);
		if (i == 1 && !ft_strcmp(av[i], "-nset"))
			(i + 1 < ac && is_numeric(av[i + 1])) ? (res = 3) : print_error(_USAGE, NULL, &res);
		else if (i == 1 && !ft_strcmp(av[i], "-n"))
			(i + 1 >= ac) ? print_error(_USAGE, NULL, &res) : (res = 2);
		else if (i == 1 && (ft_strcmp(av[i], "-dump") && ft_strcmp(av[i], "-n")))
			(!ft_strstr(av[i], ".cor")) ? print_error(_USAGE, NULL, &res) : 0;
		else if (i > 1 && is_numeric(av[i]))
		{
			(ft_strcmp(av[i - 1], "-dump") && ft_strcmp(av[i - 1], "-nset")) ? print_error(_USAGE, NULL, &res) : (*cycle = ft_atoi(av[i]));
			(i + 1 >= ac) ? print_error(_USAGE, NULL, &res) : 0;
		}
		else if (i > 1 && (!ft_strcmp(av[i], "-dump") || !ft_strcmp(av[i], "-n") || !ft_strcmp(av[i], "-nset")))
			print_error(_USAGE, NULL, &res);
	}
	return (res);
}

void	init_players(t_main *main, int indx)
{
	main->players[indx] = (t_player*)malloc(sizeof(t_player));
	main->players[indx]->nbr_pl = (!indx) ? -1 : (indx - ((indx * 2) + 1));
	main->players[indx]->ll_cycle = 0;
	main->players[indx]->live_cur_per = 0;
	main->players[indx]->live_last_per = 0;
	main->players[indx]->cnt_bot = 0;
	main->players[indx]->exec_code = 0;
}

void	init_struct(t_main *main)
{
	int i;

	i = 0;
	STEP = 0;
	main->cnt_pl = 0;
	main->cur_cycle = 0;
	main->cl_to_die = CYCLE_TO_DIE;
	main->cp_cl_to_die = CYCLE_TO_DIE;
	main->mx_check = 0;
	main->nbr_proc = 0;
	main->error = 0;
	main->finish = 0;
	while (i < MAX_PLAYERS)
	{
		main->filename[i] = NULL;
		main->players[i++] = NULL;
	}
    main->filename[i] = NULL;
	main->lst_proc = NULL;
	main->lst_changes = NULL;
	main->last_live_player = NULL;
	main->finish = 0;
	ft_table_label(main);
	ft_memset(main->map, 0, MEM_SIZE);
	ft_memset(main->arg, 0, 3);
}

int		main(int argc, char **argv)
{
	int			man_cycle;
	int 		mod;
	int 		i;
	t_main		main;

	man_cycle = 0;
	i = 0;
	if ((mod = check_args(argv, argc, &man_cycle)) < 0)
		exit (1);
	init_struct(&main);
	//system("afplay ~/Downloads/piu-piu-chpon-k.mp3 &");
	main.ddddd = open("/Users/kmykhail/Downloads/cor-master/ntext.txt", O_RDONLY | O_WRONLY | O_TRUNC, 0644);
	main.fffff = open("/Users/kmykhail/Downloads/cor-master/ntest.txt", O_RDONLY | O_WRONLY | O_TRUNC, 0644);
	dprintf(main.ddddd, "main.ddddd = %d\n", main.fffff);
	if (valid_bots(&main, argc, argv))
	{
		free_struct(&main);
		exit(1);
	}
	if (mod == 2 || mod == 3)
	{
		while (mod == 3 && man_cycle-- > 0)
			make_cycle(&main);
		(mod == 3) ? free_changes(&main) : 0;
		visual(&main);
	}
	else if (mod == 1 || !mod)
	{
		while (mod == 1 && man_cycle-- > 0)
			make_cycle(&main);
		while (i < MEM_SIZE && mod == 1)
		{
			(!i) ? ft_printf("0x%.4x : ", i) : 0;
			((i % 64 == 0) && i != 0) ? ft_printf("\n0x%.4x : ", i) : 0;
			if (main.map[i] < 10 || (main.map[i] >= 0x0a && main.map[i] <= 0x0f))
				(i == MEM_SIZE - 1) ? ft_printf("0%x", main.map[i]) : ft_printf("0%x ", main.map[i]);
			else
				(i == MEM_SIZE - 1) ? ft_printf("%x", main.map[i]) : ft_printf("%x ", main.map[i]);
			i++;
		}
		while (!main.finish && !mod)
		{
			make_cycle(&main);
		}
		if (!mod)
		{
			i = 0;
			while (i < main.cnt_pl)
			{
				ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", i + 1, \
				main.players[i]->exec_code, main.players[i]->player_name, main.players[i]->comment);
				i++;
			}
			if (!main.last_live_player && main.cnt_pl == 1)
				main.last_live_player = main.players[main.cnt_pl - 1];
			ft_printf("Contestant \"%s\", has won !", main.last_live_player->player_name);
		}
		ft_printf("\n");
		//free_struct(&main);
	}
	return (0);
}