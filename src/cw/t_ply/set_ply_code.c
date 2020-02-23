/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ply_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 20:46:28 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:53:39 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_terminate(t_cw *cw, t_ply *ply)
{
	destroy_ply(ply);
	terminate(3, cw);
}

t_ply			*set_ply_code(t_ply *ply, uint8_t *code, int code_size,
						t_cw *cw)
{
	if (!ply)
		terminate(3, cw);
	if (code_size < 0 || code_size > 682)
		s_terminate(cw, ply);
	if (!(ply->code = (uint8_t*)ft_memalloc(code_size)))
		s_terminate(cw, ply);
	ft_memcpy(ply->code, code, code_size);
	return (ply);
}
