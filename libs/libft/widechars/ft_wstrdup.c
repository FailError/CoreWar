/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:14:18 by bharrold          #+#    #+#             */
/*   Updated: 2019/01/21 15:14:33 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wstrdup(const wchar_t *wstr)
{
	wchar_t	*dest;
	int		i;

	i = 0;
	if (!(dest = (wchar_t *)malloc(sizeof(wchar_t) * (ft_wstrlen(wstr) + 1))))
		return (0);
	while (wstr[i])
	{
		dest[i] = wstr[i];
		++i;
	}
	dest[i] = L'\0';
	return (dest);
}
