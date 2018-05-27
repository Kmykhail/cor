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

#include "../inc/visual.h"
#include "../inc/main.h"

int				make_cycle(t_main *m)
{
	make_cycle_second(m, &m->lst_proc);
	if (m->cp_cl_to_die == m->cur_cycle && m->cl_to_die == U_INT)
	{
		m->finish = 1;
		m->nbr_proc = 0;
		m->cur_cycle++;
	}
	return (1);
}

static int		key_handler(t_vis *win)
{
	int			ch;

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

static void		earse_process(t_vis *win)
{
	int			i;

	i = -1;
	while (++i < MEM_SIZE)
		if (win->color[i] >= FST_PL_PROC && win->color[i] <= ECELL_PL_PROC)
			win->color[i] -= SHIFT_PR;
}

static void		fill_all(t_vis *win, t_main *main)
{
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

int				visual(t_main *main)
{
	t_vis		window;
	clock_t		start;

	init_window(&window);
	window.tmp = 0;
	window.i = 0;
	ft_memset(window.color, EMPTY_CELL, MEM_SIZE);
	while (key_handler(&window))
	{
		start = clock();
		fill_all(&window, main);
		if ((window.paused == RUN || window.one_step > 0) && !main->finish)
		{
			if (!make_cycle(main))
				break ;
			(window.one_step) ? window.one_step -= 1 : 0;
			(window.one_step) ? window.one_step = 0 : 0;
		}
		(main->finish) ? print_winner(main, &window) : 0;
		usleep((CLOCKS_PER_SEC - (clock() - start)) / window.speed);
	}
	return (0);
}
