/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbessa <kbessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 17:08:20 by kbessa            #+#    #+#             */
/*   Updated: 2020/02/12 17:53:39 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_blank(char *str)
{
	int i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		++i;
	if (!(str[i]) || str[i] == COMMENT_CHAR || str[i] == ALT_COMMENT_CHAR)
	{
		free(str);
		return (1);
	}
	return (0);
}

char	*ft_strsub2(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!(new = ft_strnew(len)))
		return (NULL);
	if (s)
		while (i < len)
		{
			new[i] = s[start + i];
			i++;
		}
	return (new);
}

int		is_label_char(char c)
{
	int i;

	i = 0;
	while (LABEL_CHARS[i])
	{
		if (c == LABEL_CHARS[i])
			return (1);
		i++;
	}
	return (0);
}

int		is_number_char(char c)
{
	int i;

	i = 27;
	while (LABEL_CHARS[i])
	{
		if (c == LABEL_CHARS[i])
			return (1);
		i++;
	}
	return (0);
}

void	is_spacei(const char *s, int *i)
{
	while (s[*i] && (s[*i] == ' ' || s[*i] == '\t'))
		*i += 1;
}
