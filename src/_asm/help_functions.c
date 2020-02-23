/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:27:37 by kturnips          #+#    #+#             */
/*   Updated: 2020/02/10 16:29:24 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_space(char **str)
{
	if (**str && (**str == ' ' || **str == '\t'))
	{
		while (**str && (**str == ' ' || **str == '\t'))
		{
			(*str)++;
		}
		return (1);
	}
	return (0);
}

int		is_comment(char *str)
{
	if (*str && (*str == COMMENT_CHAR || *str == ALT_COMMENT_CHAR))
		return (1);
	return (0);
}

char	arg_byte(int arg1, int arg2, int arg3)
{
	int res;

	res = 0;
	if (arg3 == 1)
		res += 4;
	else if (arg3 == 2)
		res += 8;
	else if (arg3 == 3)
		res += 12;
	if (arg2 == 1)
		res += 16;
	else if (arg2 == 2)
		res += 32;
	else if (arg2 == 3)
		res += 48;
	if (arg1 == 1)
		res += 64;
	else if (arg1 == 2)
		res += 128;
	else if (arg1 == 3)
		res += 192;
	return ((char)res);
}

char	shell_arg_byte(int type_args)
{
	return (arg_byte(type_args / 100, (type_args / 10) % 10, type_args % 10));
}

int		count_label(t_asm *asm_ms, char *str, int byte, t_token *token)
{
	t_label *label;

	label = asm_ms->label;
	while (label)
	{
		if (!(ft_strcmp(label->name, str)))
			return (label->byte - byte);
		label = label->next;
	}
	asm_error(13, token->current_line, asm_ms);
	return (0);
}
