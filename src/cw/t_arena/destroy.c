/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:39:42 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:48:59 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	destroy_arena_map(t_cw *cw)
{
	if (cw->arena->data == NULL)
		return ;
	free(cw->arena->data);
}

void		destroy_arena(t_cw *cw)
{
	if (cw->arena == NULL)
		return ;
	destroy_arena_map(cw);
	free(cw->arena);
}
