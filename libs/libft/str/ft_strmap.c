/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:36:20 by bharrold          #+#    #+#             */
/*   Updated: 2018/11/26 15:57:26 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr;
	size_t	i;

	if (!s || !f)
		return (NULL);
	ptr = ft_strnew(ft_strlen(s));
	if (ptr)
	{
		i = 0;
		while (s[i])
		{
			ptr[i] = f(s[i]);
			i++;
		}
	}
	return (ptr);
}
