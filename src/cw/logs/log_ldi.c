/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_ldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:37:54 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/12 08:53:16 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	log_ldi(t_carry *carry, int a1, int a2, int r)
{
	ft_printf("P %4d | ldi %d %d r%d\n", carry->id, a1, a2, r);
	ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
		a1, a2, a1 + a2, carry->position + (a1 + a2) % IDX_MOD);
}
