/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _read_magic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:26:21 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:44:32 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	read_magic(int fd, t_cw *cw)
{
	uint8_t	*ptr;
	int		magic;

	if (!(ptr = (uint8_t*)ft_memalloc(INT_SIZE)))
		terminate(1, cw);
	ft_bzero(ptr, INT_SIZE);
	if (read(fd, ptr, INT_SIZE) != INT_SIZE)
		terminate(1, cw);
	magic = bytes_to_int(ptr, INT_SIZE);
	if (magic != COREWAR_EXEC_MAGIC)
		terminate(1, cw);
	free(ptr);
	return ;
}
