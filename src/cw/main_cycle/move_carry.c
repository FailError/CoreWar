/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_carry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 22:16:55 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:40:40 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

void	move_carry(t_carry *carry, t_cw *cw)
{
	clear_args(cw, carry);
	carry->position = calc_addr(carry->position + carry->step);
	carry->step = 0;
}
