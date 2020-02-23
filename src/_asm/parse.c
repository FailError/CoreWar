/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:27:08 by kturnips          #+#    #+#             */
/*   Updated: 2020/02/10 17:27:46 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	parse_p3(t_asm *asm_ms)
{
	t_token *token;

	token = asm_ms->first;
	while (token)
	{
		if (token->type_args == 0)
			((create_dir_arg(token, 1, 1, asm_ms)));
		else
			create_args(token, asm_ms);
		token = token->next;
	}
}

void	parse_p2(t_asm *asm_ms)
{
	char	*str;
	char	*str1;
	t_token	*new;

	while (get_next_line(asm_ms->fd_r, &str) > 0)
	{
		asm_ms->current_line += 1;
		str1 = str;
		if (is_blank(str1))
			continue;
		is_space(&str1);
		if (!(check_label(&str1, asm_ms)))
		{
			new = init_token_p1(asm_ms);
			check_command(asm_ms, str1, new);
		}
		free(str);
	}
	parse_p3(asm_ms);
}

void	parse_p1(t_asm *asm_ms)
{
	char *str;
	char *str1;

	while (get_next_line(asm_ms->fd_r, &str) > 0)
	{
		asm_ms->current_line += 1;
		str1 = str;
		if (is_blank(str1))
			continue;
		is_space(&str1);
		if (check_name_comment(str1, asm_ms))
			free(str);
		if (asm_ms->name && asm_ms->comment)
			break ;
	}
	parse_p2(asm_ms);
}
