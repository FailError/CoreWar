/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:22:26 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/12 08:08:47 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	initialize_cw(t_cw *cw)
{
	cw->v = 0;
	cw->dump_cycles = -1;
	cw->d_cycles = -1;
	cw->cycles = 0;
	cw->cycles_to_check = 0;
	cw->live_count = 0;
	cw->cycles_to_die = CYCLE_TO_DIE;
	cw->count_players = 0;
	cw->arena = NULL;
	cw->carries_count = 0;
	cw->carries = NULL;
	cw->players = NULL;
	cw->last_alive = NULL;
	cw->lives_num = 0;
	cw->checks = 0;
	cw->aff = 0;
	cw->vis = NULL;
}
