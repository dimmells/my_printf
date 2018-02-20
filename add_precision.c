/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:57:00 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/20 12:42:37 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		add_precision(t_specifier ts, char *itoa, char **print)
{
	ts.precision -= ft_strlen(itoa);
	while (ts.precision > 0)
	{
		*print = strjoin_n_del(*print, "0", 0);
		ts.precision--;
	}
	*print = strjoin_n_del(*print, itoa, 0);
}
