/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_zjmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:40:38 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/12 08:51:33 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	log_zjmp(t_carry *carry, int a)
{
	ft_printf("P %4d | zjmp %d %s\n",
		carry->id, a, (carry->carry) ? "OK" : "FAILED");
}
