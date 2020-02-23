/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:12:37 by kturnips          #+#    #+#             */
/*   Updated: 2020/02/10 18:07:20 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_labelchar(char c)
{
	int i;

	i = -1;
	while (LABEL_CHARS[++i])
		if (LABEL_CHARS[i] == c)
			return (1);
	return (0);
}

int		check_label(char **str, t_asm *asm_ms)
{
	int		i;
	t_label	*temp;

	i = 0;
	while ((*str)[i] && is_labelchar((*str)[i]))
		i++;
	if ((*str)[i] != LABEL_CHAR)
		return (0);
	if (!asm_ms->label)
	{
		if (!(asm_ms->label = (t_label *)(malloc(sizeof(t_label)))))
			asm_error(4, -1, asm_ms);
		temp = asm_ms->label;
	}
	else
	{
		temp = asm_ms->label;
		while (temp->next)
			temp = temp->next;
		if (!(temp->next = (t_label *)(malloc(sizeof(t_label)))))
			asm_error(4, -1, asm_ms);
		temp = temp->next;
	}
	return (init_label(str, temp, asm_ms, i));
}
