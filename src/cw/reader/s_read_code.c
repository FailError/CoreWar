/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_read_code.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:26:04 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:47:03 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

uint8_t		*read_code(int fd, int size, t_cw *cw)
{
	uint8_t		*code;
	int			ret;

	if (!(code = (uint8_t*)ft_memalloc(size)))
		terminate(1, cw);
	if ((ret = read(fd, code, size)) != size)
		terminate(1, cw);
	if ((ret = read(fd, code, 1)) == 1)
		terminate(1, cw);
	return (code);
}
