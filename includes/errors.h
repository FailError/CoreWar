/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbessa <kbessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 21:18:58 by kbessa            #+#    #+#             */
/*   Updated: 2020/02/13 16:24:59 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_ARG_0					"Usage :\n\t ./asm [filename.s]"
# define ERR_FILE_EXT_1				"Error, wrong file extention"
# define ERR_OPEN_2					"Error, can't open file"
# define ERR_CREATE_3				"Error, can't create .cor file"
# define ERR_MALLOC_4				"Memory allocation error"
# define ERR_READ_5					"Read error"
# define ERR_QUOT_OR_CODE_6			"Error, no quotation / blank champion code"
# define ERR_EOF_6					"Error, no \\n at the end of the file"
# define ERR_CLOSE_7				"Error, can't close the file"
# define ERR_COMMAND_8				"Error, invalid command"
# define ERR_TYPE_FIRST_ARG_9		"Error, invalid type of first argument"
# define ERR_TYPE_SECOND_ARG_10		"Error, invalid type of second argument"
# define ERR_TYPE_THIRD_ARG_11		"Error, invalid type of third argument"
# define ERR_ARG_NUMBER_12			"Error, wrong arguments number"
# define ERR_LABEL_NAME_13			"Error, wrong label name"
# define ERR_INSTR_FIRST_ARG_14		"Error, invalid instruction in first arg"
# define ERR_INSTR_SECOND_ARG_15	"Error, invalid instruction in second arg"
# define ERR_INSTR_THIRD_ARG_16		"Error, invalid instruction in third arg"
# define ERR_NAME_LENGTH_17			"Error, invalid name length"
# define ERR_BAD_SYM_NAME_18		"Error, invalid symbols after name"
# define ERR_COMMENT_LENGTH_19		"Error, invalid comment length"
# define ERR_BAD_SYM_COMMENT_20		"Error, invalid symbol after comment"
# define ERR_QUOT_NAME_21			"Error, no quotation mark after .name"
# define ERR_QUOT_COMMENT_22		"Error, no quotation mark after .comment"
# define ERR_DOUBLE_NAME_23			"Error, second declaration of name"
# define ERR_DOUBLE_COMMENT_24		"Error, second declaration of comment"
# define ERR_SYM_BEFORE_25			"Error, symbols before .name/.comment"
# define ERR_MAGICK_26				"Error, the header file has been modified."

# define START_OF_COLOR				"\x1B[31m"
# define END_OF_COLOR				"\n\033[0m"
# define SOC						START_OF_COLOR
# define EOC						END_OF_COLOR

#endif
