/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:31:18 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/01/26 13:14:52 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_space(int width, int len, char *str)
{
	int			count;

	if (width < 0)
	{
		count = (width * -1) - len;
		ft_putstr(str);
	}
	else
		count = width - len;
	while (count > 0)
	{
		ft_putchar(' ');
		count--;
	}
	if (width > 0)
		ft_putstr(str);
}

int				print_str(va_list list, char *sp)
{
	int			width;
	int			len;
	char		*str;
	char		*tmp;

	str = va_arg(list, char*);
	if ((tmp = ft_strchr(sp, '.')))
	{
		tmp++;
		len = ft_atoi(tmp);
	}
	else
		len = ft_strlen(str);
	tmp = ft_strsub(str, 0, len);
	width = ft_atoi(sp + 1);
	if (width != 0)
		print_space(width, len, tmp);
	else
		ft_putstr(tmp);
	ft_strdel(&tmp);
	return (0);
}
