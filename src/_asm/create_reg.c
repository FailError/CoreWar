/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_reg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:26:20 by kturnips          #+#    #+#             */
/*   Updated: 2020/02/10 16:26:36 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		create_reg_arg(t_token *token, int byte, int arg_nu)
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
	to_add = ft_atoi_asm_ed(&(to_parse[1]));
	res = add(token, to_add, byte, 1);
	return (res);
}
