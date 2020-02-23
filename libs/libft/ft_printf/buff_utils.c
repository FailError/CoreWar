/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 19:30:27 by bharrold          #+#    #+#             */
/*   Updated: 2019/02/01 15:14:38 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_buff(t_buff *buff, int fd)
{
	buff->done = 0;
	buff->ret = 0;
	buff->color_ret = 0;
	buff->fd = fd;
}

void	write_buff(t_buff *buff, int len)
{
	int tmp;

	tmp = write(buff->fd, buff->str, len);
	buff->done += tmp;
}

void	add_char_buff(t_buff *buff, char c)
{
	(buff->str)[buff->ret + buff->color_ret] = c;
	buff->ret += 1;
	if (buff->ret + buff->color_ret == BUFF_SIZE)
	{
		write_buff(buff, BUFF_SIZE);
		buff->ret = 0;
		buff->color_ret = 0;
	}
}

void	add_string_buff(t_buff *buff, const char *str)
{
	char	*ptr;

	ptr = (char*)str;
	while (*ptr)
		add_char_buff(buff, *ptr++);
}

void	add_color_string_buff(t_buff *buff, const char *color_str)
{
	char	*ptr;
	int		color_str_len;

	color_str_len = (int)ft_strlen(color_str);
	ptr = (char*)color_str;
	if (color_str_len < BUFF_SIZE)
		return ;
	if (color_str_len > BUFF_SIZE - buff->ret - buff->color_ret)
	{
		write_buff(buff, buff->ret + buff->color_ret);
		buff->ret = 0;
		buff->color_ret = 0;
	}
	while (*ptr)
	{
		(buff->str)[buff->ret + buff->color_ret] = *ptr;
		ptr++;
	}
	if (buff->ret + buff->color_ret == BUFF_SIZE)
		write_buff(buff, BUFF_SIZE);
}
