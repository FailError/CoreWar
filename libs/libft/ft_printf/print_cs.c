/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:09:05 by bharrold          #+#    #+#             */
/*   Updated: 2019/02/01 14:30:14 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		padding_left(t_spec *spec, int len, t_buff *buff)
{
	if (spec->precision == -1)
	{
		spec->width = spec->width - len;
		spec->precision = len;
	}
	else
	{
		if (spec->precision > len)
			spec->width -= len;
		else
			spec->width -= spec->precision;
	}
	if (spec->width > 0 && spec->flags[e_flag_less] == 0)
	{
		if (spec->flags[e_flag_zero] == 1)
			pf_printnchar(buff, '0', spec->width);
		else
			pf_printnchar(buff, ' ', spec->width);
	}
}

int				print_s(t_spec *spec, t_buff *buff, va_list *ap)
{
	char	*str;
	int		len;

	str = (char *)va_arg(*ap, char*);
	len = 6;
	if (str != NULL && spec->precision != 0)
		len = ft_strlen(str);
	padding_left(spec, len, buff);
	if (str == NULL)
		pf_printstr(buff, "(null)\0", spec->precision);
	else if (spec->precision != 0)
	{
		while (*str && spec->precision > 0)
		{
			add_char_buff(buff, *str);
			str = str + 1;
			spec->precision--;
		}
	}
	if (spec->flags[e_flag_less])
		pf_printnchar(buff, ' ', spec->width);
	return (0);
}

int				print_c(t_spec *spec, t_buff *buff, va_list *ap)
{
	if (spec->flags[e_flag_less] == 0)
	{
		if (spec->flags[e_flag_zero] == 1)
			pf_printnchar(buff, '0', spec->width - 1);
		else
			pf_printnchar(buff, ' ', spec->width - 1);
	}
	pf_printnchar(buff, (char)va_arg(*ap, int), 1);
	if (spec->flags[e_flag_less])
		pf_printnchar(buff, ' ', spec->width - 1);
	return (0);
}

int				print_prc(t_spec *spec, t_buff *buff, va_list *ap)
{
	(void)*ap;
	if (spec->flags[e_flag_less] == 0)
	{
		if (spec->flags[e_flag_zero] == 1)
			pf_printnchar(buff, '0', spec->width - 1);
		else
			pf_printnchar(buff, ' ', spec->width - 1);
	}
	pf_printnchar(buff, '%', 1);
	if (spec->flags[e_flag_less])
		pf_printnchar(buff, ' ', spec->width - 1);
	return (0);
}
