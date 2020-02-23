/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:56:59 by bharrold          #+#    #+#             */
/*   Updated: 2019/02/01 14:28:21 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_oux_buff(unsigned long long int num,
	t_spec *spec, t_buff *buff)
{
	int is_up;

	is_up = 0;
	spec->con == 'x' ? is_up = 32 : 1;
	if (num / spec->base != 0)
		print_oux_buff(num / spec->base, spec, buff);
	ft_llabs(num % spec->base) <= 9 ?
	add_char_buff(buff, ft_llabs(num % spec->base) + '0') :
	add_char_buff(buff, (ft_llabs(num % spec->base)) + 'A' - 10 + is_up);
}

static void		print_oux_helper(t_spec *spec, t_buff *buff,
						unsigned long long num)
{
	t_padding	pad;

	init_padding(&pad, spec, pf_ulllen(num, spec));
	if (num == 0)
		pad.arg_zero = 1;
	calculate_padding(&pad, spec);
	print_padding(spec, pad, buff);
	if (!(num == 0 && spec->precision == 0))
		print_oux_buff(num, spec, buff);
	if (spec->flags[e_flag_less])
		pf_printnchar(buff, ' ', pad.width);
}

int				print_oux(t_spec *spec, t_buff *buff, va_list *ap)
{
	if (spec->modif == e_modif_no)
		print_oux_helper(spec, buff, (unsigned int)va_arg(*ap, unsigned int));
	if (spec->modif == e_modif_hh)
		print_oux_helper(spec, buff, (unsigned char)va_arg(*ap, unsigned int));
	if (spec->modif == e_modif_h)
		print_oux_helper(spec, buff, (unsigned short)va_arg(*ap, unsigned int));
	else if (spec->modif == e_modif_l)
		print_oux_helper(spec, buff, (unsigned long)va_arg(*ap, unsigned long));
	else if (spec->modif == e_modif_ll)
		print_oux_helper(spec, buff, (unsigned long long)va_arg(*ap,
													unsigned long long));
	else if (spec->modif == e_modif_z)
		print_oux_helper(spec, buff, (uintmax_t)va_arg(*ap, intmax_t));
	else if (spec->modif == e_modif_j)
		print_oux_helper(spec, buff, (size_t)va_arg(*ap, size_t));
	return (0);
}
