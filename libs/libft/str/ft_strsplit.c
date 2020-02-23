/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:35:18 by bharrold          #+#    #+#             */
/*   Updated: 2018/11/26 19:25:41 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_words_cnt(char const *s, char c)
{
	size_t	wordscnt;

	wordscnt = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			wordscnt++;
		while (*s && *s != c)
			s++;
	}
	return (wordscnt);
}

static size_t		ft_word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s == c)
		s++;
	while (*s && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		k;
	char		**split;

	if (!s
		|| !(split = (char**)malloc(sizeof(char*) * (ft_words_cnt(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_words_cnt(s, c))
	{
		k = 0;
		if (!(split[i] = ft_strnew(ft_word_len(&s[j], c) + 1)))
			split[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			split[i][k++] = s[j++];
		split[i][k] = '\0';
	}
	split[i] = 0;
	return (split);
}
