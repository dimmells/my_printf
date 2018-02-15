/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specifier_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:18:08 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/15 14:09:06 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*get_specifier_info(t_specifier *ts, char *sp, int number)
{
	char	*itoa;

	itoa = ft_itoa(number);
	ts->length = ft_strlen(itoa);
	get_precision(ts, sp, number);
	get_width(ts, sp, itoa);
	get_flag(ts, sp);
	get_length(ts, sp);
	return (itoa);
}
