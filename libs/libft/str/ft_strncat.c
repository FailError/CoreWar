/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:03:57 by bharrold          #+#    #+#             */
/*   Updated: 2018/11/27 13:08:40 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *restrict s1, const char*restrict s2, size_t n)
{
	char	*head;

	head = s1;
	s1 += ft_strlen(s1);
	while (*s2 && n--)
		*s1++ = *s2++;
	*s1 = 0;
	return (head);
}
