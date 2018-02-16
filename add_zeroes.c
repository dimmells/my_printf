/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_zeroes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:50:49 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/16 15:25:07 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		add_zeroes(t_specifier ts, char **print)
{
	int		count;

	count = ts.width - ft_strlen(*print);
	if (!ts.minus)
		while (count > 0)
		{
			*print = strjoin_n_del("0", *print, 2);
			count--;
		}
	else if (ts.minus)
		while (count > 0)
		{
			*print = strjoin_n_del(*print, "0", 1);
			count--;
		}
}
