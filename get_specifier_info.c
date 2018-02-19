/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specifier_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:18:08 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/19 15:19:27 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*get_specifier_info(t_specifier *ts, char *sp, int number)
{
	char	*itoa;
	int		len;

	itoa = ft_itoa(number);
	ts->length = ft_strlen(itoa);
	get_precision(ts, sp, number);
	get_width(ts, sp);
	len = (int)ft_strlen(itoa);
	if (ts->width < len)
		ts->width = len;
	get_flag(ts, sp);
	get_length(ts, sp);
	return (itoa);
}
