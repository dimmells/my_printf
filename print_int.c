/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:00:50 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/21 17:47:01 by dmelnyk          ###   ########.fr       */
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
		*print = ft_strjoin("0", *print);
		count--;
	}
	if (ts.space && ts.plus == 0)
		*print = ft_strjoin(" ", *print);
	add_sign(ts, print);
}

static int		setup(t_specifier *ts, char **itoa, int number)
{
	int			kostyl;

	if (ts->width < ts->length)
		ts->width = ts->length;
	if (number == 0 && ts->precision == 0)
	{
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

static void		add_gifts(t_specifier ts, char *itoa, char **print, int kostyl)
{
	add_precision_int(ts, itoa + kostyl, print);
	if (ts.space)
		ts.width--;
	if (ts.zero)
		add_zero(ts, print);
	else
		add_space(ts, print);
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
	kostyl = setup(&ts, &itoa, number);
	print = (char*)malloc(sizeof(char));
	add_gifts(ts, itoa, &print, kostyl);
	ft_putstr(print);
	return (ft_strlen(print));
}
