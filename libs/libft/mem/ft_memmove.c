/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:54:12 by bharrold          #+#    #+#             */
/*   Updated: 2018/11/27 13:12:05 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*psrc;
	char	*pdst;
	size_t	i;

	i = -1;
	psrc = (char *)src;
	pdst = (char *)dst;
	if (psrc < pdst)
		while ((int)(--len) >= 0)
			*(pdst + len) = *(psrc + len);
	else
		while (++i < len)
			*(pdst + i) = *(psrc + i);
	return (dst);
}
