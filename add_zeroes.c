/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_zeroes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:50:49 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/20 12:51:25 by dmelnyk          ###   ########.fr       */
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
			*print = strjoin_n_del("0", *print, 0);
			count--;
		}
	else if (ts.minus)
		while (count > 0)
		{
			*print = strjoin_n_del(*print, "0", 0);
			count--;
		}
}
