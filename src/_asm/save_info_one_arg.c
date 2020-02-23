/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_info_one_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbessa <kbessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 17:53:48 by kbessa            #+#    #+#             */
/*   Updated: 2020/02/12 17:57:40 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	save_one_arg_aff(t_asm *asm_ms, t_token *cur, int last, char *str)
{
	cur->arg1 = ft_strsub2(str, 0, last);
	cur->arg1[0] != 'r' ? asm_error(9, cur->current_line, asm_ms) : 0;
	last > 3 ? asm_error(14, cur->current_line, asm_ms) : 0;
	cur->output = ft_memalloc(sizeof(char) * 3);
	cur->output[0] = (char)cur->code_operation;
	cur->output[1] = shell_arg_byte(cur->type_args);
	cur->command_size = 3;
	asm_ms->current_byte += 3;
	cur->size1 = asm_ms->current_byte - 3;
	cur->len = 3;
}

void	save_one_arg_dir(t_asm *asm_ms, t_token *cur, int last, char *str)
{
	int size;

	cur->arg1 = ft_strsub2(str, 0, last);
	cur->arg1[0] != '%' ? asm_error(9, cur->current_line, asm_ms) : 0;
	size = cur->code_operation == 1 ? 4 : 2;
	cur->output = ft_memalloc(sizeof(char) * size + 1);
	cur->output[0] = (char)(cur->code_operation);
	cur->command_size += size + 1;
	asm_ms->current_byte += size + 1;
	cur->size1 = asm_ms->current_byte - size - 1;
	cur->len = size + 1;
}

int		save_info_one_arg(t_asm *asm_ms, char *str, t_token *cur, int last)
{
	if (cur->code_operation == 16)
		save_one_arg_aff(asm_ms, cur, last, str);
	else
		save_one_arg_dir(asm_ms, cur, last, str);
	return (0);
}
