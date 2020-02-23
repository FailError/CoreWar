/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumeric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:43:16 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/26 20:45:56 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnumeric(char *str)
{
	size_t	tmp;

	tmp = 0;
	while ((int)str[tmp])
	{
		if (!ft_isdigit(str[tmp]))
			return (0);
		tmp++;
	}
	return (1);
}
