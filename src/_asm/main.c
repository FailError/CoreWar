/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:55:04 by kturnips          #+#    #+#             */
/*   Updated: 2020/02/16 18:59:49 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "errors.h"

void	asm_error(int er_nu, int line, t_asm *asm_ms)
{
	er_nu == 0 ? ft_printf("%s\n", ERR_ARG_0) : 0;
	if (er_nu == 1)
		ft_printf(SOC"%s"EOC, ERR_FILE_EXT_1);
	else if (er_nu == 2)
		ft_printf(SOC"%s"EOC, ERR_OPEN_2);
	else if (er_nu == 3)
		ft_printf(SOC"%s"EOC, ERR_CREATE_3);
	else if (er_nu == 4)
		ft_printf(SOC"%s"EOC, ERR_MALLOC_4);
	else if (er_nu == 5)
		ft_printf(SOC"%s"EOC, ERR_READ_5);
	else if (er_nu == 6)
		ft_printf("%s "SOC"%s"EOC, asm_ms->file_name_s, ERR_EOF_6);
	else if (er_nu == 7)
		ft_printf(SOC"%s"EOC, ERR_CLOSE_7);
	else if (er_nu == 8)
		ft_printf("%s:%d "SOC"%s"EOC,
			asm_ms->file_name_s, line, ERR_COMMAND_8);
	else if (er_nu == 9)
		ft_printf("%s:%d "SOC"%s"EOC, asm_ms->file_name_s,
			line, ERR_TYPE_FIRST_ARG_9);
	else if (er_nu == 10)
		ft_printf("%s:%d "SOC"%s"EOC,
			asm_ms->file_name_s, line, ERR_TYPE_SECOND_ARG_10);
	asm_error_p2(er_nu, line, asm_ms);
}

int		asm_create_file(char *argv, t_asm *asm_ms)
{
	int		fd;
	char	*temp;

	if (!(temp = ft_strsub(argv, 0, ft_strlen(argv) - 2)))
		asm_error(4, -1, asm_ms);
	if (!(asm_ms->file_name_cor = ft_strjoin(temp, ".cor")))
		asm_error(4, -1, asm_ms);
	free(temp);
	fd = open(asm_ms->file_name_cor, O_RDWR | O_CREAT, S_IREAD | S_IWRITE);
	return (fd);
}

int		asm_check_name(char *argv, t_asm *asm_ms)
{
	int i;

	i = 0;
	asm_ms->file_name_s = argv;
	while (argv[i])
		++i;
	if (argv[i - 1] && argv[i - 1] == 's' && argv[i - 2] && argv[i - 2] == '.')
		return (1);
	return (0);
}

void	free_all(t_asm *asm_ms)
{
	t_label *curr;

	if (asm_ms->name)
		free(asm_ms->name);
	if (asm_ms->comment)
		free(asm_ms->comment);
	if (asm_ms->file_name_cor)
		free(asm_ms->file_name_cor);
	if (asm_ms->label)
	{
		curr = asm_ms->label;
		while (curr->next)
		{
			curr = asm_ms->label->next;
			free(asm_ms->label->name);
			free(asm_ms->label);
			asm_ms->label = curr;
		}
		free(asm_ms->label->name);
		free(asm_ms->label);
	}
	free_tokens(asm_ms);
}

int		main(int argc, char **argv)
{
	t_asm	asm_ms;

	init_asm_ms(&asm_ms);
	if (argc != 2)
		asm_error(0, -1, &asm_ms);
	if (!asm_check_name(argv[1], &asm_ms))
		asm_error(1, -1, &asm_ms);
	if ((asm_ms.fd_r = open(argv[1], O_RDONLY)) == -1)
		asm_error(2, -1, &asm_ms);
	asm_read_cycle(&asm_ms);
	if ((close(asm_ms.fd_r) == -1))
		asm_error(7, -1, &asm_ms);
	if ((asm_ms.fd_r = open(argv[1], O_RDONLY)) == -1)
		asm_error(2, -1, &asm_ms);
	parse_p1(&asm_ms);
	write_champ_code(&asm_ms);
	free_all(&asm_ms);
	return (0);
}
