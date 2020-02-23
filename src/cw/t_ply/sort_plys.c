/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_plys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 19:25:50 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:51:42 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	s_swap(t_ply *t1, t_ply *t2, t_cw *cw)
{
	if (t1->prev)
		t1->prev->next = t2;
	if (t2->next)
		t2->next->prev = t1;
	t1->next = t2->next;
	t2->prev = t1->prev;
	t1->prev = t2;
	t2->next = t1;
	if (t1 == cw->players)
		cw->players = t2;
}

static void	s_sort_plys(t_cw *cw)
{
	t_ply	*ply;
	t_ply	*next;

	ply = cw->players;
	next = cw->players->next;
	while (next)
	{
		if (next->id < ply->id)
		{
			s_swap(ply, next, cw);
			ply = cw->players;
			next = cw->players->next;
			continue;
		}
		ply = ply->next;
		next = next->next;
	}
}

void		sort_plys(t_cw *cw)
{
	if (!cw)
		terminate(3, cw);
	if (!cw->players)
		terminate(3, cw);
	s_sort_plys(cw);
}
