/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbessa <kbessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:07:58 by kturnips          #+#    #+#             */
/*   Updated: 2020/02/16 19:03:10 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_strlen_asm(const unsigned char *str)
{
	if (str[3])
		return (4);
	else if (str[2])
		return (3);
	else if (str[1])
		return (2);
	else if (str[0])
		return (1);
	return (0);
}

int		add(t_token *token, int to_add, int byte, int size)
{
	int				len;
	unsigned char	*char_to_add;

	if (size == 2)
		to_add = (to_add >= 0) ? (unsigned short)to_add :
			(unsigned short)((~(unsigned)(-to_add) + 1));
	char_to_add = (unsigned char *)(&(to_add));
	len = ft_strlen_asm(char_to_add);
	while (++len <= size)
		token->output[byte++] = '\0';
	len = ft_strlen_asm(char_to_add);
	while (len--)
		token->output[byte++] = char_to_add[len];
	return (size);
}
