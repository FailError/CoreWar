/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:27:20 by bharrold          #+#    #+#             */
/*   Updated: 2019/02/01 15:04:19 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_zero_printed(t_spec *spec)
{
	if (spec->width > 0 && spec->flags[e_flag_less] == 0 &&
		spec->flags[e_flag_zero] == 1)
		return (1);
	return (0);
}

int		is_space_printed(t_spec *spec)
{
	if (spec->width > 0 && spec->flags[e_flag_less] == 0 &&
		spec->flags[e_flag_zero] == 0)
		return (1);
	return (0);
}

void	handle_bad_conv(char **format, t_spec *spec, t_buff *buff)
{
	if (spec->flags[e_flag_less] == 0)
	{
		if (spec->flags[e_flag_zero])
			pf_printnchar(buff, '0', spec->width - 1);
		else
			pf_printnchar(buff, ' ', spec->width - 1);
	}
	else
	{
		pf_printnchar(buff, **format, 1);
		pf_printnchar(buff, ' ', spec->width - 1);
	}
}
