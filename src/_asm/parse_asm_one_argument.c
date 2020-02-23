/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_asm_one_argument.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbessa <kbessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 17:05:01 by kbessa            #+#    #+#             */
/*   Updated: 2020/02/12 17:07:53 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	one_arg_register(char *str, t_asm *asm_ms, t_token *cur, t_var *var)
{
	var->i++;
	is_number_char(str[var->i]) ? 0 : asm_error(14, cur->current_line, asm_ms);
	while (str[var->i] && is_number_char(str[var->i]))
		var->i++;
	var->j = var->i;
	is_spacei(str, &var->i);
	if (str[var->i] != COMMENT_CHAR && str[var->i] != ALT_COMMENT_CHAR &&
		str[var->i])
		asm_error(14, cur->current_line, asm_ms);
	save_info_one_arg(asm_ms, str, cur, var->j);
}

void	one_arg_dir_label(char *str, t_asm *asm_ms, t_token *cur, t_var *var)
{
	var->i++;
	while (str[var->i] && is_label_char(str[var->i]))
		var->i++;
	var->j = var->i;
	is_spacei(str, &var->i);
	if (str[var->i] != COMMENT_CHAR && str[var->i] != ALT_COMMENT_CHAR &&
		str[var->i])
		asm_error(14, cur->current_line, asm_ms);
}

void	one_arg_dir_number(char *str, t_asm *asm_ms, t_token *cur, t_var *var)
{
	str[var->i] == '-' && ((!str[var->i + 1] ||
		!(is_number_char(str[var->i + 1])))) ?
	asm_error(14, cur->current_line, asm_ms) : var->i++;
	while (str[var->i] && is_number_char(str[var->i]))
		var->i++;
	var->j = var->i;
	is_spacei(str, &var->i);
	if (str[var->i] != COMMENT_CHAR && str[var->i] != ALT_COMMENT_CHAR &&
		str[var->i])
		asm_error(14, cur->current_line, asm_ms);
}

int		one_argument(t_asm *asm_ms, char *str, t_token *current)
{
	t_var var;

	ft_bzero(&var, sizeof(t_var));
	if (str[var.i] && str[var.i] == DIRECT_CHAR)
		var.i++;
	else if (str[var.i] && str[var.i] == LABEL_CHARS[17] &&
		is_number_char(str[var.i + 1]))
	{
		one_arg_register(str, asm_ms, current, &var);
		return (0);
	}
	else
		asm_error(14, current->current_line, asm_ms);
	if (str[var.i] && str[var.i] == LABEL_CHAR)
		one_arg_dir_label(str, asm_ms, current, &var);
	else if ((str[var.i] == '-' || is_number_char(str[var.i])) && str[var.i])
		one_arg_dir_number(str, asm_ms, current, &var);
	else
		asm_error(14, current->current_line, asm_ms);
	save_info_one_arg(asm_ms, str, current, var.j);
	return (0);
}
