/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:00:50 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/21 12:15:13 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static int		setup(t_specifier *ts, char **itoa, int number)
{
	int			kostyl;

	if (number == 0 && ts->precision == 0)
	{
		ft_strdel(itoa);
		if (ts->width == 1)
			ts->width--;
		*itoa = ft_strdup("");
	}
	if (ts->minus || ts->precision > 0)
		ts->zero = 0;
	kostyl = 0;
	if (ts->plus < 0)
	{
		ts->space = 0;
		if (!ft_isdigit((*itoa)[0]))
			kostyl = 1;
	}
	return (kostyl);
}

int				print_int(va_list list, char *sp, char type)
{
	uintmax_t	number;
	int			kostyl;
	char		*itoa;
	char		*print;
	t_specifier	ts;

	ts = struct_init();
	get_flag(&ts, sp);
	get_length(&ts, sp);
	if (type == 'D')
		ts.l = 1;
	itoa = get_argument_int(list, &ts);
	ts.length = ft_strlen(itoa);
	number = 1;
	if (ts.plus < 0)
		number = -1;
	else if (ft_atoi(itoa) == 0)
		number = 0;
	get_precision(&ts, sp, number);
	get_width(&ts, sp);
	if (ts.width < ts.length)
		ts.width = ts.length;
	kostyl = setup(&ts, &itoa, number);
	print = (char*)malloc(sizeof(char));
	add_precision(ts, itoa + kostyl, &print);
	if (ts.space)
		ts.width--;
	if (ts.zero)
		add_zero(ts, &print);
	else
		add_space(ts, &print);
	ft_putstr(print);
	number = ft_strlen(print);
	ft_strdel(&print);
//	ft_strdel(&itoa);
	return (number);
}
