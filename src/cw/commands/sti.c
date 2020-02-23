/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:33:34 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/12 09:02:23 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

void	cw_sti(t_cw *cw, t_carry *carry)
{
	int	r;
	int	val;
	int	a1;
	int	a2;

	carry->step += OP_SIZE + ARGS_SIZE;
	r = arena_get_byte(cw, carry->position, carry->step);
	val = carry->registers[r - 1];
	carry->step += REG_LEN;
	a1 = get_argument(cw, carry, 2, true);
	a2 = get_argument(cw, carry, 3, true);
	int_to_bytecode(cw,
			(carry->position + ((a1 + a2) % IDX_MOD)), val, DIR_SIZE);
	if (cw->v & OP_LOG)
		log_sti(carry, r, a1, a2);
}
