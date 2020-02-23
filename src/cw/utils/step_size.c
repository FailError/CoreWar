/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 22:00:36 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:55:18 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_ops.h"
#include "corewar.h"

int	step_size(uint8_t arg_type, t_op *op)
{
	if (arg_type & T_REG)
		return (REG_LEN);
	else if (arg_type & T_DIR)
		return (op->t_dir_size);
	else if (arg_type & T_IND)
		return (IND_SIZE);
	return (0);
}

int	calc_step(t_carry *carry, t_op *op)
{
	int		i;
	int		step;

	i = 0;
	step = 0;
	step += OP_SIZE + (op->args_types_code ? ARGS_SIZE : 0);
	while (i < g_op[carry->op - 1].args_num)
	{
		step += step_size(carry->args_types[i], op);
		i++;
	}
	return (step);
}
