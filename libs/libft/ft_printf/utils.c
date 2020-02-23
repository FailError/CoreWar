/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 21:03:22 by bharrold          #+#    #+#             */
/*   Updated: 2019/02/01 14:29:06 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_conversion_signed(char c)
{
	if (c == 'd' || c == 'i' || c == 'f' || c == 'F')
		return (1);
	return (0);
}

int		pf_lllen(long long arg, t_spec *spec)
{
	int i;

	i = 1;
	if (arg == 0 && spec->precision == 0)
		return (0);
	while (arg / spec->base)
	{
		i++;
		arg = arg / spec->base;
	}
	return (i);
}

int		pf_ulllen(unsigned long long arg, t_spec *spec)
{
	int i;

	i = 1;
	if (arg == 0 && spec->precision == 0)
		return (0);
	while (arg / spec->base)
	{
		i++;
		arg = arg / spec->base;
	}
	return (i);
}
