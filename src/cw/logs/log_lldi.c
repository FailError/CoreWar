/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_lldi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:39:03 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/12 08:54:42 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	log_lldi(t_carry *carry, int a1, int a2, int r)
{
	ft_printf("P %4d | lldi %d %d r%d\n", carry->id, a1, a2, r);
	ft_printf("       | -> load from %d + %d = %d (with pc %d)\n",
		a1, a2, a1 + a2, carry->position + (a1 + a2));
}
