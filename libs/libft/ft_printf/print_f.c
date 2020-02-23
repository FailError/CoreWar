/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:25:08 by bharrold          #+#    #+#             */
/*   Updated: 2019/02/01 14:29:37 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_f_buff(char *str, t_spec *spec, t_buff *buff)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z' && spec->con == 'F')
			add_char_buff(buff, *str - 32);
		else
			add_char_buff(buff, *str);
		str++;
	}
}

static void		print_f_helper(t_spec *spec, t_buff *buff, long double num)
{
	t_padding	pad;
	char		*new;
	char		*old;
	int			len;

	new = ft_ldtoa(num, (spec->precision == -1) ? 6 : spec->precision);
	old = new;
	len = ft_strlen(new);
	init_padding(&pad, spec, len);
	if (old[0] == '-')
	{
		pad.sign = -1;
		new++;
	}
	print_padding(spec, pad, buff);
	print_f_buff(new, spec, buff);
	free(old);
}

int				print_f(t_spec *spec, t_buff *buff, va_list *ap)
{
	if (spec->modif == e_modif_ll)
		print_f_helper(spec, buff, (long double)va_arg(*ap, long double));
	else
		print_f_helper(spec, buff, (double)va_arg(*ap, double));
	return (0);
}
