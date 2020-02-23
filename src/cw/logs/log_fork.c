/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:35:11 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/12 08:36:06 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	log_fork(t_carry *carry, int a)
{
	ft_printf("P %4d | fork %d (%d)\n", carry->id, a,
		carry->position + a % IDX_MOD);
}
