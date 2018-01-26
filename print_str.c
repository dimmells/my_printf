/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:31:18 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/01/26 17:52:23 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		add_space(int width, int len, char **print)
{
	int			count;

	if (width < 0)
		count = (width * -1) - len;
	else
		count = width - len;
	while (count > 0)
	{
		*print = strjoin_n_del(" ", *print, 2);
		count--;
	}
}

int				print_str(va_list list, char *sp)
{
	int			width;
	char		*str;
	char		*tmp;
	char		*print;
	t_specifier	ts;

	str = va_arg(list, char*);
/*	if ((tmp = ft_strchr(sp, '.')))
	{
		tmp++;
		len = ft_atoi(tmp);
	}
	else
		len = ft_strlen(str);*/
	ts = struct_init();
	get_width(&ts, sp, str);
	print = ft_strsub(str, 0, ts.width);
	width = ft_atoi(sp + 1);
	if (width != 0)
		add_space(width, ts.width, &print);
	ft_putstr(print);
	ft_strdel(&print);
	ft_strdel(&tmp);
	return (0);
}
