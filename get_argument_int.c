/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:26:31 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/20 15:36:59 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*get_argument_int(va_list list, t_specifier *ts)
{
	char		*argument;
	intmax_t	number;

	if (ts->h)
		number = (short)va_arg(list, int);
	else if (ts->hh)
		number = (signed char)va_arg(list, int);
	else if (ts->l)
		number = va_arg(list, long);
	else if (ts->ll)
		number = va_arg(list, long long);
	else if (ts->j)
		number = va_arg(list, intmax_t);
	else if (ts->z)
		number = va_arg(list, size_t);
	else
		number = va_arg(list, int);
	if (number < 0)
	{
		number *= -1;
		ts->plus = -1;
	}
	argument = itoa_base(number, 10);
	return (argument);
}
