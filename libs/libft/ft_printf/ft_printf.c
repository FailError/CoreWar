/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 19:30:21 by bharrold          #+#    #+#             */
/*   Updated: 2019/01/28 22:23:45 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	char	*ptr;
	t_buff	buff;
	t_spec	spec;
	va_list ap_copy;

	if (format == NULL)
		return (0);
	ptr = (char*)format;
	init_buff(&buff, fd);
	va_copy(ap_copy, ap);
	while (*ptr)
	{
		if (!(pf_read(&ptr, &buff, &spec)))
			return (-1);
		if (spec.con)
			if (!(function_call_manager(&spec, &buff, &ap_copy)))
				return (-1);
	}
	write_buff(&buff, buff.ret);
	va_end(ap_copy);
	return (buff.done);
}

int	ft_printf(const char *format, ...)
{
	int		done;
	va_list	ap;

	va_start(ap, format);
	done = ft_vdprintf(1, format, ap);
	va_end(ap);
	return (done);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	int		done;
	va_list	ap;

	va_start(ap, format);
	done = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (done);
}
