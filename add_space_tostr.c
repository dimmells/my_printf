/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_space_tostr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:43:59 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/21 16:58:39 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		add_space_tostr(t_specifier ts, char **print)
{
	int		count;

	count = ts.width - ft_strlen(*print);
	if (!ts.minus)
		while (count > 0)
		{
			if (ts.zero)
				*print = ft_strjoin("0", *print);
			else
				*print = ft_strjoin(" ", *print);
			count--;
		}
	else if (ts.minus)
		while (count > 0)
		{
			*print = ft_strjoin(*print, " ");
			count--;
		}
}
