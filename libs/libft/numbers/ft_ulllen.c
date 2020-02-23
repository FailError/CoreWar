/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulllen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:22:26 by bharrold          #+#    #+#             */
/*   Updated: 2019/01/21 15:38:11 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	** Function returns unsigned long long len in base;
*/

int	ft_ulllen(unsigned long long num, int base)
{
	int		len;

	len = 0;
	while (num)
	{
		len++;
		num /= base;
	}
	return (len);
}
