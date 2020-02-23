/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_code_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 20:34:55 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:30:46 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	s_terminate(t_cw *cw, t_ply *ply)
{
	destroy_ply(ply);
	terminate(3, cw);
}

t_ply		*set_ply_code_size(t_ply *ply, int code_size, t_cw *cw)
{
	if (!ply)
		terminate(3, cw);
	if (code_size < 0 || code_size > 682)
		s_terminate(cw, ply);
	ply->code_size = code_size;
	return (ply);
}
