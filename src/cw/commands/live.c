/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:32:51 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:35:23 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

static t_ply	*get_ply(t_cw *cw, int id)
{
	t_ply *ptr;

	ptr = cw->players;
	while (ptr)
	{
		if (ptr->id == id)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

void			cw_live(t_cw *cw, t_carry *carry)
{
	int			id;
	t_ply		*ply;

	carry->step += OP_SIZE;
	id = get_argument(cw, carry, 1, false);
	cw->lives_num++;
	carry->live_cycle = cw->cycles;
	ply = NULL;
	if (id <= -1 && id >= -((cw->count_players < 0) ?
		-cw->count_players : cw->count_players))
	{
		ply = get_ply(cw, -id);
		if (!ply)
			terminate(10, cw);
		ply->live_cycle = cw->cycles;
		ply->lives_num++;
		cw->last_alive = ply;
		if (cw->v & LIVE_LOG && ply)
			log_live_msg((ply->id < 0) ? -ply->id : ply->id, ply->name);
	}
	if (cw->v & OP_LOG)
		log_live(carry->id, id);
}
