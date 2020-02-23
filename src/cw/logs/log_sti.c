/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_sti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:39:57 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/12 09:03:46 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	log_sti(t_carry *carry, int r, int a1, int a2)
{
	ft_printf("P %4d | sti r%d %d %d\n",
		carry->id, r, a1, a2);
	ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
		a1, a2, a1 + a2, carry->position + ((a1 + a2) % IDX_MOD));
}
