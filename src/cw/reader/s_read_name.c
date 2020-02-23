/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_read_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:26:26 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:46:20 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*read_name(int fd, t_cw *cw)
{
	char	*name;

	if (!(name = ft_strnew(PROG_NAME_LENGTH)))
		terminate(1, cw);
	if (read(fd, name, PROG_NAME_LENGTH) != PROG_NAME_LENGTH)
		terminate(1, cw);
	return (name);
}
