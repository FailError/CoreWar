/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_asm_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbessa <kbessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:51:16 by kbessa            #+#    #+#             */
/*   Updated: 2020/02/12 16:58:31 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	two_three_direct_number(char *str, t_token *cur, t_asm *asm_ms, t_var *var)
{
	str[var->i] == '-' ? var->j++ : 0;
	str[var->i] == '-' && ((!str[var->i + 1] || !is_number_char(str[var->i +
		1]))) ? asm_error(14 + var->a, cur->current_line, asm_ms) : 0;
	str[var->i] == '-' ? var->i++ : 0;
	while (str[var->i] && is_number_char(str[var->i]))
	{
		var->i++;
		var->j++;
	}
	direct_size(cur);
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

int	two_three_direct_label(char *str, t_token *curr, t_asm *asm_ms, t_var *var)
{
	var->i++;
	var->j++;
	while (str[var->i] && is_label_char(str[var->i]))
	{
		var->i++;
		var->j++;
	}
	direct_size(curr);
	save_arguments(str, curr, var, asm_ms);
	is_spacei(str, &var->i);
	if (var->a + 1 == curr->arg_numbers)
	{
		is_spacei(str, &var->i);
		if (!is_comment(&str[var->i]) && str[var->i])
			asm_error(14 + var->a, curr->current_line, asm_ms);
	}
	else if (str[var->i++] == SEPARATOR_CHAR)
	{
		var->a++;
		return (1);
	}
	return (0);
}

int	two_three_direct(char *str, t_token *current, t_asm *asm_ms, t_var *var)
{
	var->start = var->i++;
	var->j++;
	if (str[var->i] && (str[var->i] == '-' || is_number_char(str[var->i])))
	{
		if (two_three_direct_number(str, current, asm_ms, var))
			return (1);
	}
	else if (str[var->i] && str[var->i] == LABEL_CHAR)
	{
		if (two_three_direct_label(str, current, asm_ms, var))
			return (1);
	}
	else
		asm_error(14 + var->a, current->current_line, asm_ms);
	return (0);
}

int	check_arguments(t_asm *asm_ms, char *str, t_token *current, t_var *var)
{
	is_spacei(str, &var->i);
	if (str[var->i] && str[var->i] == DIRECT_CHAR)
	{
		if (two_three_direct(str, current, asm_ms, var))
			return (1);
	}
	else if (str[var->i] && str[var->i] == LABEL_CHAR)
	{
		if (two_three_indirect_label(str, current, asm_ms, var))
			return (1);
	}
	else if (str[var->i] && str[var->i] == REGISTER_CHAR)
	{
		if (two_three_register(str, current, asm_ms, var))
			return (1);
	}
	else if (str[var->i] && (str[var->i] == '-' || is_number_char(str[var->i])))
	{
		if (two_three_indirect_num(str, current, asm_ms, var))
			return (1);
	}
	else
		asm_error(14 + var->a, current->current_line, asm_ms);
	var->a++;
	return (0);
}

int	main_cycle_two_three_arguments(t_asm *asm_ms, char *str, t_token *current)
{
	t_var var;

	ft_bzero(&var, sizeof(t_var));
	while (var.a < current->arg_numbers)
	{
		var.j = 0;
		if (check_arguments(asm_ms, str, current, &var))
			continue ;
	}
	save_all_info(asm_ms, current);
	return (0);
}
