/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:43:47 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:34:19 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

void	cw_xor(t_cw *cw, t_carry *carry)
{
	int	val1;
	int	val2;
	int	res;
	int	r;

	carry->step += OP_SIZE + ARGS_SIZE;
	val1 = get_argument(cw, carry, 1, true);
	val2 = get_argument(cw, carry, 2, true);
	res = val1 ^ val2;
	carry->carry = (res == 0) ? 1 : 0;
	r = arena_get_byte(cw, carry->position, carry->step);
	carry->registers[r - 1] = res;
	carry->step += REG_LEN;
	if (cw->v & OP_LOG)
		log_xor(carry->id, val1, val2, r);
}
