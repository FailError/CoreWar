/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_live.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:38:32 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/12 08:46:11 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	log_live(int carry, int id)
{
	ft_printf("P %4d | live %d\n", carry, id);
}

void	log_live_msg(int id, char *player_name)
{
	ft_printf("Player %d (%s) is said to be alive\n",
		id, player_name);
}
