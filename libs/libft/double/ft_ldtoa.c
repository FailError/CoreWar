/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:31:05 by bharrold          #+#    #+#             */
/*   Updated: 2019/01/31 18:52:27 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	** ft_ldtoa converts Double(Long Double) to ascii with precision
	** and rounds it;
*/

static char		*add_dot(char *str)
{
	char	*new;
	int		len;
	int		i;

	new = 0x0;
	if (str)
	{
		len = ft_strlen(str);
		new = (char*)malloc(sizeof(char) * (len + 2));
		i = -1;
		while (++i < len)
			new[i] = str[i];
		new[i++] = '.';
		new[i++] = 0;
		free(str);
	}
	return (new);
}

static char		*concat_itof(char *s1, char *s2)
{
	char			*ptr;
	long long int	len;

	ptr = NULL;
	if (s1)
	{
		len = (long long int)(ft_strlen(s1) + ft_strlen(s2));
		ptr = ft_strnew(len);
		if (ptr)
		{
			ft_strcpy(ptr, s1);
			if (s2)
				ft_strcat(ptr, s2);
		}
	}
	return (ptr);
}

static char		*round_lda(char *str, int precision, long double fpart,
															long long int ilen)
{
	char	*head;
	int		remaind;
	char	next;

	head = str;
	str += ((head[0] == '-') ? (ilen - 3) : (ilen - 2));
	if (precision && precision >= 51)
		str += ((head[0] == '-') ? 52 : 51);
	else if (precision && precision < 51)
		str += precision + ((head[0] == '-') ? 2 : 1);
	else
		str += (head[0] == '-') ? 2 : 1;
	next = (char)((int)(fpart * 10)) + '0';
	remaind = 0;
	*str += (remaind) ? remaind : 0;
	*str += (next >= '5' && next <= '9') ? 1 : 0;
	remaind = (*str >= '9') ? 1 : 0;
	*str -= (remaind) ? 1 : 0;
	while (str != head && *str != '.' && remaind)
	{
		remaind = (*str + remaind > '9') ? 1 : 0;
		*str += (remaind) ? -9 : 1;
		str--;
	}
	return (ft_lda_round_check(head, remaind));
}

static char		*make_lda(char *istr, char *fstr, long double fpart,
																int precision)
{
	char	*lda;

	lda = 0x0;
	if (precision > 0)
	{
		istr = add_dot(istr);
		lda = concat_itof(istr, fstr);
	}
	else
		lda = ft_strdup(istr);
	lda = round_lda(lda, precision, (fpart < 0) ? -fpart : fpart,
				ft_strlen(istr));
	free(istr);
	free(fstr);
	return (lda);
}

char			*ft_ldtoa(long double num, int precision)
{
	char			*str;
	char			*fstr;
	long double		fpart;
	int				ffpart;
	int				i;

	i = 0;
	if (ft_isnan(num) || ft_isinf(num))
		return ((ft_isnan(num) ? ft_strdup("nan") : ft_strdup("inf")));
	fpart = num - (long double)((long long int)num);
	str = ft_lltoa((long long int)num, 10);
	fstr = (char*)malloc(sizeof(char) * (precision + 1));
	fstr[precision] = 0;
	while (i < precision)
	{
		fpart *= (fpart < 0) ? -1 : 1;
		fpart *= 10;
		ffpart = (int)(fpart);
		fstr[i] = ffpart + '0';
		fpart -= (long double)ffpart;
		i++;
	}
	str = make_lda(str, fstr, fpart, precision);
	return (str);
}
