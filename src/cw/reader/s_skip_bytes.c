/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_skip_bytes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:26:41 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:46:02 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	skip_bytes(int fd, t_cw *cw)
{
	char	*ptr;

	if (!(ptr = ft_strnew(INT_SIZE)))
		terminate(1, cw);
	if (read(fd, ptr, INT_SIZE) != INT_SIZE)
	{
		free(ptr);
		terminate(1, cw);
	}
	free(ptr);
}
