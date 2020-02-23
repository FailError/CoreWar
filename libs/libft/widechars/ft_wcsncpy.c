/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:14:46 by bharrold          #+#    #+#             */
/*   Updated: 2019/01/31 20:05:51 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wcsncpy(wchar_t *dst, const wchar_t *src, ssize_t n)
{
	wchar_t					*d;
	const wchar_t			*s;
	ssize_t					tlen;

	d = dst;
	s = src;
	while (n && s && *s)
	{
		if (s && *s && n < ft_wclen(*s))
			break ;
		tlen = ft_wclen(*s);
		*d++ = *s++;
		n = (n - tlen < 0) ? 0 : n - tlen;
	}
	*d = 0;
	while (n--)
		*d++ = '\0';
	return (dst);
}
