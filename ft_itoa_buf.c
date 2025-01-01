/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_buf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkornato <wkornato@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 19:09:11 by wkornato          #+#    #+#             */
/*   Updated: 2025/01/01 19:33:00 by wkornato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	prepare_result(int n, char *result, size_t count)
{
	if (n < 0)
		result[0] = '-';
	else if (n == 0)
		result[0] = '0';
	result[count] = '\0';
}

/*Parameters num: the integer to convert
buf: the char array to save the result to
size: the size of the array
Return value: returns whether the number fits.
*/
bool	ft_itoa_buf(int num, char *buf, size_t size)
{
	int			is_negative;
	long int	number;
	size_t		count;

	is_negative = (num <= 0);
	count = is_negative;
	number = num;
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	if (count >= size)
		return (false);
	prepare_result(num, buf, count);
	number = num;
	number *= (!is_negative * 2 - 1);
	while (number != 0)
	{
		buf[--count] = (number % 10) + '0';
		number /= 10;
	}
	return (true);
}
