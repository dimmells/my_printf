/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:26:31 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/20 15:56:59 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*get_argument_base(va_list list, t_specifier *ts, int base)
{
	char		*argument;
	intmax_t	number;

	if (ts->h)
		number = (unsigned short)va_arg(list, int);
	else if (ts->hh)
		number = (unsigned char)va_arg(list, int);
	else if (ts->l)
		number = va_arg(list, unsigned long);
	else if (ts->ll)
		number = va_arg(list, unsigned long long);
	else if (ts->j)
		number = va_arg(list, uintmax_t);
	else if (ts->z)
		number = va_arg(list, size_t);
	else
		number = va_arg(list, unsigned int);
	argument = itoa_base(number, base);
	return (argument);
}
