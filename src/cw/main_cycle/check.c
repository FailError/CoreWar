/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:56:08 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:41:18 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	is_carry_died(t_cw *cw, t_carry *carry)
{
	return (cw->cycles_to_die <= 0
			|| cw->cycles - carry->live_cycle >= cw->cycles_to_die);
}

static void	delete_carries(t_cw *cw)
{
	t_carry	*prev;
	t_carry	*ptr;
	t_carry	*delete;

	prev = NULL;
	ptr = cw->carries;
	while (ptr)
		if (is_carry_died(cw, (delete = ptr)))
		{
			ptr = ptr->next;
			if (cw->carries == delete)
				cw->carries = ptr;
			if (cw->v & DEATH_LOG)
				log_death(cw, delete);
			if (prev)
				prev->next = ptr;
			ft_memdel((void **)&delete);
		}
		else
		{
			prev = ptr;
			ptr = ptr->next;
		}
}

void		check(t_cw *cw)
{
	t_ply	*ptr;

	cw->checks++;
	delete_carries(cw);
	if (cw->lives_num >= NBR_LIVE || cw->checks == MAX_CHECKS)
	{
		cw->cycles_to_die -= CYCLE_DELTA;
		cw->checks = 0;
		if (cw->v & CYCLE_LOG)
			log_cycles_die(cw->cycles_to_die);
	}
	cw->cycles_to_check = 0;
	cw->lives_num = 0;
	ptr = cw->players;
	while (ptr)
	{
		ptr->lives_num = 0;
		ptr = ptr->next;
	}
}
