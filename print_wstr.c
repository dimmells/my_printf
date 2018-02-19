/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:31:18 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/19 16:21:16 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_wstrlen(wchar_t *wstr)
{
	int			i;
	int			len;

	len = 0;
	i = 0;
	while (wstr[i])
	{
		len += get_size_wchar_t((unsigned int) wstr[i]);
		i++;
	}
	return (len);
}

static void		get_str_precision(t_specifier *ts, char *sp, wchar_t *wstr)
{
	char		*tmp;

	if ((tmp = ft_strchr(sp, '.')))
	{
		tmp++;
		ts->precision = ft_atoi(tmp);
	}
	else if (wstr)
		ts->precision = ft_wstrlen(wstr);
	else
		ts->precision = 1;
}

int				print_wstr(va_list list, char *sp)
{
	wchar_t		*wstr;
	char		*print;
	t_specifier	ts;

	wstr = va_arg(list, wchar_t*);
	ts = struct_init();
	get_str_precision(&ts, sp, wstr);
	get_width(&ts, sp);
	if (wstr && ts.width == ft_wstrlen(wstr))
		ts.width = 0;
	get_flag(&ts, sp);
	if (!wstr && ts.width == 0 && ts.precision != 0)
	{
		ft_putstr("(null)");
		return (6);
	}
	print = (char*)malloc(sizeof(char) * 1);
	ts.length = ft_wstrlen(wstr);
	if (ts.width != 0)
		add_space_tostr(ts, &print);
	if (!ts.minus)
	{
		ft_putstr(print);
		ft_putwstr(wstr);
	}
	else
	{
		ft_putstr(print);
		ft_putwstr(wstr);
	}
	ts.length += ft_strlen(print);
	ft_strdel(&print);
	return (ts.length);
}
