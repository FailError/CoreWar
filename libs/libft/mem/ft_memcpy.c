/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:16:53 by bharrold          #+#    #+#             */
/*   Updated: 2018/11/26 17:36:57 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char *dst_ptr;
	unsigned char *src_ptr;

	dst_ptr = (unsigned char*)dst;
	src_ptr = (unsigned char*)src;
	while (n--)
		*dst_ptr++ = *src_ptr++;
	return (dst);
}
