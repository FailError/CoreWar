/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:09:54 by bharrold          #+#    #+#             */
/*   Updated: 2018/11/27 11:35:38 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	ptr = NULL;
	if (start + len <= slen)
	{
		ptr = ft_strnew(len);
		if (ptr)
		{
			ptr = ft_strncpy(ptr, s + start, len);
			ptr[len] = '\0';
		}
	}
	return (ptr);
}
