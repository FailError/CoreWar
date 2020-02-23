/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chtostr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:40:56 by bharrold          #+#    #+#             */
/*   Updated: 2019/01/21 15:41:52 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	** ft_chtostr convers char to string 'a' -> "a"
*/

char	*ft_chtostr(char c)
{
	char *new;

	new = (char*)malloc(sizeof(char) * (1 + 1));
	new[0] = c;
	new[1] = 0;
	return (new);
}
