/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:07:58 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:38:46 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

static int	s_do_op(t_carry *carry, t_cw *cw)
{
	t_op	*op;

	op = NULL;
	if (carry->op >= 0x01 && carry->op <= 0x10)
		op = &g_op[carry->op - 1];
	if (op)
	{
		parse_args(cw, carry, op);
		if (is_arg_types_valid(carry, op) && is_args_valid(carry, cw, op))
			op->func(cw, carry);
		else
			carry->step = calc_step(carry, op);
		return (1);
	}
	else
		return (0);
}

static void	s_update_op(t_carry *carry, t_cw *cw)
{
	int		code;

	if (!carry)
		terminate(10, cw);
	code = cw->arena->data[calc_addr(carry->position)];
	carry->op = code;
	if (code >= 0x01 && code <= 0x10)
		carry->cycles_to_exec = g_op[code - 1].cycles;
}

static void	s_cycle_carry(t_carry *carry, t_cw *cw)
{
	if (carry->cycles_to_exec == 0)
		s_update_op(carry, cw);
	if (carry->cycles_to_exec > 0)
		carry->cycles_to_exec -= 1;
	if (carry->cycles_to_exec == 0)
	{
		if (!s_do_op(carry, cw))
		{
			carry->step = OP_SIZE;
			move_carry(carry, cw);
			return ;
		}
		if (cw->v & MOVE_LOG && carry->step)
			log_movement(cw->arena->data, carry);
		move_carry(carry, cw);
	}
}

static void	s_cycle(t_cw *cw)
{
	t_carry	*carry;

	cw->cycles += 1;
	cw->cycles_to_check += 1;
	if (cw->v & CYCLE_LOG)
		log_cycle(cw->cycles);
	carry = cw->carries;
	while (carry)
	{
		s_cycle_carry(carry, cw);
		carry = carry->next;
	}
}

void		main_cycle(t_cw *cw)
{
	while (cw->carries)
	{
		if (cw->cycles == cw->dump_cycles)
		{
			print_arena(cw->arena->data, 32);
			terminate(0, cw);
		}
		if (cw->cycles == cw->d_cycles)
		{
			print_arena(cw->arena->data, 64);
			terminate(0, cw);
		}
		s_cycle(cw);
		if (cw->cycles_to_die <= 0
			|| cw->cycles_to_check == cw->cycles_to_die)
			check(cw);
	}
}
