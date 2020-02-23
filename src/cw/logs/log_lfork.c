/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_lfork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:38:13 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/12 08:42:59 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	log_lfork(t_carry *carry, int a)
{
	ft_printf("P %4d | lfork %d (%d)\n", carry->id, a, carry->position + a);
}
