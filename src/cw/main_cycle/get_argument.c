/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:24:27 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/14 21:06:37 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

int		get_argument(t_cw *cw, t_carry *c, int i, int mod)
{
	t_op		*op;
	int			value;
	int			addr;
	const int	a = calc_addr(c->position + c->step);

	op = &g_op[c->op - 1];
	value = 0;
	if (c->args_types[i - 1] & T_REG)
		value = c->registers[arena_get_byte(cw, c->position, c->step) - 1];
	else if (c->args_types[i - 1] & T_DIR)
		value = arena_bytes_to_int(cw->arena->data, a,
			op->t_dir_size);
	else if (c->args_types[i - 1] & T_IND)
	{
		addr = arena_bytes_to_int(cw->arena->data,
			a, IND_SIZE);
		value = arena_bytes_to_int(cw->arena->data,
			c->position + (mod ? (addr % IDX_MOD) : addr), DIR_SIZE);
	}
	c->step += step_size(c->args_types[i - 1], op);
	return (value);
}
