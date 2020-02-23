/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_byte.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 20:22:00 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:55:49 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

inline int8_t		carry_get_byte(t_cw *cw, t_carry *carry, int step)
{
	return (cw->arena->data[calc_addr(carry->position + step)]);
}
