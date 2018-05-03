/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_fill_charts.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:05:14 by kshyshki          #+#    #+#             */
/*   Updated: 2018/04/18 12:05:16 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	fill_chart_last_per(t_vis *win, t_main *main)
{
	int			i;
	int			j;
	unsigned	sum;
	double		line_cost;

	i = -1;
	sum = 0;
	while (++i < main->cnt_pl)
		sum += main->players[i]->live_last_per;
	line_cost = 50.0 / sum;
	wmove(win->bar, LN_LP_LN + 1, SHIFT + 1);
	i = -1;
	while (++i < main->cnt_pl)
	{
		j = -1;
		while (++j < line_cost * main->players[i]->live_last_per)
		{
			wattron(win->bar, COLOR_PAIR(i + 1) | A_BOLD);
			waddch(win->bar, '-');
			wattroff(win->bar, COLOR_PAIR(i + 1) | A_BOLD);
		}
	}
	waddch(win->bar, ']');
}

void	fill_chart_cur_per(t_vis *win, t_main *main)
{
	int			i;
	int			j;
	unsigned	sum;
	double		line_cost;

	i = -1;
	sum = 0;
	while (++i < main->cnt_pl)
		sum += main->players[i]->live_cur_per;
	line_cost = 50.0 / sum;
	wmove(win->bar, LN_CP_LN + 1, SHIFT + 1);
	i = -1;
	while (++i < main->cnt_pl)
	{
		j = -1;
		while (++j < line_cost * main->players[i]->live_cur_per)
		{
			wattron(win->bar, COLOR_PAIR(i + 1) | A_BOLD);
			waddch(win->bar, '-');
			wattroff(win->bar, COLOR_PAIR(i + 1) | A_BOLD);
		}
	}
	waddch(win->bar, ']');
}
