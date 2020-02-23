/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:15:23 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:51:06 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		destroy_carry(t_carry *carry)
{
	if (!carry)
		return ;
	if (carry->next && carry->prev)
		carry->next->prev = carry->prev;
	else if (carry->prev && !carry->next)
		carry->prev->next = NULL;
	else if (carry->next && !carry->prev)
		carry->next->prev = NULL;
	free(carry);
	carry = NULL;
}

void		destroy_died_carry(t_cw *cw, t_carry *carry)
{
	if (!carry)
		return ;
	if (carry->next && carry->prev)
		carry->next->prev = carry->prev;
	else if (carry->prev && !carry->next)
		carry->prev->next = NULL;
	else if (carry->next && !carry->prev)
		carry->next->prev = NULL;
	(void)cw;
	if (cw->carries == carry)
		cw->carries = carry->next;
	free(carry);
	carry = NULL;
}
