/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:13:22 by bharrold          #+#    #+#             */
/*   Updated: 2018/11/26 15:18:17 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ptr;

	if (!(ptr = (void *)malloc(size)))
	{
		write(2, "Memory Allocation Error\n", 24);
		exit(-1);
	}
	ft_bzero(ptr, size);
	return (ptr);
}
