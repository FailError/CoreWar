/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:31:30 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/12 10:03:41 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_ops.h"

void	cw_aff(t_cw *cw, t_carry *carry)
{
	int	r;
	int	val;

	carry->step += (OP_SIZE + ARGS_SIZE);
	r = arena_get_byte(cw, carry->position, carry->step);
	val = carry->registers[r - 1];
	carry->step += REG_LEN;
	if (cw->aff || cw->v & OP_LOG)
		ft_printf("Aff: %c\n", val);
}
