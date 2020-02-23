/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:16:42 by bharrold          #+#    #+#             */
/*   Updated: 2018/11/26 17:03:07 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *p;

	p = s;
	while (*p)
		p++;
	if (c == 0)
		return ((char*)p);
	while (p >= s)
	{
		if (*p == (const char)c)
			return ((char*)p);
		p--;
	}
	return (NULL);
}
