/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 19:34:19 by bharrold          #+#    #+#             */
/*   Updated: 2019/01/30 18:43:51 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_flag(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ')
		return (1);
	return (0);
}

int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_precision(char c)
{
	if (c == '.')
		return (1);
	return (0);
}

int	is_modif(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	return (0);
}

int	is_conversion(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd'
	|| c == 'D' || c == 'o' || c == 'O' || c == 'u'
	|| c == 'U' || c == 'x' || c == 'X' || c == 'c'
	|| c == 'F' || c == 'f'
	|| c == 'C' || c == '%' || c == 'i')
		return (1);
	return (0);
}
