/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_in_byte.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:13:41 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:48:10 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_player_in_byte(t_cw *cw, int byte)
{
	int	i;

	if (!cw->arena)
		terminate(1, cw);
	if (!cw->arena->data)
		terminate(1, cw);
	i = 1;
	if (byte > 4095)
		byte = byte % 4096;
	while (i < MAX_PLAYERS && i < cw->count_players)
	{
		if (byte < cw->arena->sections[i] && byte >= cw->arena->sections[i - 1])
			break ;
		i++;
	}
	if (i > 0 && i <= MAX_PLAYERS)
		return (i);
	return (-1);
}
