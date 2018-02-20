/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:41:56 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/20 14:09:14 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_length(t_specifier *ts, char *sp)
{
	int		len_end;

	len_end = ft_strlen(sp) - 2;
	if (sp[len_end] == 'h')
	{
		if (sp[len_end - 1] == 'h')
			ts->hh = 1;
		else
			ts->h = 1;
		ts->is_it_have_size = 1;
	}
	else if (sp[len_end] == 'l')
	{
		if (sp[len_end - 1] == 'l')
			ts->ll = 1;
		else
			ts->l = 1;
		ts->is_it_have_size = 1;
	}
	else if (sp[len_end] == 'j')
	{
		ts->j = 1;
		ts->is_it_have_size = 1;
	}
	else if (sp[len_end] == 'z')
	{
		ts->z = 1;
		ts->is_it_have_size = 1;
	}
}
