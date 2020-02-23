/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:18:52 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/17 20:12:33 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len;

	ptr = NULL;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		ptr = ft_strnew(len + 1);
		if (ptr)
		{
			ft_strcpy(ptr, s1);
			ft_strcat(ptr, s2);
		}
	}
	if (!s1 && s2)
	{
		ptr = ft_strdup(s2);
	}
	return (ptr);
}
