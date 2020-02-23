/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:30:01 by bharrold          #+#    #+#             */
/*   Updated: 2018/11/20 21:50:16 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dest;
	int		i;

	i = 0;
	if ((dest = (char *)malloc(ft_strlen(str) + 1)) == NULL)
		return (0);
	while (str[i])
	{
		dest[i] = str[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
