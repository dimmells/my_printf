/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:00:50 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/16 15:21:46 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			add_hash(t_specifier *ts, char **print)
{
	if (ts->hash == 1)
	{
		*print = strjoin_n_del("0", *print, 2);
		ts->hash = 0;
	}
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
		*print = strjoin_n_del("0", *print, 2);
		count--;
	}
	if (ts.space && ts.plus == 0)
		*print = strjoin_n_del(" ", *print, 2);
	add_hash(&ts, print);
}

static void			setup(t_specifier *ts, char **itoa, uintmax_t number)
{
	ft_strdel(itoa);
	*itoa = itoa_base(number, 8);
	ts->plus = 0;
	if (number == 0 && ts->precision == 0)
	{
		ft_strdel(itoa);
		if (ts->width == 1)
			ts->width--;
		*itoa = ft_strdup("");
	}
	if (ts->minus || ts->precision > 0)
		ts->zero = 0;
}

int					print_octal(va_list list, char *sp)
{
	unsigned int	number;
	char			*itoa;
	char			*print;
	t_specifier		ts;

	ts = struct_init();
	number = va_arg(list, unsigned int);
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
	ft_strdel(&print);
	ft_strdel(&itoa);
	return (number);
}
