/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:45:18 by bharrold          #+#    #+#             */
/*   Updated: 2018/11/26 15:58:18 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!s || !f)
		return (NULL);
	ptr = ft_strnew(ft_strlen(s));
	if (ptr)
	{
		i = 0;
		while (s[i])
		{
			ptr[i] = f(i, s[i]);
			i++;
		}
	}
	return (ptr);
}
