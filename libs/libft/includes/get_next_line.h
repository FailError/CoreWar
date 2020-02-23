/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 07:11:59 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/14 21:31:26 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define GNL_BUFF 32
# define FD_SIZE 4864

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int		get_next_line(int const fd, char **line);

#endif
