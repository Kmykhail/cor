/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_fill_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:05:14 by kshyshki          #+#    #+#             */
/*   Updated: 2018/04/18 12:05:16 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int		fill_changes(t_changes *chang, t_vis *win, unsigned int *cur_cycle)
{
	int	i;
	int	tmp;

	if (!chang)
		return (0);
	if (chang->next)
		if (fill_changes(chang->next, win, cur_cycle))
			chang->next = NULL;
	tmp = (chang->start > chang->finish) ? MEM_SIZE - 1 : chang->finish;
	i = chang->start - 1;
	while (++i < tmp + 1)
		win->color[i] = (chang->nbr_pl * -1) + SHIFT_MARKER;
	if (chang->start > chang->finish)
	{
		i = -1;
		while (++i < chang->finish + 1)
			win->color[i] = (chang->nbr_pl * -1) + SHIFT_MARKER;
	}
	if ((*cur_cycle - chang->cycle_init) >= 50)
	{
		i = chang->start - 1;
		while (++i < tmp + 1)
			win->color[i] = win->color[i] - SHIFT_MARKER;
		if (chang->start > chang->finish)
		{
			i = -1;
			while (++i < chang->finish + 1)
				win->color[i] = win->color[i] - SHIFT_MARKER;
		}
		free(chang);
		return (1);
	}
	return (0);
}

void	fill_start_changes(t_changes *chang, t_vis *win)
{
	int	i;

	if (!chang)
		return ;
	if (chang->next)
		fill_start_changes(chang->next, win);
	chang->next = NULL;
	i = chang->start - 1;
	while (++i < chang->finish + 1)
		win->color[i] = (chang->nbr_pl * -1);
	free(chang);
}

int		fill_lives(t_vis *win, t_live *live, unsigned int *cur_cycle)
{
	if (!live)
		return (0);
	if (live->next)
		if (fill_lives(win, live->next, cur_cycle))
			live->next = NULL;
	if (win->color[live->index] >= FST_PL_MARKER
		&& win->color[live->index] <= FRTH_PL_MARKER)
		win->color[live->index] = win->color[live->index] - SHFT_LV_PR;
	else if (win->color[live->index] >= FIRST_PLAYER
			&& win->color[live->index] <= FOURTH_PLAYER)
		win->color[live->index] = win->color[live->index] + SHIFT_LIVE;
	if (*cur_cycle - live->cycle_init >= 50)
	{
		win->color[live->index] = win->color[live->index] - SHIFT_LIVE;
		free(live);
		return (1);
	}
	return (0);
}

void	fill_process(t_main *main, t_vis *win)
{
	t_process	*tmp;
	t_live		*live;

	tmp = main->lst_proc;
	while (tmp)
	{
		if (main->map[tmp->index] != 1)
		{
			if (win->color[tmp->index] >= FST_PL_MARKER
				&& win->color[tmp->index] <= FRTH_PL_MARKER)
				win->color[tmp->index] = win->color[tmp->index] - SHFT_MRKR_PR;
			else if (win->color[tmp->index] >= FIRST_PLAYER
					&& win->color[tmp->index] <= EMPTY_CELL)
				win->color[tmp->index] = win->color[tmp->index] + SHIFT_PR;
		}
		else if (win->color[tmp->index] < FST_PL_LIVE || win->color[tmp->index] > FRTH_PL_LIVE)
		{
			live = (t_live*)malloc(sizeof(t_live));
			live->cycle_init = main->cur_cycle;
			live->index = tmp->index;
			live->next = win->lives;
			win->lives = live;
		}
		tmp = tmp->next;
	}
}

void	fill_map(t_vis *win, unsigned char *color, unsigned char *map)
{
	int		x;
	int		y;
	int		iter;

	y = 2;
	iter = 0;
	x = SHIFT;
	while (iter < MEM_SIZE)
	{
		if (color[iter] >= FST_PL_LIVE)
			wattron(win->map, COLOR_PAIR(color[iter]) | A_BOLD);
		else
			wattron(win->map, COLOR_PAIR(color[iter]));
		mvwprintw(win->map, y, x, "%.2x", map[iter]);
		if (color[iter] >= FST_PL_LIVE)
			wattroff(win->map, COLOR_PAIR(color[iter]) | A_BOLD);
		else
			wattroff(win->map, COLOR_PAIR(color[iter]));
		if (++iter % 64 == 0 && (x = SHIFT))
			y++;
		else
			x += 3;
	}
	refresh_windows(win);
}