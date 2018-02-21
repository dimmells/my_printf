/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:57:00 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/21 17:06:58 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		add_precision(t_specifier ts, char *itoa, char **print)
{
	ts.precision -= ft_strlen(itoa);
	while (ts.precision > 0)
	{
		*print = ft_strjoin(*print, "0");
		ts.precision--;
	}
	*print = ft_strjoin(*print, itoa);
}

void		add_precision_int(t_specifier ts, char *itoa, char **print)
{
	ts.precision -= ft_strlen(itoa);
	while (ts.precision > 0)
	{
		*print = ft_strjoin(*print, "0");
		ts.precision--;
	}
	*print = ft_strjoin(*print, itoa);
}
