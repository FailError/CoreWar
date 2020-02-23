/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:28:03 by kturnips          #+#    #+#             */
/*   Updated: 2020/02/15 19:43:02 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_last_row(char *file)
{
	size_t i;

	i = ft_strlen(file) - 1;
	while (file[i] != '\n')
		--i;
	++i;
	while (file[i] && (file[i] == ' ' || file[i] == '\t'))
		++i;
	if (!is_comment(&file[i]) && file[i])
		return (0);
	return (1);
}

void	asm_read_cycle(t_asm *asm_ms)
{
	char	*file;
	char	temp1[10];
	char	*temp2;
	int		i;

	file = 0;
	while ((i = read(asm_ms->fd_r, temp1, 9)) > 0)
	{
		temp1[i] = '\0';
		if (!(temp2 = ft_strjoin(file, temp1)))
			asm_error(4, -1, asm_ms);
		if (file)
			free(file);
		file = temp2;
	}
	if (i == -1 || !file)
		asm_error(5, -1, asm_ms);
	if (!check_last_row(file))
		asm_error(6, -1, asm_ms);
	free(file);
}
