/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 21:06:26 by bharrold          #+#    #+#             */
/*   Updated: 2019/02/01 15:08:55 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_printnchar(t_buff *buff, char c, int n)
{
	while (n > 0)
	{
		add_char_buff(buff, c);
		--n;
	}
}

void	pf_printstr(t_buff *buff, char *str, int precision)
{
	if (precision < 0)
		precision = 6;
	while (*str && precision > 0)
	{
		add_char_buff(buff, *str);
		str++;
		precision--;
	}
}

void	pf_print_size_and_prefix(t_spec *spec, t_buff *buff, t_padding pad)
{
	if (is_conversion_signed(spec->con) == 1)
	{
		if (pad.sign == -1)
			add_char_buff(buff, '-');
		else if (spec->flags[e_flag_more] && pad.sign == 0)
			add_char_buff(buff, '+');
		else if (spec->flags[e_flag_space] && pad.sign == 0)
			add_char_buff(buff, ' ');
	}
	if (spec->flags[e_flag_hashtag] == 1)
	{
		add_char_buff(buff, '0');
		if (spec->con == 'x' || spec->con == 'X')
			add_char_buff(buff, spec->con);
	}
}
