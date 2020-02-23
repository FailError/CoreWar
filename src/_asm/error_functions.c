/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:30:35 by kturnips          #+#    #+#             */
/*   Updated: 2020/02/16 20:41:32 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "errors.h"

void	asm_error_p3(int er_nu, int line, t_asm *asm_ms)
{
	if (er_nu == 19)
		ft_printf("%s:%d "SOC"%s"EOC,
			asm_ms->file_name_s, line, ERR_COMMENT_LENGTH_19);
	else if (er_nu == 20)
		ft_printf("%s:%d "SOC"%s"EOC,
			asm_ms->file_name_s, line, ERR_BAD_SYM_COMMENT_20);
	else if (er_nu == 21)
		ft_printf("%s:%d "SOC"%s"EOC,
			asm_ms->file_name_s, line, ERR_QUOT_NAME_21);
	else if (er_nu == 22)
		ft_printf("%s:%d "SOC"%s"EOC,
			asm_ms->file_name_s, line, ERR_QUOT_COMMENT_22);
	else if (er_nu == 23)
		ft_printf("%s:%d "SOC"%s"EOC,
			asm_ms->file_name_s, line, ERR_DOUBLE_NAME_23);
	else if (er_nu == 24)
		ft_printf("%s:%d "SOC"%s"EOC,
			asm_ms->file_name_s, line, ERR_DOUBLE_COMMENT_24);
	else if (er_nu == 25)
		ft_printf("%s:%d "SOC"%s"EOC,
			asm_ms->file_name_s, line, ERR_SYM_BEFORE_25);
	if (er_nu == 26)
		ft_printf("%s:%d "SOC"%s"EOC,
			asm_ms->file_name_s, line, ERR_QUOT_OR_CODE_6);
	exit(er_nu);
}

void	asm_error_p2(int er_nu, int line, t_asm *asm_ms)
{
	if (er_nu == 11)
		ft_printf("%s:%d "SOC"%s"EOC,
			asm_ms->file_name_s, line, ERR_TYPE_THIRD_ARG_11);
	else if (er_nu == 12)
		ft_printf("%s:%d "SOC"%s"EOC,
			asm_ms->file_name_s, line, ERR_ARG_NUMBER_12);
	else if (er_nu == 13)
		ft_printf("%s:%d "SOC"%s"EOC,
			asm_ms->file_name_s, line, ERR_LABEL_NAME_13);
	else if (er_nu == 14)
		ft_printf("%s:%d "SOC"%s"EOC,
			asm_ms->file_name_s, line, ERR_INSTR_FIRST_ARG_14);
	else if (er_nu == 15)
		ft_printf("%s:%d "SOC"%s"EOC,
			asm_ms->file_name_s, line, ERR_INSTR_SECOND_ARG_15);
	else if (er_nu == 16)
		ft_printf("%s:%d "SOC"%s"EOC,
			asm_ms->file_name_s, line, ERR_INSTR_THIRD_ARG_16);
	else if (er_nu == 17)
		ft_printf("%s:%d"SOC"%s"EOC,
			asm_ms->file_name_s, line, ERR_NAME_LENGTH_17);
	else if (er_nu == 18)
		ft_printf("%s:%d "SOC"%s"EOC,
			asm_ms->file_name_s, line, ERR_BAD_SYM_NAME_18);
	asm_error_p3(er_nu, line, asm_ms);
}
