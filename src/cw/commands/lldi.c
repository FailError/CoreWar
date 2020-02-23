/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:45:47 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/12 10:22:37 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

void	cw_lldi(t_cw *cw, t_carry *carry)
{
	int	a1;
	int	a2;
	int	r;

	carry->step += OP_SIZE + ARGS_SIZE;
	a1 = get_argument(cw, carry, 1, true);
	a2 = get_argument(cw, carry, 2, true);
	r = arena_get_byte(cw, carry->position, carry->step);
	carry->registers[r - 1] = arena_bytes_to_int(cw->arena->data,
			carry->position + (a1 + a2), DIR_SIZE);
	carry->carry = (carry->registers[r - 1] == 0) ? 1 : 0;
	carry->step += REG_LEN;
	if (cw->v & OP_LOG)
		log_lldi(carry, a1, a2, r);
}
