/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:24:13 by bharrold          #+#    #+#             */
/*   Updated: 2019/01/21 15:37:17 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	** Converting undigned long long to ascii in base;
	** Returns (char*) or NULL in case of malloc failed;
*/

char		*ft_ulltoa(unsigned long long num, int base)
{
	char				*buf;
	unsigned long long	unum;
	int					i;

	if (num == 0)
		return (ft_strdup("0"));
	i = ft_ulllen(num, base);
	unum = (unsigned long long)num;
	if (!(buf = (char*)malloc(sizeof(char) * (i + 1))))
		return ((void*)0);
	buf[i] = '\0';
	--i;
	while (unum)
	{
		buf[i] = "0123456789abcdef"[unum % base];
		i--;
		unum /= base;
	}
	return (buf);
}
