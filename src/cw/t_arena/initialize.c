/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:38:40 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:47:58 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	initialize_arena_sections(t_cw *cw)
{
	int i;

	if (cw->arena == NULL)
		terminate(1, cw);
	if (cw->arena->data == NULL)
		terminate(1, cw);
	if (cw->count_players == 0 || cw->count_players > MAX_PLAYERS)
		terminate(1, cw);
	i = -1;
	while (++i < cw->count_players)
		cw->arena->sections[i] = (!i) ? 0 :
			cw->arena->arena_size / cw->count_players * i;
	while (i < MAX_PLAYERS)
	{
		cw->arena->sections[i] = -1;
		i++;
	}
}

static void	initialize_map_arena(t_cw *cw)
{
	if (cw->arena == NULL)
		terminate(1, cw);
	cw->arena->data = (uint8_t*)ft_memalloc(cw->arena->arena_size);
	ft_bzero(cw->arena->data, 4096);
	if (!cw->arena->data)
		terminate(1, cw);
}

static void	initialize_plys_code(t_cw *cw)
{
	int		i;
	t_ply	*ply;

	i = 0;
	ply = cw->players;
	while (ply)
	{
		if (!ply->code)
			continue;
		if (ply->code_size > 0)
			ft_memcpy(cw->arena->data + cw->arena->sections[i], ply->code,
				ply->code_size);
		i++;
		ply = ply->next;
	}
}

void		initialize_arena(t_cw *cw)
{
	if (cw->arena != NULL)
		terminate(1, cw);
	if (!(cw->arena = (t_arena*)ft_memalloc(sizeof(t_arena))))
		terminate(1, cw);
	cw->arena->data = NULL;
	cw->arena->arena_size = MEM_SIZE;
	initialize_map_arena(cw);
	initialize_arena_sections(cw);
	initialize_plys_code(cw);
}
