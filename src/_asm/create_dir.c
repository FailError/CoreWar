/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:21:52 by kturnips          #+#    #+#             */
/*   Updated: 2020/02/10 16:23:47 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		create_dir_arg_p2(char *to_parse, t_asm *asm_ms, t_token *token,
		int arg_nu)
{
	int to_add;

	to_add = 0;
	if (to_parse[1] == LABEL_CHAR)
	{
		if (arg_nu == 1)
			to_add = count_label(asm_ms, &(to_parse[2]), token->size1, token);
		if (arg_nu == 2)
			to_add = count_label(asm_ms, &(to_parse[2]), token->size2, token);
		if (arg_nu == 3)
			to_add = count_label(asm_ms, &(to_parse[2]), token->size3, token);
	}
	else
		to_add = ft_atoi_asm_ed(&(to_parse[1]));
	return (to_add);
}

int		create_dir_arg(t_token *token, int byte, int arg_nu, t_asm *asm_ms)
{
	char	*to_parse;
	int		to_add;
	int		res;

	if (arg_nu == 1)
		to_parse = token->arg1;
	else if (arg_nu == 2)
		to_parse = token->arg2;
	else
		to_parse = token->arg3;
	to_add = (create_dir_arg_p2(to_parse, asm_ms, token, arg_nu));
	if ((*(token->output) >= (char)9 && *(token->output) <= (char)12)
	|| ((*(token->output) >= (char)14 && *(token->output) <= (char)15)))
		res = add(token, to_add, byte, 2);
	else
		res = add(token, to_add, byte, 4);
	return (res);
}
