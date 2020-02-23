/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bytes_at_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:15:34 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/31 19:18:31 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

uint8_t		*get_bytes_at_position(t_cw *cw, int position)
{
	position = calc_addr(position);
	ft_printf("%d\n", position);
	if (position < 0 || position > MEM_SIZE)
		terminate(10, cw);
	return (cw->arena->data + position);
}
