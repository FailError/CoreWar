/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_asm_commands_indir_reg.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbessa <kbessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:59:58 by kbessa            #+#    #+#             */
/*   Updated: 2020/02/12 17:04:39 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	two_three_indirect_label(char *str, t_token *cur, t_asm *asm_ms, t_var *var)
{
	var->start = var->i++;
	var->j++;
	while (str[var->i] && is_label_char(str[var->i]))
	{
		var->i++;
		var->j++;
	}
	indirect_size(cur);
	save_arguments(str, cur, var, asm_ms);
	is_spacei(str, &var->i);
	if (var->a + 1 == cur->arg_numbers)
	{
		is_spacei(str, &var->i);
		if (!is_comment(&str[var->i]) && str[var->i])
			asm_error(14 + var->a, cur->current_line, asm_ms);
	}
	else if (str[var->i++] == SEPARATOR_CHAR)
	{
		var->a++;
		return (1);
	}
	return (0);
}

int	two_three_register(char *str, t_token *current, t_asm *asm_ms, t_var *var)
{
	var->start = var->i++;
	var->j++;
	is_number_char(str[var->i]) ? 0 : asm_error(14 + var->a,
		current->current_line, asm_ms);
	while (str[var->i] && is_number_char(str[var->i]))
	{
		var->i++;
		var->j++;
	}
	var->j > 3 ? asm_error(14 + var->a, current->current_line, asm_ms) : 0;
	register_size(current);
	save_arguments(str, current, var, asm_ms);
	is_spacei(str, &var->i);
	if (var->a + 1 == current->arg_numbers)
	{
		is_spacei(str, &var->i);
		if (!is_comment(&str[var->i]) && str[var->i])
			asm_error(14 + var->a, current->current_line, asm_ms);
	}
	else if (str[var->i++] == SEPARATOR_CHAR)
	{
		var->a++;
		return (1);
	}
	return (0);
}

int	two_three_indirect_num(char *str, t_token *cur, t_asm *asm_ms, t_var *var)
{
	var->j++;
	var->start = var->i;
	str[var->i] == '-' ? var->j++ : 0;
	str[var->i] == '-' && ((!str[var->i + 1] || !(is_number_char)(str[var->i +
		1]))) ? asm_error(14 + var->a, cur->current_line, asm_ms) : var->i++;
	while (str[var->i] && is_number_char(str[var->i]))
	{
		var->i++;
		var->j++;
	}
	indirect_size(cur);
	save_arguments(str, cur, var, asm_ms);
	is_spacei(str, &var->i);
	if (var->a + 1 == cur->arg_numbers)
	{
		is_spacei(str, &var->i);
		if (!is_comment(&str[var->i]) && str[var->i])
			asm_error(14 + var->a, cur->current_line, asm_ms);
	}
	else if (str[var->i++] == SEPARATOR_CHAR)
	{
		var->a++;
		return (1);
	}
	return (0);
}
