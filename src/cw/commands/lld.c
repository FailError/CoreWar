/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:33:01 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/14 21:05:42 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

void	cw_lld(t_cw *cw, t_carry *carry)
{
	int	val;
	int	r;

	carry->step += (OP_SIZE + ARGS_SIZE);
	val = get_argument(cw, carry, 1, 0);
	carry->carry = (val == 0) ? 1 : 0;
	r = arena_get_byte(cw, carry->position, carry->step);
	carry->registers[r - 1] = val;
	carry->step += REG_LEN;
	if (cw->v & OP_LOG)
		log_lld(carry->id, val, r);
}
