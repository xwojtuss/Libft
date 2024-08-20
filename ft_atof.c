/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkornato <wkornato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:25:16 by wkornato          #+#    #+#             */
/*   Updated: 2024/08/20 11:37:05 by wkornato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_part(const char *str, int *i)
{
	int	int_part;

	int_part = 0;
	while (ft_isdigit(str[*i]))
	{
		int_part = int_part * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (int_part);
}

double	ft_atof(const char *str)
{
	double	result;
	int		i;
	bool	is_negative;

	i = 0;
	result = 0;
	if (!str)
		return (0);
	is_negative = (str[0] == '-' && i++ == 0);
	result = get_part(str, &i);
	if (str[i] == 'e' || str[i] == 'E')
	{
		i++;
		result *= ft_pow(10, ft_atoi(str + i));
	}
	if (!str[i] || str[i] != '.')
		return (result * (!is_negative * 2 - 1));
	i++;
	result += (double)get_part(str, &i) / ft_pow(10, ft_intlen_d(ft_atoi(str + i)));
	if (str[i] == 'e' || str[i] == 'E')
	{
		i++;
		result *= ft_pow(10, ft_atoi(str + i));
	}
	return (result * (!is_negative * 2 - 1));
}
