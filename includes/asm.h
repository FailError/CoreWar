/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:27:46 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/15 19:43:02 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <limits.h>
# include <fcntl.h>
# include "libft.h"
# include "op.h"

typedef struct		s_op
{
	char			*name;
	int				args_num;
	int				args_types[3];
	int				code;
	int				cycles;
	char			*description;
	int				args_types_code;
	int				t_dir_size;
}					t_op;

extern t_op			g_op_tab[17];

typedef struct		s_label
{
	char			*name;
	int				byte;
	struct s_label	*next;
}					t_label;

typedef struct		s_token
{
	char			*name;
	unsigned char	*output;
	int				code_operation;
	int				type_args;
	int				arg_numbers;
	char			*arg1;
	char			*arg2;
	char			*arg3;
	int				size1;
	int				size2;
	int				size3;
	int				command_size;
	int				current_line;
	int				index;
	int				len;
	struct s_token	*next;
}					t_token;

typedef struct		s_asm
{
	int				fd_r;
	int				fd_w;
	char			*file_name_cor;
	char			*name;
	char			*comment;
	char			*file_name_s;
	struct s_token	*first;
	struct s_label	*label;
	int				current_byte;
	int				current_line;
	int				current_column;
	int				len;
}					t_asm;

typedef struct		s_variables
{
	int a;
	int i;
	int j;
	int start;
}					t_var;

void				parse_p1(t_asm *asm_ms);
void				asm_read_cycle(t_asm *asm_ms);
void				asm_error(int er_nu, int line, t_asm *asm_ms);
int					is_space(char **str);
int					is_comment(char *str);
void				is_spacei(const char *s, int *i);
int					is_number_char(char c);
int					is_label_char(char c);
int					check_name_comment(char *str1, t_asm *asm_ms);
void				init_asm_ms(t_asm *asm_ms);
int					is_blank(char *str);
t_token				*init_token_p1(t_asm *asm_ms);
int					init_label(char **str, t_label *label, t_asm *asm_ms,
						int i);
int					check_label(char **str, t_asm *asm_ms);
void				write_champ_code(t_asm *asm_ms);
int					create_reg_arg(t_token *token, int byte, int arg_nu);
int					create_dir_arg(t_token *token, int byte, int arg_nu,
						t_asm *asm_ms);
int					create_ind_arg(t_token *token, int byte, int arg_nu,
						t_asm *asm_ms);
void				create_args(t_token *token, t_asm *asm_ms);
int					count_label(t_asm *asm_ms, char *str, int byte,
						t_token *token);
int					add(t_token *token, int to_add, int byte, int size);
int					check_command(t_asm *asm_ms, char *str, t_token *current);
int					one_argument(t_asm *asm_ms, char *str, t_token *current);
char				shell_arg_byte(int type_args);
int					main_cycle_two_three_arguments(t_asm *asm_ms, char *str,
						t_token *current);
void				save_all_info(t_asm *asm_ms, t_token *current);
int					ft_atoi_asm_ed(const char *str);
void				asm_error_p2(int er_nu, int line, t_asm *asm_ms);
void				check_name_p2(int i, t_asm *asm_ms);
void				check_comment_p2(int i, t_asm *asm_ms);
int					save_info_one_arg(t_asm *asm_ms, char *str,
						t_token *current, int last);
int					asm_create_file(char *argv, t_asm *asm_ms);
int					two_three_indirect_num(char *str, t_token *cur,
						t_asm *asm_ms, t_var *var);
int					two_three_register(char *str, t_token *current,
						t_asm *asm_ms, t_var *var);
int					two_three_indirect_label(char *str, t_token *cur,
						t_asm *asm_ms, t_var *var);
void				direct_size(t_token *current);
void				indirect_size(t_token *current);
void				register_size(t_token *current);
char				*ft_strsub2(char const *s, unsigned int start, size_t len);
void				save_arguments(char *str, t_token *current, t_var *var,
						t_asm *asm_ms);
void				free_tokens(t_asm *asm_ms);

#endif
