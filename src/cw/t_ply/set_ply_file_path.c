/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ply_file_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 19:21:27 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:53:52 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	s_terminate(t_cw *cw, t_ply *ply)
{
	destroy_ply(ply);
	terminate(3, cw);
}

t_ply		*set_ply_file_path(t_ply *ply, char *file_path, t_cw *cw)
{
	if (!ply)
		terminate(3, cw);
	if (!file_path)
		s_terminate(cw, ply);
	ply->file_path = ft_strdup(file_path);
	return (ply);
}
