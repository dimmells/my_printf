/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_zeroes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:50:49 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/21 17:57:09 by dmelnyk          ###   ########.fr       */
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
			*print = ft_strjoin("0", *print);
			count--;
		}
	else if (ts.minus)
		while (count > 0)
		{
			*print = ft_strjoin(*print, "0");
			count--;
		}
}
