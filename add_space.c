/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:01:56 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/21 17:07:54 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			add_space(t_specifier ts, char **print)
{
	int			count;

	add_sign(ts, print);
	if (ts.space && ts.plus == 0)
	{
		*print = ft_strjoin(" ", *print);
		ts.width++;
	}
	count = ts.width - ft_strlen(*print);
	while (count > 0)
	{
		if (!ts.minus)
			*print = ft_strjoin(" ", *print);
		else
			*print = ft_strjoin(*print, " ");
		count--;
	}
}
