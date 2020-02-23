/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwnchar_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 22:21:39 by bharrold          #+#    #+#             */
/*   Updated: 2019/01/20 22:21:42 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwnchar_fd(wchar_t wc, int n, int fd)
{
	int i;
	int done;

	done = 0;
	i = -1;
	while (++i < n)
		done += ft_putwchar_fd(wc, fd);
	return (done);
}
