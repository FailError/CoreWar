/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_info_two_three_arg.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbessa <kbessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 17:47:44 by kbessa            #+#    #+#             */
/*   Updated: 2020/02/12 17:58:28 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_arg(t_token *current, const char *arg, int num, t_asm *asm_ms)
{
	if (g_op_tab[current->index].args_types[num] == 1)
		arg[0] != 'r' ? asm_error(9 + num, current->current_line, asm_ms) : 0;
	else if (g_op_tab[current->index].args_types[num] == 2)
		arg[0] != '%' ? asm_error(9 + num, current->current_line, asm_ms) : 0;
	else if (g_op_tab[current->index].args_types[num] == 3)
		arg[0] == 'r' || arg[0] == '%' ? 0 :
		asm_error(9 + num, current->current_line, asm_ms);
	else if (g_op_tab[current->index].args_types[num] == 4)
		arg[0] != 'r' && arg[0] != '%' ? 0 :
		asm_error(9 + num, current->current_line, asm_ms);
	else if (g_op_tab[current->index].args_types[num] == 5)
		arg[0] != '%' ? 0 : asm_error(9 + num, current->current_line, asm_ms);
	else if (g_op_tab[current->index].args_types[num] == 6)
		arg[0] != 'r' ? 0 : asm_error(9 + num, current->current_line, asm_ms);
}

void	save_arguments(char *str, t_token *current, t_var *var, t_asm *asm_ms)
{
	if (!current->arg1)
	{
		current->arg1 = ft_strsub2(str, var->start, var->j);
		check_arg(current, current->arg1, 0, asm_ms);
	}
	else if (!current->arg2)
	{
		current->arg2 = ft_strsub2(str, var->start, var->j);
		check_arg(current, current->arg2, 1, asm_ms);
	}
	else if (!current->arg3)
	{
		current->arg3 = ft_strsub2(str, var->start, var->j);
		check_arg(current, current->arg3, 2, asm_ms);
	}
}

int		size_code(int size, t_token *current)
{
	if (current->arg1 && current->arg1[0] == 'r')
		size = 100;
	else if (current->arg1 && current->arg1[0] == '%')
		size = 200;
	else if (current->arg1)
		size = 300;
	if (current->arg2 && current->arg2[0] == 'r')
		size += 10;
	else if (current->arg2 && current->arg2[0] == '%')
		size += 20;
	else if (current->arg2)
		size += 30;
	if (current->arg3 && current->arg3[0] == 'r')
		size += 1;
	else if (current->arg3 && current->arg3[0] == '%')
		size += 2;
	else if (current->arg3)
		size += 3;
	return (size);
}

void	save_all_info(t_asm *asm_, t_token *cur)
{
	int size;

	size = 0;
	size = size_code(size, cur);
	cur->type_args = size;
	cur->output = ft_memalloc(sizeof(char) * 1 + 1 +
		(cur->size1 + cur->size2 + cur->size3));
	cur->output[0] = (char)cur->code_operation;
	cur->output[1] = shell_arg_byte(size);
	asm_->current_byte += 1 + 1 + (cur->size1 + cur->size2 + cur->size3);
	cur->len = 1 + 1 + (cur->size1 + cur->size2 + cur->size3);
	cur->size1 = asm_->current_byte - cur->size1 - cur->size2 - cur->size3 - 2;
	cur->size2 = cur->size1;
	cur->size3 = cur->size1;
}
