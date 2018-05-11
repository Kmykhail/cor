/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_fill_bar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:05:14 by kshyshki          #+#    #+#             */
/*   Updated: 2018/04/18 12:05:16 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	fill_boxes(t_vis *win)
{
	wattron(win->map, COLOR_PAIR(TAB));
	box(win->map, '*', '*');
	wattroff(win->map, COLOR_PAIR(TAB));
	wattron(win->bar, COLOR_PAIR(TAB));
	box(win->bar, '*', '*');
	wattroff(win->bar, COLOR_PAIR(TAB));
}

static void	fill_players(t_vis *win, t_main *main)
{
	int		i;

	i = -1;
	while (++i < main->cnt_pl)
	{
		mvwprintw(win->bar, PL_LN + i * 4, SHIFT, "%s-%d : ",
				PLAYER, (unsigned char)(main->players[i]->nbr_pl * -1));
		wattron(win->bar, COLOR_PAIR(i + 1) | A_BOLD);
		mvwprintw(win->bar, PL_LN + i * 4, SHFT_NAME, "%s",
				main->players[i]->player_name);
		wattroff(win->bar, COLOR_PAIR(i + 1) | A_BOLD);
		mvwprintw(win->bar, PL_LN + i * 4 + 1, SHIFT + 2, "%s", LSTL);
		mvwprintw(win->bar, PL_LN + i * 4 + 2, SHIFT + 2, "%s", LCP);
		wattron(win->bar, COLOR_PAIR(WHITE_CW) | A_BOLD);
		mvwprintw(win->bar, PL_LN + i * 4 + 1, SHIFT + 2 + SHFT_LV_CNT, "%8d",
				main->players[i]->ll_cycle);
		mvwprintw(win->bar, PL_LN + i * 4 + 2, SHIFT + 2 + SHFT_LV_CNT, "%8d",
				main->players[i]->live_cur_per);
		wattroff(win->bar, COLOR_PAIR(WHITE_CW) | A_BOLD);
	}
}

static void	fill_bars_tamplate(t_vis *win)
{
	mvwprintw(win->bar, LN_CP_LN, SHIFT, "%s", LB_CP);
	mvwprintw(win->bar, LN_CP_LN + 1, SHIFT, "[%s]", CHRT_BAR);
	mvwprintw(win->bar, LN_LP_LN, SHIFT, "%s", LB_LP);
	mvwprintw(win->bar, LN_LP_LN + 1, SHIFT, "[%s]", CHRT_BAR);
}

void		fill_bars(t_vis *win, t_main *main)
{
	fill_bars_tamplate(win);
	fill_chart_cur_per(win, main);
	fill_chart_last_per(win, main);
}

void		fill_tab(t_vis *win, t_main *main)
{
	fill_boxes(win);
	wattron(win->bar, COLOR_PAIR(WHITE_CW) | A_BOLD);
	mvwprintw(win->bar, P_LN, SHIFT, "%s", win->paused);
	wattroff(win->bar, COLOR_PAIR(WHITE_CW) | A_BOLD);
	wattron(win->bar, COLOR_PAIR(WHITE_CW));
	mvwprintw(win->bar, SP_LN, SHIFT, "%s", SPEED);
	mvwprintw(win->bar, C_LN, SHIFT, "%s", CYCLE);
	mvwprintw(win->bar, PR_LN, SHIFT, "%s", PR);
	fill_players(win, main);
	fill_bars(win, main);
	mvwprintw(win->bar, CTD_LN, SHIFT, "%s", CTD);
	mvwprintw(win->bar, CDLT_LN, SHIFT, "%s", CDLT);
	mvwprintw(win->bar, NBL_LN, SHIFT, "%s", NBL);
	mvwprintw(win->bar, MAXCH_LN, SHIFT, "%s", MAXCH);
	wattroff(win->bar, COLOR_PAIR(WHITE_CW));
	wattron(win->bar, COLOR_PAIR(WHITE_CW) | A_BOLD);
	mvwprintw(win->bar, SP_LN, SHIFT + ft_strlen(SPEED), "%d   ", win->speed);
	mvwprintw(win->bar, C_LN, SHIFT + ft_strlen(CYCLE), "%d", main->cur_cycle);
	mvwprintw(win->bar, PR_LN, SHIFT + ft_strlen(PR), "%d", main->nbr_proc);
	mvwprintw(win->bar, CTD_LN, SHIFT + ft_strlen(CTD), "%d   ", main->cl_to_die);
	mvwprintw(win->bar, CDLT_LN, SHIFT + ft_strlen(CDLT), "%d", CYCLE_DELTA);
	mvwprintw(win->bar, NBL_LN, SHIFT + ft_strlen(NBL), "%d", NBR_LIVE);
	mvwprintw(win->bar, MAXCH_LN, SHIFT + ft_strlen(MAXCH), "%d", MAX_CHECKS);
	wattroff(win->bar, COLOR_PAIR(WHITE_CW) | A_BOLD);
	refresh_windows(win);
}
