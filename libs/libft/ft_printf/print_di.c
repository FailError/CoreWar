/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 20:39:08 by bharrold          #+#    #+#             */
/*   Updated: 2019/02/01 14:32:50 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_di_buff(long long num, t_spec *spec, t_buff *buff)
{
	if (num < 0)
		num = num * -1;
	if (num / spec->base != 0)
		print_di_buff(num / spec->base, spec, buff);
	add_char_buff(buff, ft_llabs(num % spec->base) + '0');
}

static void		print_di_helper(t_spec *spec, t_buff *buff, long long num)
{
	t_padding	pad;

	init_padding(&pad, spec, pf_lllen(num, spec));
	if (num < 0)
		pad.sign = -1;
	calculate_padding(&pad, spec);
	print_padding(spec, pad, buff);
	if (!(num == 0 && spec->precision == 0))
		print_di_buff(num, spec, buff);
	if (spec->flags[e_flag_less])
		pf_printnchar(buff, ' ', pad.width);
}

int				print_di(t_spec *spec, t_buff *buff, va_list *ap)
{
	if (spec->modif == e_modif_no)
		print_di_helper(spec, buff, (int)va_arg(*ap, int));
	if (spec->modif == e_modif_hh)
		print_di_helper(spec, buff, (signed char)va_arg(*ap, int));
	if (spec->modif == e_modif_h)
		print_di_helper(spec, buff, (short)va_arg(*ap, int));
	else if (spec->modif == e_modif_l)
		print_di_helper(spec, buff, (long)va_arg(*ap, long));
	else if (spec->modif == e_modif_ll)
		print_di_helper(spec, buff, (long long)va_arg(*ap, long long));
	else if (spec->modif == e_modif_z)
		print_di_helper(spec, buff, (intmax_t)va_arg(*ap, intmax_t));
	else if (spec->modif == e_modif_j)
		print_di_helper(spec, buff, (ssize_t)va_arg(*ap, ssize_t));
	return (0);
}
