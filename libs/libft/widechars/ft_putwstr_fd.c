/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 22:18:35 by bharrold          #+#    #+#             */
/*   Updated: 2019/01/20 22:22:28 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwstr_fd(const wchar_t *wstr, int fd)
{
	int done;

	done = 0;
	while (wstr && *wstr)
		done += ft_putwchar_fd(*wstr++, fd);
	return (done);
}
