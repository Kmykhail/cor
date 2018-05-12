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
			(i + 1 < ac && is_numeric(av[i + 1])) ? (res = 1) : 0;
		else if (i == 1 && !ft_strcmp(av[i], "-n"))
			(i + 1 >= ac) ? print_error(_USAGE, NULL, &res) : (res = 2);
		else if (i == 1 && (ft_strcmp(av[i], "-dump") && ft_strcmp(av[i], "-n")))
		{
			if (ft_strlen(av[i]) > 4)
				(ft_strcmp(ft_strsub(av[i], (ft_strlen(av[i]) - 4), ft_strlen(av[i])), ".cor")) ? print_error(_USAGE, NULL, &res) : 0;
			else
				print_error(_USAGE, NULL, &res);
		}
		else if (i > 1 && is_numeric(av[i]))
			(ft_strcmp(av[i - 1], "-dump")) ? print_error(_USAGE, NULL, &res) : (*cycle = ft_atoi(av[i]));
		else if (i > 1 && ft_strlen(av[i]) > 4)
			(ft_strcmp(ft_strsub(av[i], (ft_strlen(av[i]) - 4), ft_strlen(av[i])), ".cor")) ? print_error(_USAGE, NULL, &res) : 0;
		else if (i > 1 && (!ft_strcmp(av[i], "-dump") || !ft_strcmp(av[i], "-n")))
			print_error(_USAGE, NULL, &res);
		else if (i > 1 && (ft_strcmp(av[i], "-dump") || ft_strcmp(av[i], "-n")) && \
		ft_strlen(av[i]) <= 4 && !ft_strstr(av[i], ".cor"))
			print_error(_USAGE, NULL, &res);
	}
	return (res);
}

void	init_players(t_main *main, int indx)
{
	main->players[indx] = (t_player*)malloc(sizeof(t_player));
	main->players[indx]->bot_name = 0;
	main->players[indx]->comm = 0;
	main->players[indx]->nbr_pl = (!indx) ? -1 : (indx - ((indx * 2) + 1));
	main->players[indx]->ll_cycle = 0;
	main->players[indx]->live_cur_per = 0;
	main->players[indx]->live_last_per = 0;
	main->players[indx]->cnt_bot = 0;
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
	//main->var_crap = (t_crap*)malloc(sizeof(t_crap));
	main->finish = 0;
	ft_table_label(main);
	ft_memset(main->map, 0, MEM_SIZE);
	ft_memset(main->arg, 0, 3);
}

int		main(int argc, char **argv)
{
	int			man_cycle;
	int 		mod;
	t_main		main;

	man_cycle = 0;
	if ((mod = check_args(argv, argc, &man_cycle)) < 0)
		exit (1);
	printf("SFSFDSFD\n");
	init_struct(&main);
	main.ddddd = open("/Users/kmykhail/Downloads/cor-master/test.txt", O_RDONLY | O_WRONLY | O_TRUNC, 0644);
	main.fffff = open("/Users/kmykhail/Downloads/cor-master/ntest.txt", O_RDONLY | O_WRONLY | O_TRUNC, 0644);
	dprintf(main.ddddd, "main.ddddd = %d\n", main.fffff);
	if (valid_bots(&main, argc, argv))
	{
		//проверить лики
		exit(1);
	}
	if (mod == 2)
		visual(&main);
	else
	{
		while (man_cycle-- >= 0)
		{
			make_cycle(&main);
			printf("YYYYYYYY\n");
		}
	}
	/*while (++i < argc)
		(!ft_strcmp(argv[i], "-n")) ? visual(&main) : 0;*/
	return (0);
}