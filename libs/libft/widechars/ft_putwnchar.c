/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwnchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 22:13:33 by bharrold          #+#    #+#             */
/*   Updated: 2019/01/20 22:13:45 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwnchar(wchar_t wc, int n)
{
	int i;
	int done;

	done = 0;
	i = -1;
	while (++i < n)
		done += ft_putwchar(wc);
	return (done);
}
