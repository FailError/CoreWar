/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lcls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:28:39 by bharrold          #+#    #+#             */
/*   Updated: 2019/02/01 14:27:35 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		pf_putwchar(t_buff *buff, wchar_t wc)
{
	if (wc <= 0x7F)
		add_char_buff(buff, wc);
	else if (wc <= 0x7FF)
	{
		add_char_buff(buff, (wc >> 6) | 0xC0);
		add_char_buff(buff, (wc & 0x3F) | 0x80);
	}
	else if (wc <= 0xFFFF)
	{
		add_char_buff(buff, (wc >> 12) | 0xE0);
		add_char_buff(buff, ((wc >> 6) & 0x3F) | 0x80);
		add_char_buff(buff, ((wc & 0x3F) | 0x80));
	}
	else if (wc <= 0x10FFFF)
	{
		add_char_buff(buff, (wc >> 18) | 0xF0);
		add_char_buff(buff, ((wc >> 12) & 0x3F) | 0x80);
		add_char_buff(buff, ((wc >> 6) & 0x3F) | 0x80);
		add_char_buff(buff, (wc & 0x3F) | 0x80);
	}
}

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

int				wc_precision(wchar_t *str, int precision)
{
	int result_precision;
	int tmp;

	result_precision = 0;
	tmp = 0;
	while (str)
	{
		tmp += ft_wclen(*str);
		if (tmp > precision)
			return (result_precision);
		result_precision = tmp;
		str = str + 1;
	}
	return (result_precision);
}

int				print_lc(t_spec *spec, t_buff *buff, va_list *ap)
{
	wchar_t wc;
	int		wclen;

	wc = (wchar_t)va_arg(*ap, wchar_t);
	wclen = ft_wclen(wc);
	if (spec->flags[e_flag_less] == 0)
	{
		if (spec->flags[e_flag_zero])
			pf_printnchar(buff, '0', spec->width - wclen);
		else
			pf_printnchar(buff, ' ', spec->width - wclen);
	}
	pf_putwchar(buff, wc);
	if (spec->flags[e_flag_less])
		pf_printnchar(buff, ' ', spec->width - wclen);
	return (0);
}

int				print_ls(t_spec *spec, t_buff *buff, va_list *ap)
{
	wchar_t *str;
	int		len;

	str = (wchar_t *)va_arg(*ap, wchar_t*);
	len = 6;
	if (str != NULL && spec->precision != 0)
		len = ft_wstrlen(str);
	if (str != NULL && spec->precision > 0)
		spec->precision = wc_precision(str, spec->precision);
	padding_left(spec, len, buff);
	if (str == NULL)
		pf_printstr(buff, "(null)\0", spec->precision);
	else if (spec->precision != 0)
	{
		while (*str && spec->precision >= ft_wclen(*str))
		{
			pf_putwchar(buff, *str);
			spec->precision -= ft_wclen(*str);
			str = str + 1;
		}
	}
	if (spec->flags[e_flag_less])
		pf_printnchar(buff, ' ', spec->width);
	return (0);
}
