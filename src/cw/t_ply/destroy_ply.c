/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_ply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:10:24 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:53:56 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	pokeout(t_ply *ply)
{
	if (ply->next && ply->prev)
	{
		ply->prev->next = ply->next;
		ply->next->prev = ply->prev;
	}
	if (!ply->next && ply->prev)
		ply->prev->next = NULL;
	if (ply->next && !ply->prev)
		ply->next->prev = NULL;
}

void		destroy_ply(t_ply *ply)
{
	if (!ply)
		return ;
	if (ply->name)
		free(ply->name);
	if (ply->comment)
		free(ply->comment);
	if (ply->code)
		free(ply->code);
	if (ply->file_path)
		free(ply->file_path);
	if (ply->id)
		ply->id = -1;
	if (ply->code_size)
		ply->code_size = 0;
	pokeout(ply);
	free(ply);
}
