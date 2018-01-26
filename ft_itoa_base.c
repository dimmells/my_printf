/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:12:36 by dmelnyk           #+#    #+#             */
/*   Updated: 2017/11/07 16:17:34 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		ft_itoh(int i)
{
	if (i == 10)
		return ('A');
	if (i == 11)
		return ('B');
	if (i == 12)
		return ('C');
	if (i == 13)
		return ('D');
	if (i == 14)
		return ('E');
	return ('F');
}

char			*ft_itoa_base(int value, int base)
{
	char	*itoa;
	int		i;
	int		tmp;

	itoa = ft_strnew(8);
	i = 8;
	while (--i >= 0)
		itoa[i] = '0';
	i = 8;
	while (value != 0)
	{
		tmp = value % base;
		if (tmp > 9)
			itoa[--i] = ft_itoh(tmp);
		else
			itoa[--i] = tmp + '0';
		value /= base;
	}
	while (*itoa == '0')
		itoa++;
	return (itoa);
}
