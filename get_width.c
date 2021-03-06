/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:12:21 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/19 15:18:40 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_width(t_specifier *ts, char *sp)
{
	int		i;

	i = 0;
	while (sp[i])
	{
		if (sp[i] == '0')
			i++;
		if (sp[i] == '.')
			break ;
		if (ft_isdigit((sp + i)[0]))
		{
			ts->width = (ft_atoi(sp + i));
			break ;
		}
		i++;
	}
}
