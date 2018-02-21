/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:16:37 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/21 19:03:13 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_arg_two(va_list list, char type, char *sp)
{
	int		length;

	length = 0;
	if (type == 'u' || type == 'U')
		length = print_ui(list, sp, type);
	else if (type == 'c')
		length = print_char(list, sp);
	else if (type == 'C')
		length = print_wchar_t(list, sp);
	else if (type == 'p')
		length = print_pointer(list, sp);
	else if (type == 'o' || type == 'O')
		length = print_octal(list, sp, type);
	return (length);
}

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
	if (type == 's')
		length = print_str(list, sp);
	else if (type == 'S')
		length = print_wstr(list, sp);
	else if (type == 'd' || type == 'i' || type == 'D')
		length = print_int(list, sp, type);
	else if (type == '%')
		length = print_percent(sp);
	else if (type == 'x' || type == 'X')
		length = print_hex(list, sp, type);
	else
		length = print_arg_two(list, type, sp);
	return (length);
}
