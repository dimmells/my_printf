/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 10:54:13 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/19 15:27:39 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		add_gifts(t_specifier ts, char **print)
{
	if (!ts.zero || ts.minus)
		add_space_tostr(ts, print);
	else if (!ts.minus)
		add_zeroes(ts, print);
}

int				print_percent(char *sp)
{
	t_specifier	ts;
	char		*print;

	print = ft_strdup("%");
	ts = struct_init();
	get_width(&ts, sp);
	get_flag(&ts, sp);
	if (ts.width < 1)
		ts.width = 1;
	if (ts.width > 1)
		add_gifts(ts, &print);
	ft_putstr(print);
	ft_strdel(&print);
	return (ts.width);
}
