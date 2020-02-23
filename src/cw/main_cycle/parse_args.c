/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:24:14 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:40:02 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

static void	set_arg_type(int8_t arg_type, int8_t index, t_carry *carry)
{
	carry->args_types[index - 1] = g_arg_code[arg_type - 1];
}

void		clear_args(t_cw *cw, t_carry *carry)
{
	int i;

	(void)cw;
	i = 0;
	while (i < 3)
	{
		carry->args_types[i] = 0;
		i++;
	}
}

void		parse_args(t_cw *cw, t_carry *carry, t_op *op)
{
	int8_t args_types_code;

	if (op->args_types_code)
	{
		args_types_code = arena_get_byte(cw, carry->position, 1);
		if (op->args_num >= 1)
			set_arg_type((int8_t)((args_types_code & 0xC0) >> 6), 1, carry);
		if (op->args_num >= 2)
			set_arg_type((int8_t)((args_types_code & 0x30) >> 4), 2, carry);
		if (op->args_num >= 3)
			set_arg_type((int8_t)((args_types_code & 0xC) >> 2), 3, carry);
	}
	else
		carry->args_types[0] = op->args_types[0];
}
