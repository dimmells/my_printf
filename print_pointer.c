/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:00:50 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/21 18:00:28 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			add_hash(t_specifier *ts, char **print)
{
	if (ts->hash == 1)
		*print = ft_strjoin("0x", *print);
}

static void			add_zero(t_specifier ts, char **print)
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
	add_hash(&ts, print);
}

static void			setup(t_specifier *ts, char **itoa, uintmax_t number)
{
	int				len;

	len = ft_strlen(*itoa);
	*itoa = itoa_base(number, 16);
	ts->plus = 0;
	ts->space = 0;
	ts->length = ft_strlen(*itoa);
	ts->hash = 1;
	if (len == ts->width)
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

int					print_pointer(va_list list, char *sp)
{
	uintmax_t		number;
	char			*itoa;
	char			*print;
	t_specifier		ts;

	ts = struct_init();
	number = va_arg(list, uintmax_t);
	itoa = get_specifier_info(&ts, sp, number);
	setup(&ts, &itoa, number);
	print = (char*)malloc(sizeof(char));
	add_precision(ts, itoa, &print);
	if (ts.space)
		ts.width--;
	if (ts.zero)
		add_zero(ts, &print);
	else
	{
		add_hash(&ts, &print);
		add_space(ts, &print);
	}
	ft_putstr(print);
	number = ft_strlen(print);
	return (number);
}
