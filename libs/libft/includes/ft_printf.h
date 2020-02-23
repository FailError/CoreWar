/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 19:30:24 by bharrold          #+#    #+#             */
/*   Updated: 2019/02/01 15:13:42 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft.h"
# include <wchar.h>

# define BUFF_SIZE 2048
# define FLAGS_CNT 5

/*
	** Colors define
*/

# define ANSI_COLOR_RED "\x1b[31m"
# define ANSI_COLOR_GREEN "\x1b[32m"
# define ANSI_COLOR_YELLOW "\x1b[33m"
# define ANSI_COLOR_BLUE "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN "\x1b[36m"
# define ANSI_COLOR_RESET "\x1b[0m"

/*
	** data structures
*/

typedef struct	s_buff
{
	char	str[BUFF_SIZE];
	size_t	done;
	int		ret;
	int		color_ret;
	int		fd;
}				t_buff;

typedef struct	s_spec
{
	int			flags[FLAGS_CNT];
	int			modif;
	char		con;
	int			base;
	int			precision;
	int			width;
	int			sign;
	int			conversion_group;
}				t_spec;

/*
	** Padding need only for dioux conversions
*/

typedef	struct	s_padding
{
	int			width;
	int			precision;
	int			sign;
	int			size;
	int			arg_zero;
}				t_padding;

/*
	** e_modif_xl - L modificator
*/

enum			e_flag
{
	e_flag_hashtag,
	e_flag_zero,
	e_flag_less,
	e_flag_more,
	e_flag_space,
};

enum			e_modif
{
	e_modif_no,
	e_modif_hh,
	e_modif_h,
	e_modif_ll,
	e_modif_l,
	e_modif_xl,
	e_modif_j,
	e_modif_z,
};

enum			e_conv_group
{
	e_conv_di,
	e_conv_oux,
	e_conv_p,
	e_conv_c,
	e_conv_s,
	e_conv_lc,
	e_conv_ls,
	e_conv_f,
	e_conv_prc,
};

typedef int	(*t_func) (t_spec *spec, t_buff *buff, va_list *ap);

/*
	** Main functions
*/

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_vdprintf(int fd, const char *format, va_list ap);

/*
	** Parsing functions
*/

int				pf_read(char **format, t_buff *buff, t_spec *spec);
int				is_flag(char c);
void			flag_recognition(char **format, t_spec *spec);
int				is_number(char c);
void			width_recognition(char **str, t_spec *spec);
int				is_precision(char c);
void			precision_recognition(char **str, t_spec *spec);
int				is_modif(char c);
void			modif_recognition(char **str, t_spec *spec);
int				is_conversion(char c);
void			conversion_recognition(char **str, t_spec *spec);

/*
	** Printing functions
*/

int				function_call_manager(t_spec *spec, t_buff *buff, va_list *ap);
int				print_di(t_spec *spec, t_buff *buff, va_list *ap);
int				print_oux(t_spec *spec, t_buff *buff, va_list *ap);
int				print_p(t_spec *spec, t_buff *buff, va_list *ap);
int				print_c(t_spec *spec, t_buff *buff, va_list *ap);
int				print_s(t_spec *spec, t_buff *buff, va_list *ap);
int				print_lc(t_spec *spec, t_buff *buff, va_list *ap);
int				print_ls(t_spec *spec, t_buff *buff, va_list *ap);
int				print_prc(t_spec *spec, t_buff *buff, va_list *ap);
int				print_prc(t_spec *spec, t_buff *buff, va_list *ap);
int				print_f(t_spec *spec, t_buff *buff, va_list *ap);

/*
	** Buff functions
*/

void			init_buff(t_buff *buff, int fd);
void			write_buff(t_buff *buff, int len);
void			add_char_buff(t_buff *buff, char c);
void			add_string_buff(t_buff *buff, const char *str);
void			add_color_string_buff(t_buff *buff, const char *color_str);
void			conversion_recognition(char **str, t_spec *spec);

/*
	** Padding utils
*/

void			init_padding(t_padding *pad, t_spec *spec, int size);
void			calculate_padding(t_padding *padding, t_spec *spec);
void			print_padding(t_spec *spec, t_padding pad, t_buff *buff);

/*
	**  Printing utils
*/

void			pf_printnchar(t_buff *buff, char c, int n);
void			pf_printstr(t_buff *buff, char *str, int precision);
void			pf_print_size_and_prefix(t_spec *spec, t_buff *buff,
				t_padding padding);

/*
	** Other utils
*/

int				is_conversion_signed(char c);
int				pf_lllen(long long arg, t_spec *spec);
int				pf_ulllen(unsigned long long arg, t_spec *spec);

int				is_zero_printed(t_spec *spec);
int				is_space_printed(t_spec *spec);

void			handle_bad_conv(char **str, t_spec *spec, t_buff *buff);
#endif
