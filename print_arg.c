/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:16:37 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/17 15:33:45 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_arg(const char **format, va_list list)
{
	char	*sp;
	char	type;
	int		sp_len;
	int		length;

	length = 0;
	sp_len = get_specifier_len(format);
	sp = ft_strsub(*format, 0, sp_len);
	type = (*format)[sp_len - 1];
	if (sp_len == 0)
		sp_len++;
	(*(format)) += sp_len;
	if (type == 's' || type == 'S')
		length = print_str(list, sp);
	else if (type == 'd' || type == 'i')
		length = print_int(list, sp);
	else if (type == '%')
		length = print_percent(sp);
	else if (type == 'x')
		length = print_hex(list, sp);
	else if (type == 'X')
		length = print_hex_upper(list, sp);
	else if (type == 'o')
		length = print_octal(list, sp);
	else if (type == 'u')
		length = print_ui(list, sp);
	else if (type == 'c')
		length = print_char(list, sp);
	else if (type == 'C')
		length = print_wchar_t(list, sp);
	ft_strdel(&sp);
	return (length);
}
