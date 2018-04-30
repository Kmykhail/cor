/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:01:44 by kshyshki          #+#    #+#             */
/*   Updated: 2018/04/18 12:01:46 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"
#include "main.h"

static int	key_handler(t_vis *win)
{
	int ch;

	ch = getch();
	if (ch == 'q')
	{
		delwin(win->map);
		delwin(win->bar);
		endwin();
		return (0);
	}
	else if (ch == 'w')
		(win->speed > 1) ? win->speed-- : 0;
	else if (ch == 'e')
		win->speed++;
	else if (ch == ' ')
		win->paused = (!ft_strcmp(win->paused, RUN)) ? PAUSE : RUN;
	else if (ch == KEY_UP)
		win->one_step = 1;
	else if (ch == KEY_RESIZE)
	{
		endwin();
		clear();
		init_window(win);
	}
	return (1);
}

static void	earse_process(t_vis *win)
{
	int i;

	i = -1;
	while (++i < MEM_SIZE)
		if (win->color[i] >= FST_PL_PROC && win->color[i] <= ECELL_PL_PROC)
			win->color[i] -= SHIFT_PR;
}

static void	fill_all(t_vis *win, t_main *main)
{
	/*while (1)
		;*/
	earse_process(win);
	if (main->cur_cycle == 0)
	{
		fill_start_changes(main->lst_changes, win);
		main->lst_changes = NULL;
	}
	else if (fill_changes(main->lst_changes, win, &main->cur_cycle))
		main->lst_changes = NULL;
	fill_process(main, win);
	if (fill_lives(win, win->lives, &main->cur_cycle))
		win->lives = NULL;
	fill_map(win, win->color, main->map);
	fill_tab(win, main);
	print_usage(win);
}

int			visual(t_main *main)
{
	t_vis	window;
	clock_t	start;

    //printf("BBBBBBBBBB\n");
//__________________________________________________________________
	// main->lst_proc = (t_process*)malloc(sizeof(t_process));
	// main->lst_changes = (t_changes*)malloc(sizeof(t_changes));


	// main->lst_proc->index =  main->coor_of_p[main->test_i];
	// main->lst_proc->nbr_pl = main->players[main->test_i]->nbr_pl;
	// main->lst_proc->live = 0;
	// main->lst_proc->next = NULL;

	// main->lst_changes->start =  main->coor_of_p[main->test_i];
	// main->lst_changes->finish = main->coor_of_p[main->test_i] + main->test_l;
	// main->lst_changes->cycle_init = 0;
	// main->lst_changes->process = main->lst_proc;
	// main->lst_changes->next = NULL;
//__________________________________________________________________
   	/*printf("proc->index[0]%x\n", main->lst_proc->nbr_pl);
   	printf("proc->index[1]%x\n", main->lst_proc->next->nbr_pl);
   	printf("change->start[0]%d\n", main->lst_changes->start);
   	printf("change->start[1]%d\n", main->lst_changes->next->start);
	exit(1);*/
	init_window(&window);
	ft_memset(window.color, EMPTY_CELL, MEM_SIZE);
	//printf("ONE\n");
	while (key_handler(&window))
	{
		start = clock();
		fill_all(&window, main);
		if ((window.paused == RUN || window.one_step == 1) && !main->finish)
		{
			if (!make_cycle(main))
				break ;
			while (1)
				printf("STEP: %d\n", STEP);
			(window.one_step) ? window.one_step = 0 : 0;
		}
		(main->finish) ? print_winner(main, &window) : 0;
		usleep((CLOCKS_PER_SEC - (clock() - start)) / window.speed);
	}
	return (0);
}
