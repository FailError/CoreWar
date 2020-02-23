/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:11:25 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/23 11:51:15 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	reader(t_cw *cw, int argc, char **argv)
{
	int		i;

	if (argc < 2)
		terminate(5, cw);
	i = 1;
	while (i < argc)
	{
		if (cw_is_flag(argv[i], "-dump") && (i + 1) < argc)
			read_dump_flag(cw, &i, argv);
		else if (cw_is_flag(argv[i], "-d") && (i + 1) < argc)
			read_d_flag(cw, &i, argv);
		else if (cw_is_flag(argv[i], "-v") && (i + 2) < argc)
			read_v_flag(cw, &i, argv);
		else if (cw_is_flag(argv[i], "-n") && (i + 2) < argc)
			read_n_flag(cw, &i, argv);
		else if (cw_is_flag(argv[i], "-a"))
			read_a_flag(cw, &i, argv);
		else if (cw_is_champion_file(argv[i]))
			read_champion(cw, argv[i]);
		else
			terminate(6, cw);
		i++;
	}
}
