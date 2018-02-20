/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:00:50 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/20 13:18:59 by dmelnyk          ###   ########.fr       */
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
		*print = strjoin_n_del("0", *print, 0);
		count--;
	}
	if (ts.space && ts.plus == 0)
		*print = strjoin_n_del(" ", *print, 0);
	add_sign(ts, print);
}

static int		setup(t_specifier *ts, char **itoa, int number)
{
	int			kostyl;

	if (number == 0 && ts->precision == 0)
	{
//		ft_strdel(itoa);
		if (ts->width == 1)
			ts->width--;
		*itoa = ft_strdup("");
	}
	if (ts->minus || ts->precision > 0)
		ts->zero = 0;
	kostyl = 0;
	if (number < 0)
	{
		ts->plus = -1;
		ts->space = 0;
		number *= -1;
		free(*itoa);
		*itoa = NULL;
//		ft_strdel(itoa);
		*itoa = ft_itoa(number);
		if (!ft_isdigit((*itoa)[0]))
			kostyl = 1;
	}
	return (kostyl);
}

int				print_int(va_list list, char *sp)
{
	int			number;
	int			kostyl;
	char		*itoa;
	char		*print;
	t_specifier	ts;

	print = (char*)malloc(sizeof(char) * 5);
	free(print);
	print = NULL;
	ts = struct_init();
	number = va_arg(list, int);
	itoa = get_specifier_info(&ts, sp, number);
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
//	ft_strdel(&print);
//	ft_strdel(&itoa);
	return (number);
}
