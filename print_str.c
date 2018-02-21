/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:31:18 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/21 19:07:11 by dmelnyk          ###   ########.fr       */
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
	else if (str)
		ts->precision = ft_strlen(str);
	else
		ts->precision = 1;
}

static void		setup(t_specifier *ts, char *str, char *sp)
{
	get_str_precision(ts, sp, str);
	get_width(ts, sp);
	if (str && ts->width == (int)ft_strlen(str))
		ts->width = 0;
	get_flag(ts, sp);
}

int				print_str(va_list list, char *sp)
{
	char		*str;
	char		*print;
	t_specifier	ts;

	ts = struct_init();
	get_length(&ts, sp);
	if (ts.l)
		return (print_wstr(list, sp));
	str = va_arg(list, char*);
	setup(&ts, str, sp);
	if (!str && ts.width == 0 && ts.precision != 0)
	{
		ft_putstr("(null)");
		return (6);
	}
	else if (str)
		print = ft_strsub(str, 0, ts.precision);
	else
		print = ft_strnew(1);
	ts.length = ft_strlen(print);
	if (ts.width != 0)
		add_space_tostr(ts, &print);
	ft_putstr(print);
	ts.length = ft_strlen(print);
	return (ts.length);
}
