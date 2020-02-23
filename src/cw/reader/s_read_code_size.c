/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _read_code_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:26:16 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:44:14 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	s_terminate(t_cw *cw, uint8_t *ptr)
{
	free(ptr);
	terminate(1, cw);
}

int			read_code_size(int fd, t_cw *cw)
{
	int		result;
	uint8_t	*ptr;

	result = 0;
	if (!(ptr = ft_memalloc(INT_SIZE)))
		terminate(1, cw);
	if (read(fd, ptr, INT_SIZE) != INT_SIZE)
		s_terminate(cw, ptr);
	result = bytes_to_int(ptr, 4);
	if (result < 0 || result > 682)
		s_terminate(cw, ptr);
	free(ptr);
	return (result);
}
