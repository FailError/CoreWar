/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:45:45 by bharrold          #+#    #+#             */
/*   Updated: 2018/11/26 19:55:30 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*plist;

	if (!(plist = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(plist->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(plist->content, content, content_size);
		plist->content_size = content_size;
	}
	else
	{
		plist->content = NULL;
		plist->content_size = 0;
	}
	plist->next = NULL;
	return (plist);
}
