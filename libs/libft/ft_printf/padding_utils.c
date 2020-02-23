/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 20:54:41 by bharrold          #+#    #+#             */
/*   Updated: 2019/02/01 15:09:15 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_padding(t_padding *pad, t_spec *spec, int size)
{
	pad->sign = 0;
	pad->size = size;
	pad->width = spec->width - size;
	pad->precision = spec->precision - size;
	if (pad->precision > 0)
		pad->width -= pad->precision;
	pad->arg_zero = 0;
}

void	calculate_padding(t_padding *pad, t_spec *spec)
{
	if (spec->con == 'o')
	{
		if (pad->arg_zero && spec->precision != 0)
			spec->flags[e_flag_hashtag] = 0;
		if (spec->flags[e_flag_hashtag] == 1)
		{
			if (pad->precision < 1)
				pad->width -= 1;
			pad->precision -= 1;
		}
	}
	else
	{
		if (is_conversion_signed(spec->con))
		{
			if (pad->sign == -1 || spec->flags[e_flag_more] == 1
			|| spec->flags[e_flag_space] == 1)
				pad->width -= 1;
		}
		if (pad->arg_zero)
			spec->flags[e_flag_hashtag] = 0;
		if (spec->flags[e_flag_hashtag] == 1)
			pad->width -= 2;
	}
}

void	print_padding(t_spec *spec, t_padding pad, t_buff *buff)
{
	if (pad.width > 0 && spec->flags[e_flag_less] == 0)
	{
		if (spec->flags[e_flag_zero] == 1)
		{
			pf_print_size_and_prefix(spec, buff, pad);
			pf_printnchar(buff, '0', pad.width);
		}
		else
		{
			pf_printnchar(buff, ' ', pad.width);
			pf_print_size_and_prefix(spec, buff, pad);
		}
	}
	else
		pf_print_size_and_prefix(spec, buff, pad);
	if (pad.precision > 0)
		pf_printnchar(buff, '0', pad.precision);
}
