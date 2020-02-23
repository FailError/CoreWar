/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_recognitions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 19:48:41 by bharrold          #+#    #+#             */
/*   Updated: 2019/01/31 20:16:28 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_recognition(char **format, t_spec *spec)
{
	while (is_flag(**format))
	{
		if (**format == '#')
			spec->flags[e_flag_hashtag] = 1;
		else if (**format == '0')
			spec->flags[e_flag_zero] = 1;
		else if (**format == '-')
			spec->flags[e_flag_less] = 1;
		else if (**format == '+')
			spec->flags[e_flag_more] = 1;
		else if (**format == ' ')
			spec->flags[e_flag_space] = 1;
		*format = *format + 1;
	}
	if (spec->flags[e_flag_less])
		spec->flags[e_flag_zero] = 0;
	if (spec->flags[e_flag_more])
		spec->flags[e_flag_space] = 0;
}

void	width_recognition(char **str, t_spec *spec)
{
	while (is_number(**str))
	{
		spec->width = spec->width * 10 + ((**str - 48) % 10);
		*str = *str + 1;
	}
}

void	precision_recognition(char **str, t_spec *spec)
{
	*str = *str + 1;
	spec->precision = 0;
	while (is_number(**str))
	{
		spec->precision = spec->precision * 10 + ((**str - 48) % 10);
		*str = *str + 1;
	}
}

void	modif_recognition(char **str, t_spec *spec)
{
	if (**str == 'h' && *(*str + 1) != 'h')
		spec->modif = e_modif_h;
	else if (**str == 'h' && *(*str + 1) == 'h')
	{
		spec->modif = e_modif_hh;
		*str = *str + 1;
	}
	else if (**str == 'l' && *(*str + 1) != 'l')
		spec->modif = e_modif_l;
	if (**str == 'l' && *(*str + 1) == 'l')
	{
		spec->modif = e_modif_ll;
		*str = *str + 1;
	}
	if (**str == 'j')
		spec->modif = e_modif_j;
	if (**str == 'z')
		spec->modif = e_modif_z;
	*str = *str + 1;
}

void	conversion_recognition(char **str, t_spec *spec)
{
	spec->con = **str;
	*str = *str + 1;
	if (spec->con == 'd' || spec->con == 'i' ||
	spec->con == 'u' || spec->con == 'D' || spec->con == 'U')
		spec->base = 10;
	else if (spec->con == 'o' || spec->con == 'O')
		spec->base = 8;
	else if (spec->con == 'x' || spec->con == 'X'
	|| spec->con == 'p')
		spec->base = 16;
	if (spec->con == 'D' || spec->con == 'O' || spec->con == 'U')
	{
		spec->con += 32;
		spec->modif = e_modif_l;
	}
	if (spec->precision >= 0 && spec->con != 'c' && spec->con != 's'
		&& spec->con != 'C' && spec->con != 'S' && spec->con != '%'
		&& spec->con != 'f' && spec->con != 'F')
		spec->flags[e_flag_zero] = 0;
	if (spec->con == 'c' && spec->modif == e_modif_l)
		spec->con = 'C';
	else if (spec->con == 's' && spec->modif == e_modif_l)
		spec->con = 'S';
}
