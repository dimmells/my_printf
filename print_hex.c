/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:00:50 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/21 17:32:21 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			add_hash(t_specifier *ts, char **print, uintmax_t number)
{
	if (number != 0 && ts->hash == 1)
		*print = ft_strjoin("0x", *print);
}

static void			add_zero(t_specifier ts, char **print, uintmax_t number)
{
	int				count;

	if (ts.plus != 0)
		ts.width--;
	if (ts.hash == 1)
		ts.width -= 2;
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
	if (ts->length == ts->width)
		ts->width = ts->length;
	if (number == 0 && ts->precision == 0)
	{
		if (ts->width == 1)
			ts->width--;
		*itoa = ft_strdup("");
	}
	if (ts->minus || ts->precision > 0)
		ts->zero = 0;
}

static void			add_gifts(t_specifier *ts, char **print,
		unsigned int number, char **itoa)
{
	add_precision(*ts, *itoa, print);
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

int					print_hex(va_list list, char *sp, char type)
{
	unsigned int	number;
	char			*itoa;
	char			*print;
	t_specifier		ts;

	ts = struct_init();
	get_flag(&ts, sp);
	get_length(&ts, sp);
	itoa = get_argument_base(list, &ts, 16);
	ts.length = ft_strlen(itoa);
	number = 1;
	if (ft_atoi(itoa) == 0)
		number = 0;
	get_precision(&ts, sp, number);
	get_width(&ts, sp);
	setup(&ts, &itoa, number);
	print = (char*)malloc(sizeof(char));
	add_gifts(&ts, &print, number, &itoa);
	if (type == 'x')
		ft_putstr(print);
	else
		ft_putstr(ft_str_toupper(print));
	number = ft_strlen(print);
	return (number);
}
