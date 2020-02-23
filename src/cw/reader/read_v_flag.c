/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_v_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:35:51 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/12 08:08:51 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	read_v_flag(t_cw *cw, int *i, char **argv)
{
	*i += 1;
	if (!ft_isnumber(argv[*i]))
		terminate(5, cw);
	cw->v = ft_atoi(argv[*i]);
}
