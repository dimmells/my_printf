/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_wchar_t.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 13:31:05 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/19 11:33:31 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					get_size_wchar_t(unsigned int wc)
{
	int				size;

	size = get_bin_size(wc);
	if (size <= 7)
		return (1);
	else if (size <= 11)
		return (2);
	else if (size <= 16)
		return (3);
	else
		return (4);
}
