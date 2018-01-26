/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:10:11 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/01/26 13:46:18 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_precision(t_specifier *ts, char *sp, int number)
{
	char	*tmp;

	if ((tmp = ft_strchr(sp, '.')))
	{
		tmp++;
		ts->precision = ft_atoi(tmp);
		if (ts->precision == 0 && number != 0)
			ts->precision++;
		else if (ts->precision == 0)
			ts->precision = 0;
	}
	else
		ts->precision = 0;
}
