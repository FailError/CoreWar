/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 01:18:58 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:49:58 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

static void	s_carry_duplicate(t_cw *cw, t_carry *carry, t_carry *new, int a)
{
	int		i;

	a = calc_addr(carry->position + a);
	i = -1;
	while (++i < REG_NUMBER)
		new->registers[i] = carry->registers[i];
	new->carry = carry->carry;
	new->live_cycle = carry->live_cycle;
	push_duplicated_carry(cw, new, a);
}

void		carry_duplicate(t_cw *cw, t_carry *carry, int a)
{
	t_carry	*new;

	if (!carry)
		terminate(10, cw);
	new = new_carry(cw);
	if (!new)
		terminate(10, cw);
	s_carry_duplicate(cw, carry, new, a);
}
