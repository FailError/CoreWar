/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:06:16 by bharrold          #+#    #+#             */
/*   Updated: 2018/11/27 11:05:05 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *p1;
	unsigned char *p2;

	if (n == 0)
		return (0);
	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	while (*p1 == *p2 && --n)
	{
		p1++;
		p2++;
	}
	return ((int)(*p1 - *p2));
}
