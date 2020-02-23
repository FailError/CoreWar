/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all_plys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:17:11 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:54:28 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	s_destoy_all_plys(t_cw *cw)
{
	t_ply *ptr;
	t_ply *next;

	ptr = cw->players;
	while (ptr)
	{
		next = ptr->next;
		destroy_ply(ptr);
		ptr = next;
	}
}

void		destroy_all_plys(t_cw *cw)
{
	if (!cw)
		return ;
	if (!cw->players)
		return ;
	s_destoy_all_plys(cw);
}
