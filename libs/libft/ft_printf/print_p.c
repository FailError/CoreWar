/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:52:22 by bharrold          #+#    #+#             */
/*   Updated: 2019/02/01 14:28:55 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_p_buff(unsigned long long int num,
	t_spec *spec, t_buff *buff)
{
	int is_up;

	is_up = 0;
	spec->con == 'x' ? is_up = 32 : 1;
	if (num / spec->base != 0)
		print_p_buff(num / spec->base, spec, buff);
	ft_llabs(num % spec->base) <= 9 ?
	add_char_buff(buff, ft_llabs(num % spec->base) + '0') :
	add_char_buff(buff, (ft_llabs(num % spec->base)) + 'A' - 10 + is_up);
}

int				print_p(t_spec *spec, t_buff *buff, va_list *ap)
{
	int						size;
	unsigned long long int	num;

	num = (unsigned long long int)va_arg(*ap, unsigned long long int);
	size = pf_ulllen(num, spec);
	spec->precision -= size;
	if (spec->precision > 0)
		spec->width = spec->width - spec->precision - size - 2;
	else
		spec->width = spec->width - size - 2;
	if (is_space_printed(spec))
		pf_printnchar(buff, ' ', spec->width);
	pf_printstr(buff, "0x", 2);
	if (is_zero_printed(spec))
		pf_printnchar(buff, '0', spec->width);
	if (spec->precision > 0)
		pf_printnchar(buff, '0', spec->precision);
	if (size != 0)
	{
		spec->con = 'x';
		print_p_buff(num, spec, buff);
	}
	if (spec->width > 0 && spec->flags[e_flag_less] == 1)
		pf_printnchar(buff, ' ', spec->width);
	return (0);
}
