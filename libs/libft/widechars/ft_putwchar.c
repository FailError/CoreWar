/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 22:09:03 by bharrold          #+#    #+#             */
/*   Updated: 2019/01/21 15:21:14 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwchar(wchar_t c)
{
	int done;

	done = 0;
	if (c <= 0x7F)
		done += ft_putchar(c);
	else if (c <= 0x7FF)
	{
		done += ft_putchar((c >> 6) | 0xC0);
		done += ft_putchar((c & 0x3F) | 0x80);
	}
	else if (c <= 0xFFFF)
	{
		done += ft_putchar((c >> 12) | 0xE0);
		done += ft_putchar(((c >> 6) & 0x3F) | 0x80);
		done += ft_putchar((c & 0x3F) | 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		done += ft_putchar((c >> 18) | 0xF0);
		done += ft_putchar(((c >> 12) & 0x3F) | 0x80);
		done += ft_putchar(((c >> 6) & 0x3F) | 0x80);
		done += ft_putchar((c & 0x3F) | 0x80);
	}
	return (done);
}
