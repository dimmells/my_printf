/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:16:37 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/01/26 13:07:23 by dmelnyk          ###   ########.fr       */
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
	(*(format)) += sp_len;
	if (type == 's' || type == 'S')
		length = print_str(list, sp);
	else if (type == 'd' || type == 'i')
		length = print_int(list, sp, sp_len);
	ft_strdel(&sp);
	return (length);
}
