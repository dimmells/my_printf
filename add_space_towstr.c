/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_space_towstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:43:59 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/21 13:13:34 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		add_space_towstr(t_specifier ts, char **print, wchar_t *wstr)
{
	int		count;

	count = ts.width - ft_wstrlen(wstr);
	if (!ts.minus)
		while (count > 0)
		{
			if (ts.zero)
				*print = strjoin_n_del("0", *print, 0);
			else
				*print = strjoin_n_del(" ", *print, 0);
			count--;
		}
	else if (ts.minus)
		while (count > 0)
		{
			*print = strjoin_n_del(*print, " ", 0);
			count--;
		}
}
