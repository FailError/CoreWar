/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:27:40 by bharrold          #+#    #+#             */
/*   Updated: 2019/01/21 15:27:57 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	** Converting undigned long long to ascii in base;
	** Returns (char*) or NULL in case of malloc failed;
*/

char		*ft_lltoa(long long num, int base)
{
	char				*buf;
	unsigned long long	unum;
	int					sign;
	int					i;

	if (num == 0)
		return (ft_strdup("0"));
	i = ft_lllen(num, base);
	sign = (num < 0) ? -1 : 1;
	unum = (num < 0) ? (unsigned long long)num * -1 : (unsigned long long)num;
	if (!(buf = (char*)malloc(sizeof(char) * (i + 1))))
		return ((void*)0);
	buf[0] = (sign < 0) ? '-' : buf[0];
	buf[i] = 0;
	--i;
	while (unum)
	{
		buf[i] = "0123456789abcdef"[unum % base];
		i--;
		unum /= base;
	}
	return (buf);
}
