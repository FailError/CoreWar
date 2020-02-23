/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_carries.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:59:21 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:50:19 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	s_initialize_carry(t_ply *ply, t_cw *cw)
{
	t_carry	*carry;

	carry = push_new_carry(cw, cw->arena->sections[ply->id - 1], ply->id);
}

void		initialize_carries(t_cw *cw)
{
	t_ply	*ply;

	if (!cw->players)
		terminate(1, cw);
	ply = cw->players;
	while (ply)
	{
		s_initialize_carry(ply, cw);
		ply = ply->next;
	}
}
