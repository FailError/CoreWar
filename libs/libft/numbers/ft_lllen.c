/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lllen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:26:12 by bharrold          #+#    #+#             */
/*   Updated: 2019/01/28 22:54:39 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	** Function returns long long len in base;
*/

int	ft_lllen(long long num, int base)
{
	int		len;

	base = (base == 0) ? 10 : base;
	len = (num < 0) ? 1 : 0;
	while (num)
	{
		len++;
		num /= base;
	}
	return (len);
}
