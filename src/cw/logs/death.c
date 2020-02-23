/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 07:49:07 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/12 08:46:50 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

void	log_death(t_cw *cw, t_carry *carry)
{
	ft_printf("Process %i hasn't lived for %i cycles (CTD %i)\n",
		carry->id, cw->cycles - carry->live_cycle, cw->cycles_to_die);
}
