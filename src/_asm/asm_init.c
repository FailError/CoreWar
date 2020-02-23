/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:09:34 by kturnips          #+#    #+#             */
/*   Updated: 2020/02/10 16:11:03 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		init_label(char **str, t_label *label, t_asm *asm_ms, int i)
{
	t_token *new;

	new = NULL;
	label->next = NULL;
	label->byte = asm_ms->current_byte;
	if (!(label->name = ft_strsub(*str, 0, i)))
		asm_error(4, -1, asm_ms);
	*str += i + 1;
	is_space(str);
	if (!(is_comment(*str)) && (**str))
	{
		new = init_token_p1(asm_ms);
		check_command(asm_ms, *str, new);
	}
	return (1);
}

t_token	*init_token_p1(t_asm *asm_ms)
{
	t_token *temp;

	temp = asm_ms->first;
	if (!(asm_ms->first))
	{
		if (!(asm_ms->first = (t_token *)(ft_memalloc(sizeof(t_token)))))
			asm_error(4, -1, asm_ms);
		temp = asm_ms->first;
	}
	else
	{
		while (temp->next)
			temp = temp->next;
		if (!(temp->next = (t_token *)(ft_memalloc(sizeof(t_token)))))
			asm_error(4, -1, asm_ms);
		temp = temp->next;
	}
	temp->current_line = asm_ms->current_line;
	return (temp);
}

void	init_asm_ms(t_asm *asm_ms)
{
	ft_memset(asm_ms, 0, sizeof(t_asm));
	asm_ms->fd_r = -1;
	asm_ms->fd_w = -1;
	asm_ms->first = 0;
}
