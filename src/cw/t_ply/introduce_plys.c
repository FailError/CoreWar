/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introduce_plys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 21:02:47 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/31 21:12:36 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		introduce_plys(t_cw *cw)
{
	t_ply	*ply;

	ply = cw->players;
	if (!ply)
		terminate(1, cw);
	ft_printf("Introducing contestants...\n");
	while (ply)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			ply->id, ply->code_size, ply->name, ply->comment);
		ply = ply->next;
	}
}
