/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbessa <kbessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 17:49:33 by kbessa            #+#    #+#             */
/*   Updated: 2020/02/12 17:49:35 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	direct_size(t_token *current)
{
	if (current->code_operation == 10 || current->code_operation == 11 ||
		current->code_operation == 14)
	{
		if (current->size1 == 0)
			current->size1 = 2;
		else if (current->size2 == 0)
			current->size2 = 2;
		else if (current->size3 == 0)
			current->size3 = 2;
	}
	else
	{
		if (current->size1 == 0)
			current->size1 = 4;
		else if (current->size2 == 0)
			current->size2 = 4;
		else if (current->size3 == 0)
			current->size3 = 4;
	}
}

void	indirect_size(t_token *current)
{
	if (current->size1 == 0)
		current->size1 = 2;
	else if (current->size2 == 0)
		current->size2 = 2;
	else if (current->size3 == 0)
		current->size3 = 2;
}

void	register_size(t_token *current)
{
	if (current->size1 == 0)
		current->size1 = 1;
	else if (current->size2 == 0)
		current->size2 = 1;
	else if (current->size3 == 0)
		current->size3 = 1;
}
