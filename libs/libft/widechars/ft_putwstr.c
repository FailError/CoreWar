/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 22:11:13 by bharrold          #+#    #+#             */
/*   Updated: 2019/01/31 20:05:55 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwstr(const wchar_t *wstr)
{
	int done;

	done = 0;
	while (wstr && *wstr)
		done += ft_putwchar(*wstr++);
	return (done);
}
