/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:25:40 by bharrold          #+#    #+#             */
/*   Updated: 2018/11/26 23:44:11 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char *begin_ptr;
	const char *pneed;

	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while (*haystack)
	{
		begin_ptr = haystack;
		pneed = needle;
		while (*haystack && *pneed && *haystack == *pneed)
		{
			haystack++;
			pneed++;
		}
		if (*pneed == '\0')
			return ((char*)begin_ptr);
		haystack = begin_ptr + 1;
	}
	return (NULL);
}
