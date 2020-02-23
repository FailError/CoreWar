/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 07:49:07 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/14 19:24:33 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

void		log_movement(uint8_t *arena, t_carry *carry)
{
	int	i;

	ft_printf("ADV %d (%0.4p -> %0.4p) ",
		carry->step, carry->position, carry->position + carry->step);
	i = 0;
	while (i < carry->step)
	{
		ft_printf("%02x ", arena[calc_addr(carry->position + i)]);
		i++;
	}
	ft_printf("\n");
}
