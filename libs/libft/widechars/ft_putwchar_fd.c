/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 22:14:18 by bharrold          #+#    #+#             */
/*   Updated: 2019/01/20 22:20:00 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwchar_fd(wchar_t c, int fd)
{
	int done;

	done = 0;
	if (c <= 0x7F)
		done += ft_putchar_fd(c, fd);
	else if (c <= 0x7FF)
	{
		done += ft_putchar_fd((c >> 6) | 0xC0, fd);
		done += ft_putchar_fd((c & 0x3F) | 0x80, fd);
	}
	else if (c <= 0xFFFF)
	{
		done += ft_putchar_fd((c >> 12) | 0xE0, fd);
		done += ft_putchar_fd(((c >> 6) & 0x3F) | 0x80, fd);
		done += ft_putchar_fd((c & 0x3F) | 0x80, fd);
	}
	else if (c <= 0x10FFFF)
	{
		done += ft_putchar_fd((c >> 18) | 0xF0, fd);
		done += ft_putchar_fd(((c >> 12) & 0x3F) | 0x80, fd);
		done += ft_putchar_fd(((c >> 6) & 0x3F) | 0x80, fd);
		done += ft_putchar_fd((c & 0x3F) | 0x80, fd);
	}
	return (done);
}
