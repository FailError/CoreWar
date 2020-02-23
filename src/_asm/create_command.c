/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:16:30 by kturnips          #+#    #+#             */
/*   Updated: 2020/02/10 16:21:25 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	create_args(t_token *token, t_asm *asm_ms)
{
	int byte;

	byte = 2;
	if (token->type_args / 100 == 1)
		byte += create_reg_arg(token, byte, 1);
	else if (token->type_args / 100 == 2)
		byte += create_dir_arg(token, byte, 1, asm_ms);
	else if (token->type_args / 100 == 3)
		byte += create_ind_arg(token, byte, 1, asm_ms);
	if ((token->type_args / 10) % 10 == 1)
		byte += create_reg_arg(token, byte, 2);
	else if ((token->type_args / 10) % 10 == 2)
		byte += create_dir_arg(token, byte, 2, asm_ms);
	else if ((token->type_args / 10) % 10 == 3)
		byte += create_ind_arg(token, byte, 2, asm_ms);
	if (token->type_args % 10 == 1)
		byte += create_reg_arg(token, byte, 3);
	else if (token->type_args % 10 == 2)
		byte += create_dir_arg(token, byte, 3, asm_ms);
	else if (token->type_args % 10 == 3)
		byte += create_ind_arg(token, byte, 3, asm_ms);
}
