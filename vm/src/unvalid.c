/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unvalid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 12:48:04 by ozharko           #+#    #+#             */
/*   Updated: 2018/05/17 12:48:07 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

static	void	unvalid_only_step_go(t_main *m, t_process *p, int d, int s)
{
	s = (m->arg[0] == 1) ? (s + 1) : s;
	s = (m->arg[0] == 2) ? (s + d) : s;
	s = (m->arg[0] == 3) ? (s + 2) : s;
	s = (m->arg[1] == 1) ? (s + 1) : s;
	s = (m->arg[1] == 2) ? (s + d) : s;
	s = (m->arg[1] == 3) ? (s + 2) : s;
	s = (m->arg[2] == 1) ? (s + 1) : s;
	s = (m->arg[2] == 2) ? (s + d) : s;
	s = (m->arg[2] == 3) ? (s + 2) : s;
	p->index = (p->index + s) % MEM_SIZE;
}

void			unvalid_only_step(t_main *main, t_process *proc)
{
	int			s;
	int			num_p;
	int			d;

	d = 0;
	num_p = main->map[proc->index % MEM_SIZE];
	if (num_p == 1 || num_p == 2 || num_p == 3 || num_p == 4 ||
		num_p == 5 || num_p == 6 || num_p == 7 || num_p == 8 ||
		num_p == 13)
		d = 4;
	else
		d = 2;
	if (num_p == 2 || num_p == 3 || num_p == 4 || num_p == 5 ||
		num_p == 6 || num_p == 7 || num_p == 8 || num_p == 10 ||
		num_p == 11 || num_p == 13 || num_p == 14)
		s = 2;
	else
		s = 1;
	unvalid_only_step_go(main, proc, d, s);
}
