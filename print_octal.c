/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:00:50 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/21 17:55:28 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			add_hash(t_specifier *ts, char **print, uintmax_t number)
{
	if (ts->hash == 1 && number != 0)
	{
		*print = ft_strjoin("0", *print);
		ts->hash = 0;
	}
}

static void			add_zero(t_specifier ts, char **print, uintmax_t number)
{
	int				count;

	if (ts.plus != 0)
		ts.width--;
	if (ts.hash == 1)
		ts.width -= 1;
	count = ts.width - ft_strlen(*print);
	while (count > 0)
	{
		*print = ft_strjoin("0", *print);
		count--;
	}
	if (ts.space && ts.plus == 0)
		*print = ft_strjoin(" ", *print);
	add_hash(&ts, print, number);
}

static void			setup(t_specifier *ts, char **itoa, uintmax_t number)
{
	if (ts->width < ts->length)
		ts->width = ts->length;
	ts->plus = 0;
	ts->space = 0;
	ts->length = ft_strlen(*itoa);
	if (number == 0 && ts->precision == 0)
	{
		if (ts->width == 1)
			ts->width--;
		if (ts->hash == 0)
			*itoa = ft_strdup("");
	}
	if (ts->hash)
		ts->precision--;
	if (ts->minus || ts->precision > 0)
		ts->zero = 0;
}

static void			add_gifts(t_specifier *ts, char *itoa,
		char **print, unsigned int number)
{
	add_precision(*ts, itoa, print);
	if (ts->space)
		ts->width--;
	if (ts->zero)
		add_zero(*ts, print, number);
	else
	{
		add_hash(ts, print, number);
		add_space(*ts, print);
	}
}

int					print_octal(va_list list, char *sp, char type)
{
	unsigned int	number;
	char			*itoa;
	char			*print;
	t_specifier		ts;

	ts = struct_init();
	get_flag(&ts, sp);
	get_length(&ts, sp);
	if (type == 'O')
		ts.l = 1;
	itoa = get_argument_base(list, &ts, 8);
	ts.length = ft_strlen(itoa);
	number = 1;
	if (ft_atoi(itoa) == 0)
		number = 0;
	get_precision(&ts, sp, number);
	get_width(&ts, sp);
	setup(&ts, &itoa, number);
	print = (char*)malloc(sizeof(char));
	add_gifts(&ts, itoa, &print, number);
	ft_putstr(print);
	number = ft_strlen(print);
	return (number);
}
