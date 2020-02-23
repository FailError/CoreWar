/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:14:35 by bharrold          #+#    #+#             */
/*   Updated: 2018/11/26 21:04:47 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *lstmap;
	t_list *ptr;

	lstmap = f(lst);
	ptr = lstmap;
	if (lst == NULL || lstmap == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		ptr->next = f(lst);
		if (ptr->next == NULL)
			return (NULL);
		ptr = ptr->next;
	}
	return (lstmap);
}
