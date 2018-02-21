/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:00:50 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/21 12:17:50 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			add_hash(t_specifier *ts, char **print, uintmax_t number)
{
	if (ts->hash == 1 && number != 0)
	{
		*print = strjoin_n_del("0", *print, 0);
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
		*print = strjoin_n_del("0", *print, 0);
		count--;
	}
	if (ts.space && ts.plus == 0)
		*print = strjoin_n_del(" ", *print, 0);
	add_hash(&ts, print, number);
}

static void			setup(t_specifier *ts, char **itoa, uintmax_t number)
{
//	ft_strdel(itoa);
//	*itoa = itoa_base(number, 8);
	ts->plus = 0;
	ts->space = 0;
	ts->length = ft_strlen(*itoa);
	if (number == 0 && ts->precision == 0)
	{

		if (ts->width == 1)
			ts->width--;
		if (ts->hash == 0)
		{
//			ft_strdel(itoa);
			*itoa = ft_strdup("");
		}
	}
	if (ts->hash)
		ts->precision--;
	if (ts->minus || ts->precision > 0)
		ts->zero = 0;
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
	if (ts.width < ts.length)
		ts.width = ts.length;
	setup(&ts, &itoa, number);
	print = (char*)malloc(sizeof(char));
	add_precision(ts, itoa, &print);
	if (ts.space)
		ts.width--;
	if (ts.zero)
		add_zero(ts, &print, number);
	else
	{
		add_hash(&ts, &print, number);
		add_space(ts, &print);
	}
	ft_putstr(print);
	number = ft_strlen(print);
//	ft_strdel(&print);
//	ft_strdel(&itoa);
	return (number);
}
