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

/*
int		make_cycle(t_main *main)
{
	main->cur_cycle++;
	main->lst_proc->index++;
	main->lst_proc->next->index++;
	if (main->cur_cycle == MEM_SIZE / 2)
		main->finish = 1;
	return (1);
}*/

/*
static void	init_main(t_main *main)
{
	t_process	*proc1;
	t_process	*proc2;
	t_changes	*chang1;
	t_changes	*chang2;
	t_player	*player1;
	t_player	*player2;
	player1 = (t_player*)malloc(sizeof(t_player));
	player2 = (t_player*)malloc(sizeof(t_player));
	ft_bzero(player1->player_name, PROG_NAME_LENGTH + 1);
	ft_bzero(player2->player_name, PROG_NAME_LENGTH + 1);
	player1->ll_cycle = 0;
	player2->ll_cycle = 0;
	player1->live_cur_per = 1;
	player2->live_cur_per = 88;
	player1->live_last_per = 1024;
	player2->live_last_per = 1;
	main->players[0] = player1;
	main->players[1] = player2;
	main->players[2] = player2;
	player1->nbr_pl = -1;
	player2->nbr_pl = -2;
	player1->player_name[0] = 'P';
	player1->player_name[1] = 'l';
	player1->player_name[2] = '1';
	player2->player_name[0] = 'P';
	player2->player_name[1] = 'l';
	player2->player_name[2] = '2';
	main->cnt_pl = 3;
	proc1 = (t_process*)malloc(sizeof(t_process));
	proc2 = (t_process*)malloc(sizeof(t_process));
	proc1->next = proc2;
	main->lst_proc = proc1;
	proc2->next = NULL;
	proc1->index = 0;
	proc2->index = 0;
	proc1->nbr_pl = -1;
	proc2->nbr_pl = -2;
	main->cur_cycle = 0;
	main->nbr_proc = 2;
	main->cl_to_die = CYCLE_TO_DIE;
	main->lst_changes = NULL;
	chang1 = (t_changes*)malloc(sizeof(t_changes));
	chang2 = (t_changes*)malloc(sizeof(t_changes));
	chang1->next = chang2;
	chang2->next = NULL;
	chang1->start = 0;
	chang1->finish = 63;
	chang1->cycle_init = 0;
	chang2->cycle_init = 0;
	chang2->start = CHAMP_MAX_SIZE + 1;
	chang2->finish = CHAMP_MAX_SIZE + 63;
	chang1->process = proc1;
	chang2->process = proc2;
	main->lst_changes = chang1;
	ft_memset(main->map, 0, MEM_SIZE);
	main->map[5] = 1;
	main->map[63] = 1;
	main->last_live_player = NULL;
	main->finish = 0;
}
*/

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

void	init_struct(t_main *main, int argc)
{
	int i;

	i = 0;
	STEP = 0;
	main->tmp_fork = 0;
	main->cnt_pl = 0;
	main->cmd_cycle = 0;
	main->cur_cycle = 0;
	main->cl_to_die = CYCLE_TO_DIE;
	main->nbr_proc = 0;
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
	main->var_crap = (t_crap*)malloc(sizeof(t_crap));
	main->finish = 0;
	ft_table_label(main);
	ft_memset(main->map, 0, MEM_SIZE);
	ft_memset(main->arg, 0, 3);
}

int		main(int argc, char **argv)
{
	int			i;
	t_main		main;

	i = 0;
	if (argc == 1)
	{
		printf("Wrong\n");
		return (1);
	}
	init_struct(&main, argc);
	main.ddddd = open("/Users/kmykhail/corewar_kmykhail/test.txt", O_RDONLY | O_WRONLY | O_TRUNC, 0644);
	main.var_crap->itr = 0;
	valid_bots(&main, argc, argv);
	/*while (main.lst_proc)
	{
		printf("proc_cmd_cycle:%d\n", main.lst_proc->cmd_cycle);
		main.lst_proc = main.lst_proc->next;
	}
	exit(1);*/
	while (++i < argc)
		(!ft_strcmp(argv[i], "-n")) ? visual(&main) : 0;
	return (0);
}