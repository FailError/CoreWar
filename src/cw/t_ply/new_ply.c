/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ply.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 19:14:30 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:54:11 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_ply	*new_ply(int number, char *name, char *comment, uint8_t *code)
{
	t_ply	*ply;

	if (!name || !comment)
		return (NULL);
	ply = (t_ply*)ft_memalloc(sizeof(t_ply));
	if (!ply)
		return (NULL);
	(void)code;
	ply->id = number;
	ply->name = ft_strdup(name);
	ply->comment = ft_strdup(comment);
	ply->file_path = NULL;
	ply->lives_num = 0;
	ply->live_cycle = 0;
	ply->next = NULL;
	ply->prev = NULL;
	return (ply);
}
