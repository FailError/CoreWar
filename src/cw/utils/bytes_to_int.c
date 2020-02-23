/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytes_to_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:30:05 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:58:06 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	bytes_to_int(uint8_t *bytes, size_t size)
{
	int result;
	int i;
	int sign;

	sign = (bytes[0] & 0x80);
	i = 0;
	result = 0;
	while (size)
	{
		if (!sign)
			result += (bytes[size - 1] & 0xFF) << (8 * i);
		else
			result += (bytes[size - 1]) << (8 * i);
		i++;
		size--;
	}
	if (sign)
		result = ~result;
	return (result);
}

int	arena_bytes_to_int(const uint8_t *arena, int addr, int size)
{
	int			result;
	int			sign;
	int			i;

	result = 0;
	sign = (int)(arena[calc_addr(addr)] & 0x80);
	i = 0;
	while (size)
	{
		if (sign)
			result += ((arena[calc_addr(addr + size - 1)] ^ 0xFF) << (i++ * 8));
		else
			result += arena[calc_addr(addr + size - 1)] << (i++ * 8);
		size--;
	}
	if (sign)
		result = ~(result);
	return (result);
}
