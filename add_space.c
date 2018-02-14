/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:43:59 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/14 15:02:50 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		add_space(t_specifier ts, char **print)
{
	int		count;

	count = ts.width - ft_strlen(*print);
	if (!ts.minus)
	while (count > 0)
	{
		*print = strjoin_n_del(" ", *print, 2);
		count--;
	}
	else if (ts.minus)
		while (count > 0)
		{
			*print = strjoin_n_del(*print, " ", 1);
			count--;
		}
}
