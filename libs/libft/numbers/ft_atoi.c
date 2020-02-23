/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:27:59 by bharrold          #+#    #+#             */
/*   Updated: 2018/11/27 13:06:47 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		result;
	int		sign;
	size_t	i;

	result = 0;
	sign = 1;
	i = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r' || *str == '0')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (i == 10 && sign == -1)
			return (0);
		if (i == 10 && sign == 1)
			return (-1);
		result = result * 10 + *str - '0';
		str++;
		i++;
	}
	return (result * sign);
}
