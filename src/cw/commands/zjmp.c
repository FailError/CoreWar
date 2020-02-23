/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:34:00 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:34:29 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

void	cw_zjmp(t_cw *cw, t_carry *carry)
{
	int a;

	carry->step += OP_SIZE;
	a = get_argument(cw, carry, 1, true);
	if (carry->carry)
	{
		carry->position = calc_addr(carry->position + (a % IDX_MOD));
		carry->step = 0;
	}
	if (cw->v & OP_LOG)
		log_zjmp(carry, a);
}
