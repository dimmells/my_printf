/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:31:18 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/21 17:03:36 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		get_str_precision(t_specifier *ts, char *sp)
{
	char		*tmp;

	if ((tmp = ft_strchr(sp, '.')))
	{
		tmp++;
		ts->precision = ft_atoi(tmp);
	}
	else
		ts->precision = 1;
}

static void		print_with_space(t_specifier ts, char **print, unsigned char c)
{
	int		count;

	count = ts.width - ft_strlen(*print) - 1;
	if (!ts.minus)
	{
		while (count > 0)
		{
			if (ts.zero)
				*print = ft_strjoin("0", *print);
			else
				*print = ft_strjoin(" ", *print);
			count--;
		}
		ft_putstr(*print);
		ft_putchar(c);
	}
	else if (ts.minus)
	{
		ft_putchar(c);
		while (count > 0)
		{
			*print = ft_strjoin(*print, " ");
			count--;
		}
		ft_putstr(*print);
	}
}

int				print_char(va_list list, char *sp)
{
	char		c;
	char		*print;
	t_specifier	ts;

	ts = struct_init();
	get_length(&ts, sp);
	if (ts.l)
		return (print_wchar_t(list, sp));
	c = (unsigned char)va_arg(list, int);
	get_str_precision(&ts, sp);
	get_width(&ts, sp);
	if (ts.width == 1)
		ts.width = 0;
	get_flag(&ts, sp);
	print = ft_strnew(1);
	ts.length = ft_strlen(print);
	if (ts.width != 0)
		print_with_space(ts, &print, c);
	else
		ft_putchar(c);
	ts.length = ft_strlen(print) + 1;
	return (ts.length);
}
