/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:05:14 by kshyshki          #+#    #+#             */
/*   Updated: 2018/04/18 12:05:16 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	init_pairs(void)
{
	init_pair(FIRST_PLAYER, COLOR_GREEN, COLOR_BLACK);
	init_pair(SECOND_PLAYER, COLOR_BLUE, COLOR_BLACK);
	init_pair(THIRD_PLAYER, COLOR_RED, COLOR_BLACK);
	init_pair(FOURTH_PLAYER, COLOR_CYAN, COLOR_BLACK);
	init_pair(FST_PL_PROC, COLOR_BLACK, COLOR_GREEN);
	init_pair(SCND_PL_PROC, COLOR_BLACK, COLOR_BLUE);
	init_pair(THRD_PL_PROC, COLOR_BLACK, COLOR_RED);
	init_pair(FRTH_PL_PROC, COLOR_BLACK, COLOR_CYAN);
	init_color(COLOR_WHITE, 500, 500, 500);
	init_pair(ECELL_PL_PROC, COLOR_BLACK, COLOR_WHITE);
	init_pair(TAB, COLOR_WHITE, COLOR_WHITE);
	init_pair(EMPTY_CELL, COLOR_WHITE, COLOR_BLACK);
	init_pair(WHITE_CW, COLOR_WHITE, COLOR_BLACK);
	init_pair(FST_PL_LIVE, COLOR_WHITE, COLOR_GREEN);
	init_pair(SCND_PL_LIVE, COLOR_WHITE, COLOR_BLUE);
	init_pair(THRD_PL_LIVE, COLOR_WHITE, COLOR_RED);
	init_pair(FRTH_PL_LIVE, COLOR_WHITE, COLOR_CYAN);
	init_pair(FST_PL_MARKER, COLOR_GREEN, COLOR_BLACK);
	init_pair(SCND_PL_MARKER, COLOR_BLUE, COLOR_BLACK);
	init_pair(THRD_PL_MARKER, COLOR_RED, COLOR_BLACK);
	init_pair(FRTH_PL_MARKER, COLOR_CYAN, COLOR_BLACK);
}

void		print_winner(t_main *main, t_vis *win)
{
	if (main->last_live_player)
	{
		wattron(win->bar, COLOR_PAIR(WHITE_CW) | A_BOLD);
		mvwprintw(win->bar, WINNER_LN, SHIFT, "%s", WINNER);
		mvwprintw(win->bar, WINNER_LN + 2, SHIFT, "%s", QIUTKEY);
		wattroff(win->bar, COLOR_PAIR(WHITE_CW) | A_BOLD);
		wattron(win->bar,
				COLOR_PAIR((UCH) (main->last_live_player->nbr_pl * -1)) | A_BOLD);
		mvwprintw(win->bar, WINNER_LN, SHIFT + ft_strlen(WINNER),
				  "%s", main->last_live_player->player_name);
		wattroff(win->bar,
				 COLOR_PAIR((UCH) (main->last_live_player->nbr_pl * -1)) | A_BOLD);
		refresh_windows(win);
	}
}

void		print_usage(t_vis *win)
{
	wattron(win->bar, COLOR_PAIR(WHITE_CW) | A_BOLD);
	mvwprintw(win->bar, USAGE_LN, SHIFT, "%s", USAGE);
	mvwprintw(win->bar, USAGE_LN + 1, SHIFT,
			"%s", "\'q\' - quit");
	mvwprintw(win->bar, USAGE_LN + 2, SHIFT,
			"%s", "\'w\' - reduce speed");
	mvwprintw(win->bar, USAGE_LN + 3, SHIFT,
			"%s", "\'e\' - increase a speed");
	mvwprintw(win->bar, USAGE_LN + 4, SHIFT,
			"%s", "\'space\' - RUN/PAUSE");
	mvwprintw(win->bar, USAGE_LN + 5, SHIFT,
			"%s", "\'KEY_UP\' - one step");
	wattroff(win->bar, COLOR_PAIR(WHITE_CW) | A_BOLD);
}

void		refresh_windows(t_vis *win)
{
	wrefresh(win->map);
	wrefresh(win->bar);
	
	refresh();
}

int			init_window(t_vis *win)
{
	initscr();
	cbreak();
	curs_set(0);
	nodelay(stdscr, TRUE);
	noecho();
	keypad(stdscr, TRUE);
	win->map = newwin(MAP_HEIGHT, MAP_WIDTH, 0, 0);
	wresize(win->map, MAP_HEIGHT, MAP_WIDTH);
	win->bar = newwin(MAP_HEIGHT, COLS - MAP_WIDTH, 0, MAP_WIDTH);
	nodelay(win->map, TRUE);
	keypad(win->map, TRUE);
	nodelay(win->bar, TRUE);
	keypad(win->bar, TRUE);
	win->paused = PAUSE;
	win->speed = BASE_SPEED;
	start_color();
	init_pairs();
	win->lives = NULL;
	win->one_step = 0;
	refresh();
	return (1);
}
