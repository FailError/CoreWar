/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:33:43 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:34:13 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

void	cw_sub(t_cw *cw, t_carry *carry)
{
	int	r1;
	int	r2;
	int	r3;
	int	value;

	carry->step = (OP_SIZE + ARGS_SIZE);
	r1 = arena_get_byte(cw, carry->position, carry->step);
	carry->step += REG_LEN;
	r2 = arena_get_byte(cw, carry->position, carry->step);
	carry->step += REG_LEN;
	value = carry->registers[r1 - 1] - carry->registers[r2 - 1];
	carry->carry = (value == 0) ? 1 : 0;
	r3 = arena_get_byte(cw, carry->position, carry->step);
	carry->registers[r3 - 1] = value;
	carry->step += REG_LEN;
	if (cw->v & OP_LOG)
		log_sub(carry->id, r1, r2, r3);
}
