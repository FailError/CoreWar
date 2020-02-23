/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_plys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 21:05:54 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:52:40 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	s_get_free_id(int ids[MAX_PLAYERS])
{
	int i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (ids[i] == 0)
			return (i);
		i++;
	}
	return (-1);
}

static void	s_set_ids(t_cw *cw, int ids[MAX_PLAYERS])
{
	t_ply *ptr;

	ptr = cw->players;
	while (ptr)
	{
		if (ptr->id > cw->count_players)
			terminate(8, cw);
		if (ptr->id == -1)
		{
			ptr->id = s_get_free_id(ids) + 1;
			if (ptr->id == -1)
				terminate(4, cw);
			ids[ptr->id - 1] = 1;
		}
		ptr = ptr->next;
	}
}

static void	initialize_last_alive(t_cw *cw)
{
	t_ply	*ply;

	ply = cw->players;
	while (ply)
	{
		if (ply->next == NULL)
		{
			cw->last_alive = ply;
			break ;
		}
		ply = ply->next;
	}
}

void		initialize_plys(t_cw *cw)
{
	int		ids[MAX_PLAYERS];
	int		i;
	t_ply	*ptr;

	i = -1;
	while (++i < MAX_PLAYERS)
		ids[i] = 0;
	if (!cw->players)
		terminate(4, cw);
	if (cw->count_players > MAX_PLAYERS)
		terminate(4, cw);
	ptr = cw->players;
	while (ptr)
	{
		if (ptr->id > MAX_PLAYERS)
			terminate(4, cw);
		if (ptr->id != -1)
			ids[ptr->id - 1] = 1;
		ptr = ptr->next;
	}
	s_set_ids(cw, ids);
	sort_plys(cw);
	initialize_last_alive(cw);
}
