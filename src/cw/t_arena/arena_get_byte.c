/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_get_byte.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 22:10:29 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/03 22:12:05 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

uint8_t	arena_get_byte(t_cw *cw, int position, int step)
{
	return (cw->arena->data[calc_addr(position + step)]);
}
