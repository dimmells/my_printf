/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar_t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:31:18 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/17 15:32:25 by dmelnyk          ###   ########.fr       */
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
			*print = strjoin_n_del(" ", *print, 2);
			count--;
		}
		ft_putstr(*print);
		ft_putwchar_t(c);
	}
	else if (ts.minus)
	{
		ft_putwchar_t(c);
		while (count > 0)
		{
			*print = strjoin_n_del(*print, " ", 1);
			count--;
		}
		ft_putstr(*print);
	}
}

int				print_wchar_t(va_list list, char *sp)
{
	char		c;
	char		*print;
	t_specifier	ts;

	c = (unsigned char)va_arg(list, int);
	ts = struct_init();
	get_str_precision(&ts, sp);
	get_width(&ts, sp, " ");
	if (ts.width == 1)
		ts.width = 0;
	get_flag(&ts, sp);
	print = ft_strnew(1);
	ts.length = ft_strlen(print);
	if (ts.width != 0)
		print_with_space(ts, &print, c);
	else
		ft_putwchar_t(c);
	ts.length = ft_strlen(print) + 1;
	ft_strdel(&print);
	return (ts.length);
}
