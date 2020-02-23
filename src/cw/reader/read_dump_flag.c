/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dump_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:23:17 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:43:47 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		read_dump_flag(t_cw *cw, int *i, char **argv)
{
	*i += 1;
	if (!ft_isnumber(argv[*i]))
		terminate(5, cw);
	cw->d_cycles = ft_atoi(argv[*i]);
}
