/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:53:08 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/21 18:31:51 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		list;
	int			length;

	va_start(list, format);
	length = 0;
	while (*format)
	{
		if (format[0] == '%')
		{
			length += print_arg(&format, list);
		}
		else
		{
			ft_putchar(format[0]);
			format++;
			length++;
		}
	}
	va_end(list);
	return (length);
}
