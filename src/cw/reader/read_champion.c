/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:23:02 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 22:43:21 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <fcntl.h>

static t_ply	*s_read_champion_file(int fd, int id, t_cw *cw, uint8_t *code)
{
	char	*name;
	int		code_size;
	char	*comment;
	t_ply	*ply;

	read_magic(fd, cw);
	name = read_name(fd, cw);
	skip_bytes(fd, cw);
	code_size = read_code_size(fd, cw);
	comment = read_comment(fd, cw);
	skip_bytes(fd, cw);
	code = read_code(fd, code_size, cw);
	ply = set_ply_code(set_ply_code_size(new_ply(id, name, comment, code),
		code_size, cw), code, code_size, cw);
	free(name);
	free(comment);
	free(code);
	return (ply);
}

static void		s_read_champion(t_cw *cw, char *file, int id)
{
	int		fd;
	t_ply	*ply;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		terminate(7, cw);
	ply = s_read_champion_file(fd, id, cw, NULL);
	push_ply(cw, set_ply_file_path(ply, file, cw));
	if (close(fd) != 0)
		terminate(8, cw);
}

void			read_champion(t_cw *cw, char *file)
{
	s_read_champion(cw, file, -1);
}

void			read_n_flag(t_cw *cw, int *i, char **argv)
{
	int	id;

	*i += 1;
	if (!ft_isnumber(argv[*i]))
		terminate(5, cw);
	id = ft_atoi(argv[*i]);
	if (id < 1 || id > MAX_PLAYERS)
		terminate(5, cw);
	*i += 1;
	if (!cw_is_champion_file(argv[*i]))
		terminate(5, cw);
	s_read_champion(cw, argv[*i], id);
}
