/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_call_manager.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 20:13:36 by bharrold          #+#    #+#             */
/*   Updated: 2019/02/01 15:10:25 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		set_conversion_group(t_spec *spec)
{
	static char	conv[10][4] = {"di", "ouxX", "p", "c", "s", "C", "S",
						"fF", "%", "\0"};
	int			i;
	int			j;

	i = 0;
	while (i < 9 && conv[i])
	{
		j = 0;
		while (j < 4 && conv[i][j])
		{
			if (spec->con == conv[i][j])
			{
				spec->conversion_group = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int				function_call_manager(t_spec *spec, t_buff *buff, va_list *ap)
{
	t_func func[9];

	set_conversion_group(spec);
	func[e_conv_di] = print_di;
	func[e_conv_oux] = print_oux;
	func[e_conv_p] = print_p;
	func[e_conv_c] = print_c;
	func[e_conv_s] = print_s;
	func[e_conv_lc] = print_lc;
	func[e_conv_ls] = print_ls;
	func[e_conv_prc] = print_prc;
	func[e_conv_f] = print_f;
	func[spec->conversion_group](spec, buff, ap);
	return (1);
}
