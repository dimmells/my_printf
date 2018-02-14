/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:31:18 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/14 14:46:58 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		get_str_precision(t_specifier *ts, char *sp, char *str)
{
	char		*tmp;

	if ((tmp = ft_strchr(sp, '.')))
	{
		tmp++;
		ts->precision = ft_atoi(tmp);
	}
	else
		ts->precision = ft_strlen(str);
}

int				print_str(va_list list, char *sp)
{
	char		*str;
	char		*print;
	t_specifier	ts;

	str = va_arg(list, char*);
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	ts = struct_init();
	get_str_precision(&ts, sp, str);
	get_width(&ts, sp, str);
	if (ts.width == (int)ft_strlen(str))
		ts.width = 0;
	get_flag(&ts, sp);
	print = ft_strsub(str, 0, ts.precision);
	ts.length = ft_strlen(print);
	if (ts.width != 0)
		add_space(ts, &print);
	ft_putstr(print);
	ts.length = ft_strlen(print);
	ft_strdel(&print);
	return (ts.length);
}
