/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_bytes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:06:51 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:55:27 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	int_to_bytecode(t_cw *cw, int addr, int val, int size)
{
	int8_t i;

	i = 0;
	while (size)
	{
		cw->arena->data[calc_addr(addr + size - 1)] =
			(uint8_t)((val >> i) & 0xFF);
		i += 8;
		size--;
	}
}
