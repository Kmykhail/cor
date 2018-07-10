/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:05:14 by kshyshki          #+#    #+#             */
/*   Updated: 2018/04/18 12:05:16 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

int		print_error(int code, char *text, int *res)
{
	if (code == _USAGE)
	{
		ft_printf("Usage: ./corewar [-dump N | -n <some_player.cor> <...>\n");
		ft_printf("#### TEXT OUTPUT MODE ##################################\n");
		ft_printf(" -dump N : Dumps memory after N (>= 0) cycles then exits\n");
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
		ft_printf("%s has a code size that differ from what its header says\n",
		text);
	}
	if (code == TOO_MANY)
		ft_printf("Too many champions\n");
	return (1);
}

void	print_dump(t_main *main, int man_cycle)
{
	int i;

	i = 0;
	while (man_cycle-- > 0 && !main->finish)
		make_cycle(main);
	while (i < MEM_SIZE)
	{
		(!i) ? ft_printf("0x%.4x : ", i) : 0;
		((i % 64 == 0) && i != 0) ? ft_printf("\n0x%.4x : ", i) : 0;
		if (main->map[i] < 10 || (main->map[i] >= 0x0a && main->map[i] <= 0x0f))
		{
			if (i == MEM_SIZE - 1)
				ft_printf("0%x", main->map[i]);
			else
				ft_printf("0%x ", main->map[i]);
		}
		else
		{
			if (i == MEM_SIZE - 1)
				ft_printf("%x", main->map[i]);
			else
				ft_printf("%x ", main->map[i]);
		}
		i++;
	}
}

void	print_champion(t_main *main)
{
	int i;

	i = 0;
	while (i < main->cnt_pl)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", i + 1,\
		main->players[i]->exec_code, main->players[i]->player_name,\
		main->players[i]->comment);
		i++;
	}
	if (!main->last_live_player && main->cnt_pl == 1)
		main->last_live_player = main->players[main->cnt_pl - 1];
	ft_printf("Contestant %d \"%s\", has won !",\
	((main->last_live_player->nbr_pl * -1) + 256),\
	main->last_live_player->player_name);
}
