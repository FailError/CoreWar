/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_ops.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:27:25 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/14 21:30:59 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_OPS_H
# define CW_OPS_H

# include "corewar.h"
# include "libft.h"

typedef struct	s_op
{
	char		*name;
	uint8_t		code;
	uint8_t		args_num;
	int			args_types_code;
	uint8_t		args_types[3];
	uint8_t		t_dir_size;
	uint32_t	cycles;
	void		(*func)(t_cw *, t_carry *);
}				t_op;

/*
**	Commands
*/

void			cw_add(t_cw *cw, t_carry *carry);
void			cw_aff(t_cw *cw, t_carry *carry);
void			cw_and(t_cw *cw, t_carry *carry);
void			cw_fork(t_cw *cw, t_carry *carry);
void			cw_lfork(t_cw *cw, t_carry *carry);
void			cw_live(t_cw *cw, t_carry *carry);
void			cw_ld(t_cw *cw, t_carry *carry);
void			cw_lld(t_cw *cw, t_carry *carry);
void			cw_ldi(t_cw *cw, t_carry *carry);
void			cw_lldi(t_cw *cw, t_carry *carry);
void			cw_or(t_cw *cw, t_carry *carry);
void			cw_st(t_cw *cw, t_carry *carry);
void			cw_sti(t_cw *cw, t_carry *carry);
void			cw_sub(t_cw *cw, t_carry *carry);
void			cw_xor(t_cw *cw, t_carry *carry);
void			cw_zjmp(t_cw *cw, t_carry *carry);

/*
** Main Cycle
*/

void			parse_args(t_cw *cw, t_carry *carry, t_op *op);
void			clear_args(t_cw *cw, t_carry *carry);
int				is_arg_types_valid(t_carry *carry, t_op *op);
int				is_args_valid(t_carry *carry, t_cw *cw, t_op *op);
int				step_size(uint8_t arg_type, t_op *op);
int				calc_step(t_carry *carry, t_op *op);
void			clear_args(t_cw *cw, t_carry *carry);
int				get_argument(t_cw *cw, t_carry *c, int i, int mod);

static t_op		g_op[16] = {
	{
		.name = "live",
		.code = 0x01,
		.args_num = 1,
		.args_types_code = 0,
		.args_types = {T_DIR, 0, 0},
		.t_dir_size = 4,
		.cycles = 10,
		.func = &cw_live
	},
	{
		.name = "ld",
		.code = 0x02,
		.args_num = 2,
		.args_types_code = 1,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.t_dir_size = 4,
		.cycles = 5,
		.func = &cw_ld
	},
	{
		.name = "st",
		.code = 0x03,
		.args_num = 2,
		.args_types_code = 1,
		.args_types = {T_REG, T_REG | T_IND, 0},
		.t_dir_size = 4,
		.cycles = 5,
		.func = &cw_st
	},
	{
		.name = "add",
		.code = 0x04,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG, T_REG, T_REG},
		.t_dir_size = 4,
		.cycles = 10,
		.func = &cw_add
	},
	{
		.name = "sub",
		.code = 0x05,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG, T_REG, T_REG},
		.t_dir_size = 4,
		.cycles = 10,
		.func = &cw_sub
	},
	{
		.name = "and",
		.code = 0x06,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.t_dir_size = 4,
		.cycles = 6,
		.func = &cw_and
	},
	{
		.name = "or",
		.code = 0x07,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.t_dir_size = 4,
		.cycles = 6,
		.func = &cw_or
	},
	{
		.name = "xor",
		.code = 0x08,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.t_dir_size = 4,
		.cycles = 6,
		.func = &cw_xor
	},
	{
		.name = "zjmp",
		.code = 0x09,
		.args_num = 1,
		.args_types_code = 0,
		.args_types = {T_DIR, 0, 0},
		.t_dir_size = 2,
		.cycles = 20,
		.func = &cw_zjmp
	},
	{
		.name = "ldi",
		.code = 0x0A,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.t_dir_size = 2,
		.cycles = 25,
		.func = &cw_ldi
	},
	{
		.name = "sti",
		.code = 0x0B,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
		.t_dir_size = 2,
		.cycles = 25,
		.func = &cw_sti
	},
	{
		.name = "fork",
		.code = 0x0C,
		.args_num = 1,
		.args_types_code = 0,
		.args_types = {T_DIR, 0, 0},
		.t_dir_size = 2,
		.cycles = 800,
		.func = &cw_fork
	},
	{
		.name = "lld",
		.code = 0x0D,
		.args_num = 2,
		.args_types_code = 1,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.t_dir_size = 4,
		.cycles = 10,
		.func = &cw_lld
	},
	{
		.name = "lldi",
		.code = 0x0E,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.t_dir_size = 2,
		.cycles = 50,
		.func = &cw_lldi
	},
	{
		.name = "lfork",
		.code = 0x0F,
		.args_num = 1,
		.args_types_code = 0,
		.args_types = {T_DIR, 0, 0},
		.t_dir_size = 2,
		.cycles = 1000,
		.func = &cw_lfork
	},
	{
		.name = "aff",
		.code = 0x10,
		.args_num = 1,
		.args_types_code = 1,
		.args_types = {T_REG, 0, 0},
		.t_dir_size = 4,
		.cycles = 2,
		.func = &cw_aff
	}
};

#endif
