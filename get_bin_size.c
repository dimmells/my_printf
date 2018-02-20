/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bin_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:25:27 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/20 13:04:31 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_bin_size(unsigned int wc)
{
	char	*itoa;
	int		size;

	itoa = itoa_base(wc, 2);
	size = ft_strlen(itoa);
//	ft_strdel(&itoa);
	return (size);
}
