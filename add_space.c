/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:01:56 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/20 12:43:01 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			add_space(t_specifier ts, char **print)
{
	int			count;

	add_sign(ts, print);
	if (ts.space && ts.plus == 0)
	{
		*print = strjoin_n_del(" ", *print, 0);
		ts.width++;
	}
	count = ts.width - ft_strlen(*print);
	while (count > 0)
	{
		if (!ts.minus)
			*print = strjoin_n_del(" ", *print, 0);
		else
			*print = strjoin_n_del(*print, " ", 0);
		count--;
	}
}
