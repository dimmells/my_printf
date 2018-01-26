/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:00:50 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/01/26 13:46:16 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
static void		add_precision(t_specifier ts, int number, char *itoa, char **print)
{
	int		del;

	del = 0;
	ts.precision -= ft_strlen(itoa);
	while (ts.precision > 0)
	{
		*print = strjoin_n_del(*print, "0", 1);
		del = 1;
		ts.precision--;
	}
	*print = strjoin_n_del(*print, itoa, 1);
}

static void		add_sign(t_specifier ts, char **print)
{
	if (ts.plus == 1)
		*print = strjoin_n_del("+", *print, 2);
	if (ts.plus == -1)
		*print = strjoin_n_del("-", *print, 2);
}

static void		add_zero(t_specifier ts, char **print)
{
	int			count;

	if (ts.plus != 0)
		ts.width--;
	count = ts.width - ft_strlen(*print);
	while (count > 0)
	{
		*print = strjoin_n_del("0", *print, 2);
		count--;
	}
	if (ts.space && ts.plus == 0)
		*print = strjoin_n_del(" ", *print, 2);
	add_sign(ts, print);
}

static void		add_spaces(t_specifier ts, char **print)
{
	int			count;

	add_sign(ts, print);
	if (ts.space && ts.plus == 0)
	{
		*print = strjoin_n_del(" ", *print, 2);
		ts.width++;
	}
	count = ts.width - ft_strlen(*print);
	while (count > 0)
	{
		if (!ts.minus)
			*print = strjoin_n_del(" ", *print, 2);
		else
			*print = strjoin_n_del(*print, " ", 1);
		count--;
	}
}

int				print_int(va_list list, char *sp, int sp_len)
{
	int			number;
	char		*itoa;
	char		*print;
	t_specifier	ts;

	ts = struct_init();
	number = va_arg(list, int);
	itoa = ft_itoa(number);
	ts.length = ft_strlen(itoa);
	get_precision(&ts, sp, number);
	get_width(&ts, sp, itoa);
	get_flag(&ts, sp);
	get_length(&ts, sp);
	if (ts.minus || ts.precision > 0)
		ts.zero = 0;
	if (number < 0)
	{
		ts.plus = -1;
		ts.space = 0;
		number *= -1;
		ft_strdel(&itoa);
		itoa = ft_itoa(number);
	}
	print = (char*)malloc(sizeof(char));
	add_precision(ts, number, itoa, &print);
	if (ts.space)
		ts.width--;
	if (ts.zero)
		add_zero(ts, &print);
	else
		add_spaces(ts, &print);
	ft_putstr(print);
	number = ft_strlen(print);
	ft_strdel(&print);
	ft_strdel(&itoa);
	return (number);
}
