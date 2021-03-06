/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:45:32 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/21 17:08:19 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		add_sign(t_specifier ts, char **print)
{
	if (ts.plus == 1)
		*print = ft_strjoin("+", *print);
	if (ts.plus == -1)
		*print = ft_strjoin("-", *print);
}
