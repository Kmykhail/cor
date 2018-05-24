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
	else if (ch == KEY_DOWN)
		win->one_step = 10;
	else if (ch == KEY_LEFT)
		win->one_step = 100;
	else if (ch == KEY_RIGHT)
		win->one_step = 1000;
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
	// dprintf(3, "7777 1 window.bar %p\n", win->bar);
	earse_process(win);
	// dprintf(3, "7777 2 window.bar %p\n", win->bar);
	if (main->cur_cycle == 0)
	{
		// dprintf(3, "7777 3 window.bar %p\n", win->bar);
		fill_start_changes(main->lst_changes, win);
		// dprintf(3, "7777 4 window.bar %p\n", win->bar);
		main->lst_changes = NULL;
	}
	else if (fill_changes(main->lst_changes, win, &main->cur_cycle))
	{
		// dprintf(3, "7777 5 window.bar %p\n", win->bar);
		main->lst_changes = NULL;
	}
	// dprintf(3, "7777 6 window.bar %p\n", win->bar);
	fill_process(main, win);
	// dprintf(3, "7777 7 window.bar %p\n", win->bar);
	if (fill_lives(win, win->lives, &main->cur_cycle))
	{
		// dprintf(3, "7777 8 window.bar %p\n", win->bar);
		win->lives = NULL;
		// dprintf(3, "7777 9 window.bar %p\n", win->bar);
	}
	fill_map(win, win->color, main->map);
	// dprintf(3, "7777 10 window.bar %p\n", win->bar);
	fill_tab(win, main);
	// dprintf(3, "7777 11 window.bar %p\n", win->bar);
	print_usage(win);
	// dprintf(3, "7777 12 window.bar %p\n", win->bar);
}

int			visual(t_main *main)
{
	t_vis	window;
	clock_t	start;

	init_window(&window);
	ft_memset(window.color, EMPTY_CELL, MEM_SIZE);
	//printf("ONE\n");
	while (key_handler(&window))
	{

		start = clock();
		// dprintf(3, "7777 F window.bar %p\n", window.bar);
		fill_all(&window, main);
		// dprintf(3, "7777 G window.bar %p\n", window.bar);
		if ((window.paused == RUN || window.one_step > 0) && !main->finish)
		{
			while (window.one_step > 0) // comment if you want back to normal mode
			{							// comment if you want back to normal mode
				// dprintf(3, "7777 A window.bar %p\n", window.bar);
				if (!make_cycle(main))
					break ;
				(window.one_step) ? window.one_step -= 1 : 0;
				///(window.one_step) ? window.one_step = 0 : 0; //uncomment end dell line before when finish
				// dprintf(3, "7777 B window.bar %p\n", window.bar);
			}							// comment if you want back to normal mode
			// dprintf(3, "7777 C window.bar %p\n", window.bar);
		}
		/*if (main->finish)
			printf("^^^: %s\n", main->last_live_player->player_name);*/
		// dprintf(3, "7777 D window.bar %p\n", window.bar);
		(main->finish) ? print_winner(main, &window) : 0;
		usleep((CLOCKS_PER_SEC - (clock() - start)) / window.speed);
		// dprintf(3, "7777 E window.bar %p\n", window.bar);
	}
	return (0);
}
