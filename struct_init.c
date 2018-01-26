/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 12:34:36 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/01/24 14:20:29 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_specifier		struct_init(void)
{
	t_specifier	ts;

	ts.minus = 0;
	ts.plus = 0;
	ts.space = 0;
	ts.hash = 0;
	ts.zero = 0;
	ts.hh = 0;
	ts.h = 0;
	ts.l = 0;
	ts.ll = 0;
	ts.j = 0;
	ts.z = 0;
	ts.width = 0;
	return (ts);
}
