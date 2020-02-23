/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_champ_code.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:28:38 by kturnips          #+#    #+#             */
/*   Updated: 2020/02/11 23:34:00 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <errors.h>

void	write_magic_header(t_asm *asm_ms)
{
	char	*char_to_print;
	int		i;
	char	ch;

	ch = 0;
	i = COREWAR_EXEC_MAGIC;
	if (i != 15369203)
	{
		write(2, ERR_MAGICK_26"\n", 42);
		exit(26);
	}
	write(asm_ms->fd_w, &ch, 1);
	char_to_print = (char *)(&i);
	write(asm_ms->fd_w, &char_to_print[2], 1);
	write(asm_ms->fd_w, &char_to_print[1], 1);
	write(asm_ms->fd_w, &char_to_print[0], 1);
}

void	write_null(t_asm *asm_ms)
{
	char	c;
	int		i;

	c = 0;
	i = -1;
	while (++i < 4)
		write(asm_ms->fd_w, &c, 1);
}

void	write_size(t_asm *asm_ms)
{
	char	*size;
	int		len;

	size = (char *)(&(asm_ms->current_byte));
	len = ft_strlen(size);
	while (++len <= 4)
		write(asm_ms->fd_w, "\0", 1);
	len = ft_strlen(size);
	while (len--)
		write(asm_ms->fd_w, &size[len], 1);
}

void	write_code(t_asm *asm_ms)
{
	t_token *token;

	if (asm_ms->current_byte == 0 && !asm_ms->label)
		asm_error(26, asm_ms->current_line, asm_ms);
	token = asm_ms->first;
	while (token)
	{
		write(asm_ms->fd_w, token->output, token->len);
		token = token->next;
	}
}

void	write_champ_code(t_asm *asm_ms)
{
	if ((asm_ms->fd_w = asm_create_file(asm_ms->file_name_s, asm_ms)) == -1)
		asm_error(3, -1, asm_ms);
	write_magic_header(asm_ms);
	write(asm_ms->fd_w, asm_ms->name, PROG_NAME_LENGTH);
	write_null(asm_ms);
	write_size(asm_ms);
	write(asm_ms->fd_w, asm_ms->comment, COMMENT_LENGTH);
	write_null(asm_ms);
	write_code(asm_ms);
	if ((close(asm_ms->fd_w)) == -1)
		asm_error(7, -1, asm_ms);
	ft_printf("Writing output program to %s\n", asm_ms->file_name_cor);
}
