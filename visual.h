/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:05:14 by kshyshki          #+#    #+#             */
/*   Updated: 2018/04/18 12:05:16 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include <ncurses.h>
# include <time.h>
# include <limits.h>
# include <math.h>
# include <signal.h>
# include "main.h"

# define SHIFT 3

# define PAUSE "** PAUSED ** "
# define RUN "** RUNNING **"
# define P_LN 2

# define SPEED "Cycles/second limit : "
# define SP_LN 4

# define CYCLE "Cycle : "
# define C_LN 6

# define PR "Processes : "
# define PR_LN 8

# define PLAYER "Player "
# define PL_LN 10

# define LSTL "Last live : "

# define LCP "Lives in current period : "

# define LB_CP "Live breakdown for current period :"
# define LN_CP_LN 26
# define CHRT_BAR "--------------------------------------------------"

# define LB_LP "Live breakdown for last period :"
# define LN_LP_LN 29

# define CTD "CYCLE_TO_DIE : "
# define CTD_LN 32

# define CDLT "CYCLE_DELTA : "
# define CDLT_LN 34

# define NBL "NBR_LIVE : "
# define NBL_LN 36

# define MAXCH "MAX_CHECKS : "
# define MAXCH_LN 38

# define WINNER "The winner is : "
# define WINNER_LN 40
# define QIUTKEY "** Press \'q\' key to exit ** "

# define USAGE "USAGE : "
# define USAGE_LN 46

# define BASE_SPEED 50

# define MAP_HEIGHT 68
# define MAP_WIDTH 197

# define SHIFT_PR 5
# define SHIFT_LIVE 10
# define SHIFT_MARKER 14
# define SHFT_MRKR_PR 9
# define SHFT_LV_PR 4

# define SHFT_NAME 15
# define SHFT_LV_CNT 26

enum
{
	FIRST_PLAYER = 1,
	SECOND_PLAYER,
	THIRD_PLAYER,
	FOURTH_PLAYER,
	EMPTY_CELL,
	FST_PL_PROC,
	SCND_PL_PROC,
	THRD_PL_PROC,
	FRTH_PL_PROC,
	ECELL_PL_PROC,
	FST_PL_LIVE,
	SCND_PL_LIVE,
	THRD_PL_LIVE,
	FRTH_PL_LIVE,
	FST_PL_MARKER,
	SCND_PL_MARKER,
	THRD_PL_MARKER,
	FRTH_PL_MARKER,
	TAB,
	WHITE_CW
};

typedef struct			s_live
{
	int					index;
	unsigned int		cycle_init;
	struct s_live		*next;
}						t_live;

typedef struct			s_vis
{
	WINDOW				*map;
	WINDOW				*bar;
	unsigned char		color[MEM_SIZE];
	unsigned int		speed;
	char				*paused;
	int					one_step;
	t_live				*lives;
}						t_vis;

void					fill_map(t_vis *win,
								unsigned char *color, unsigned char *map);
int						fill_lives(t_vis *win,
									t_live *live, unsigned int *cur_cycle);
int						fill_changes(t_changes *chang,
										t_vis *win, unsigned int *cur_cycle);
void					fill_start_changes(t_changes *chang, t_vis *win);
void					fill_process(t_main *main, t_vis *win);
void					fill_tab(t_vis *win, t_main *main);
void					fill_chart_cur_per(t_vis *win, t_main *main);
void					fill_chart_last_per(t_vis *win, t_main *main);
void					print_winner(t_main *main, t_vis *win);
void					print_usage(t_vis *win);
int						init_window(t_vis *win);
void					refresh_windows(t_vis *win);
int						visual(t_main *main);

#endif
