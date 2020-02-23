/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_project.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbessa <kbessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 17:00:45 by kbessa            #+#    #+#             */
/*   Updated: 2020/02/16 17:01:52 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_tokens(t_asm *asm_ms)
{
	t_token *t_curr;

	if (asm_ms->first)
	{
		t_curr = asm_ms->first;
		while (t_curr->next)
		{
			t_curr = asm_ms->first->next;
			asm_ms->first->arg1 ? free(asm_ms->first->arg1) : 0;
			asm_ms->first->arg2 ? free(asm_ms->first->arg2) : 0;
			asm_ms->first->arg3 ? free(asm_ms->first->arg3) : 0;
			asm_ms->first->output ? free(asm_ms->first->output) : 0;
			asm_ms->first ? free(asm_ms->first) : 0;
			asm_ms->first = t_curr;
		}
		asm_ms->first->arg1 ? free(asm_ms->first->arg1) : 0;
		asm_ms->first->arg2 ? free(asm_ms->first->arg2) : 0;
		asm_ms->first->arg3 ? free(asm_ms->first->arg3) : 0;
		asm_ms->first->output ? free(asm_ms->first->output) : 0;
		free(asm_ms->first);
	}
}
