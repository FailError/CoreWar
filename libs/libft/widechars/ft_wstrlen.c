/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:13:45 by bharrold          #+#    #+#             */
/*   Updated: 2019/01/21 15:13:52 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wstrlen(const wchar_t *wstr)
{
	int		i;
	int		len;

	if (wstr)
	{
		i = 0;
		len = 0;
		while (wstr[i])
		{
			len += ft_wclen(wstr[i]);
			i++;
		}
		return (len);
	}
	return (0);
}
