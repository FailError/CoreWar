/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:41:27 by bharrold          #+#    #+#             */
/*   Updated: 2019/02/01 15:14:00 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lda_round_check(char *str, int remaind)
{
	char	*old;

	if (remaind && str[0] != '9')
	{
		str[0]++;
		return (str);
	}
	if (remaind && str[0] == '9')
	{
		old = str;
		str = ft_strnew(ft_strlen(old) + 1);
		ft_strcpy(str + 1, old);
		str[1] = '0';
		str[0] = '1';
		free(old);
		return (str);
	}
	else
		return (str);
}
