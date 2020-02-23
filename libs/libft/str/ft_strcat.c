/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:01:08 by bharrold          #+#    #+#             */
/*   Updated: 2018/11/27 12:56:58 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *restrict s1, const char*restrict s2)
{
	char	*head;

	head = s1;
	s1 += ft_strlen(s1);
	while (*s2)
		*s1++ = *s2++;
	*s1 = 0;
	return (head);
}
