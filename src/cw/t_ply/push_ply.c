/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 19:12:50 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:53:11 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	s_terminate(t_cw *cw, t_ply *ply)
{
	destroy_ply(ply);
	terminate(3, cw);
}

static void	s_push_ply(t_cw *cw, t_ply *ply)
{
	t_ply *ptr;

	if (!cw->players)
	{
		cw->players = ply;
		ply->next = NULL;
		ply->prev = NULL;
		cw->count_players += 1;
		return ;
	}
	ptr = cw->players;
	if (ply->id != -1 && ptr->id == ply->id)
		s_terminate(cw, ply);
	while (ptr->next)
	{
		if (ply->id != -1 && ptr->next->id == ply->id)
			s_terminate(cw, ply);
		ptr = ptr->next;
	}
	ptr->next = ply;
	ply->prev = ptr;
	ply->next = NULL;
	cw->count_players += 1;
}

void		push_ply(t_cw *cw, t_ply *ply)
{
	if (!ply)
		terminate(3, cw);
	if (ply->id > MAX_PLAYERS)
		s_terminate(cw, ply);
	if (!ply->file_path)
		s_terminate(cw, ply);
	if (!ply->name)
		s_terminate(cw, ply);
	if (!ply->comment)
		s_terminate(cw, ply);
	if (!ply->code)
		s_terminate(cw, ply);
	if (ply->code_size < 0 || ply->code_size > 682)
		s_terminate(cw, ply);
	if (cw->count_players >= MAX_PLAYERS)
		s_terminate(cw, ply);
	s_push_ply(cw, ply);
}
