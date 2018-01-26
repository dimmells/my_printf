/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 12:44:34 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/01/24 13:52:23 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_flag(t_specifier *ts, char *sp)
{
	int		i;

	i = 1;
	while (sp[i] == '-' || sp[i] == '+' || sp[i] == ' ' || sp[i] == '#' ||
			sp[i] == '0')
	{
		if (sp[i] == '-')
			ts->minus = 1;
		else if (sp[i] == '+')
			ts->plus = 1;
		else if (sp[i] == ' ')
			ts->space = 1;
		else if (sp[i] == '#')
			ts->hash = 1;
		else if (sp[i] == '0')
			ts->zero = 1;
		i++;
	}
}
