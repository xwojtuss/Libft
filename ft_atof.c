/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkornato <wkornato@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:25:16 by wkornato          #+#    #+#             */
/*   Updated: 2024/11/01 12:13:22 by wkornato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_part(const char *str, int *i, int *offset)
{
	int	int_part;

	int_part = 0;
	*offset = 0;
	while (ft_isdigit(str[*i]))
	{
		int_part = int_part * 10 + (str[*i] - '0');
		(*i)++;
		(*offset)++;
	}
	return (int_part);
}

double	ft_atof(const char *str)
{
	double	result;
	int		i;
	int		offset;

	i = 0;
	result = 0;
	if (!str)
		return (0);
	if (str[0] == '-')
		i++;
	result = ft_atoi(str + i);
	i += ft_intlen_d(ft_atoi(str));
	if (str[i] == 'e' || str[i] == 'E')
	{
		result *= ft_pow(10, ft_atoi(str + ++i));
		i += ft_intlen(ft_atoi(str + i));
		return (result * ((str[0] != '-') * 2 - 1));
	}
	if (!str[i] || str[i] != '.' || !str[i + 1])
		return (result * ((str[0] != '-') * 2 - 1));
	i++;
	result += (double)get_part(str, &i, &offset) / ft_pow(10, offset);
	if (str[i] == 'e' || str[i] == 'E')
		result *= ft_pow(10, ft_atoi(str + ++i));
	return (result * ((str[0] != '-') * 2 - 1));
}
