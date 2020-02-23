/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 19:30:33 by bharrold          #+#    #+#             */
/*   Updated: 2019/02/01 15:23:16 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_spec(t_spec *spec)
{
	int i;

	i = 0;
	while (i < FLAGS_CNT)
	{
		spec->flags[i] = 0;
		i++;
	}
	spec->con = 0;
	spec->modif = e_modif_no;
	spec->precision = -1;
	spec->width = 0;
	spec->conversion_group = -1;
}

static int	pf_parse(char **format, t_buff *buff, t_spec *spec)
{
	if (is_flag(**format))
		flag_recognition(format, spec);
	if (is_number(**format))
		width_recognition(format, spec);
	if (is_precision(**format))
		precision_recognition(format, spec);
	if (is_modif(**format))
		modif_recognition(format, spec);
	if (is_conversion(**format))
		conversion_recognition(format, spec);
	else
	{
		handle_bad_conv(format, spec, buff);
		return (0);
	}
	return (1);
}

static int	pf_read_spec(char **format, char **save, t_buff *buff, t_spec *spec)
{
	(*format)++;
	if (**format == 0)
		return (1);
	save = format;
	if (!(pf_parse(format, buff, spec)))
	{
		format = save;
		if (spec->flags[e_flag_less] == 1)
			(*format)++;
	}
	else
		return (1);
	return (0);
}

int			pf_read(char **format, t_buff *buff, t_spec *spec)
{
	char	**save;
	char	*color;

	save = NULL;
	color = NULL;
	init_spec(spec);
	while (**format)
	{
		if (**format == '%')
		{
			if (pf_read_spec(format, save, buff, spec))
				return (1);
		}
		add_char_buff(buff, **format);
		(*format)++;
	}
	if (color != NULL)
		add_color_string_buff(buff, ANSI_COLOR_RESET);
	return (1);
}
