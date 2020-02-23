/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:42:22 by bharrold          #+#    #+#             */
/*   Updated: 2018/11/21 19:53:04 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*begin_ptr;
	const char	*pneed;
	size_t		i;

	i = 0;
	while (*haystack && len)
	{
		begin_ptr = haystack;
		pneed = needle;
		i = len;
		while (*haystack && *pneed && len && *haystack == *pneed)
		{
			haystack++;
			pneed++;
			len--;
		}
		if (*pneed == '\0')
			return ((char*)begin_ptr);
		haystack = begin_ptr + 1;
		len = i - 1;
	}
	return (NULL);
}
