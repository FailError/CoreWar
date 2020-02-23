/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_champion_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:20:52 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:56:55 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			cw_is_champion_file(char *str)
{
	char *ptr;

	ptr = ft_strstr(str, ".cor");
	if (ptr == NULL)
		return (0);
	if (*(ptr + 4) == 0)
		return (1);
	return (0);
}
