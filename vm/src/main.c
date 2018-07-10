/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:05:14 by kshyshki          #+#    #+#             */
/*   Updated: 2018/04/18 12:05:16 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"
#include "../inc/visual.h"

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

int		check_args(char **av, int ac, int *cycle)
{
	int i;
	int res;

	i = 0;
	res = 0;
	(ac == 1) ? PRINT_ERROR : 0;
	while (++i < ac && ac > 1 && res >= 0)
	{
		if (i == 1 && !CMP(av[i], "-dump"))
			(i + 1 < ac && is_numeric(av[i + 1])) ? (res = 1) : PRINT_ERROR;
		else if (i == 1 && !CMP(av[i], "-n"))
			(i + 1 >= ac) ? PRINT_ERROR : (res = 2);
		else if (i == 1 && (CMP(av[i], "-dump") && CMP(av[i], "-n")))
			(!ft_strstr(av[i], ".cor")) ? PRINT_ERROR : 0;
		else if (i > 1 && is_numeric(av[i]))
		{
			(CMP(av[i - 1], "-dump")) ? PRINT_ERROR : (*cycle = ft_atoi(av[i]));
			(i + 1 >= ac) ? PRINT_ERROR : 0;
		}
		else if (i > 1 && (!CMP(av[i], "-dump") || !CMP(av[i], "-n")))
			PRINT_ERROR;
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
	main->cnt_pl = 0;
	main->cur_cycle = 0;
	main->cp_cur_cycle = 0;
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
	main->players[i] = NULL;
	main->filename[i] = NULL;
	main->lst_proc = NULL;
	main->lst_changes = NULL;
	main->last_live_player = NULL;
	ft_table_label(main);
	ft_memset(main->map, 0, MEM_SIZE);
	ft_memset(main->arg, 0, 3);
}

int		main(int argc, char **argv)
{
	int			man_cycle;
	int			mod;
	int			i;
	t_main		main;

	man_cycle = 0;
	i = 0;
	((mod = check_args(argv, argc, &man_cycle)) < 0) ? exit(1) : 0;
	init_struct(&main);
	if (valid_bots(&main, argc, argv))
	{
		free_struct(&main);
		exit(1);
	}
	(mod == 2) ? visual(&main) : 0;
	if (mod == 1 || !mod)
	{
		(mod == 1) ? print_dump(&main, man_cycle) : 0;
		while (!main.finish && !mod)
			make_cycle(&main);
		(!mod) ? print_champion(&main) : 0;
		ft_printf("\n");
		free_struct(&main);
	}
	return (0);
}
