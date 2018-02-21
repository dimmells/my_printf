/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:00:50 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/21 11:48:48 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		*print = strjoin_n_del("0", *print, 0);
		count--;
	}
	if (ts.space && ts.plus == 0)
		*print = strjoin_n_del(" ", *print, 0);
}

static void			setup(t_specifier *ts, char **itoa, uintmax_t number)
{
	int				len;

	len = ft_strlen(*itoa);
	ts->plus = 0;
	ts->space = 0;
	ts->length = ft_strlen(*itoa);
	if (len == ts->width)
		ts->width = ts->length;
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

int					print_ui(va_list list, char *sp, char type)
{
	unsigned int	number;
	char			*itoa;
	char			*print;
	t_specifier		ts;

	ts = struct_init();
	get_flag(&ts, sp);
	get_length(&ts, sp);
	if (type == 'U')
		ts.l = 1;
	itoa = get_argument_base(list, &ts, 10);
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
	if (ts.zero)
		add_zero(ts, &print);
	else
		add_space(ts, &print);
	ft_putstr(print);
	number = ft_strlen(print);
//	ft_strdel(&print);
//	ft_strdel(&itoa);
	return (number);
}
