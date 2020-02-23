/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:32:35 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/12 09:07:49 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

void	cw_lfork(t_cw *cw, t_carry *carry)
{
	int		a;

	carry->step += OP_SIZE;
	a = get_argument(cw, carry, 1, true);
	carry_duplicate(cw, carry, a);
	if (cw->v & OP_LOG)
		log_lfork(carry, a);
}
