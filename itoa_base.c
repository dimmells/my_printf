/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:17:47 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/16 15:26:21 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			correct_result(uintmax_t number)
{
	if (number > 9)
		return (number - 10 + 'a');
	else
		return (number + '0');
}

static int			count_size(uintmax_t number, int base)
{
	int				count;

	count = 1;
	while (number / base != 0)
	{
		number = number / base;
		count++;
	}
	return (count);
}

char				*itoa_base(uintmax_t number, int base)
{
	int				count;
	char			*result;

	if (base < 0)
		return (NULL);
	count = count_size(number, base);
	result = ft_strnew(count);
	while (--count >= 0)
	{
		result[count] = correct_result(number % base);
		number = number / base;
	}
	result[count] = correct_result(number);
	return (result);
}
