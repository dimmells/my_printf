/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 13:31:05 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/18 15:26:47 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int			second_mask(unsigned int c, unsigned int mask)
{
	unsigned char	o2 = (c << 26) >> 26;
	unsigned char	o1 = ((c >> 6) << 27) >> 27;
	unsigned char	result;

	result = (mask >> 8) | o1;
	write(1, &result, 1);
	result = ((mask << 24) >> 24) | o2;
	write(1, &result, 1);
	return (2);
}

static int			third_mask(unsigned int c, unsigned int mask)
{
	unsigned char	o3 = (c << 26) >> 26;
	unsigned char	o2 = ((c >> 6) << 26) >> 26;
	unsigned char	o1 = ((c >> 12) << 28) >> 28;
	unsigned char	result;

	result = (mask >> 16) | o1;
	write(1, &result, 1);
	result = ((mask << 16) >> 24) | o2;
	write(1, &result, 1);
	result = ((mask << 24) >> 24) | o3;
	write(1, &result, 1);
	return (3);
}

static int			fourth_mask(unsigned int c, unsigned int mask)
{
	unsigned char o4 = (c << 26) >> 26;
	unsigned char o3 = ((c >> 6) << 26) >> 26;
	unsigned char o2 = ((c >> 12) << 26) >> 26;
	unsigned char o1 = ((c >> 18) << 29) >> 29;
	unsigned char	result;

	result = (mask >> 24) | o1;
	write(1, &result, 1);
	result = ((mask << 8) >> 24) | o2;
	write(1, &result, 1);
	result = ((mask << 16) >> 24) | o3;
	write(1, &result, 1);
	result = ((mask << 24) >> 24) | o4;
	write(1, &result, 1);
	return (4);
}

int					ft_putwchar_t(unsigned int wc)
{
	int				size;
	int				length;
	unsigned int	mask3;
	unsigned int	mask2;
	unsigned int	mask;

	mask = 49280;
	mask2 = 14712960;
	mask3= 4034953344;
	size = get_bin_size(wc);
	length = 1;
	if (size <= 7)
		write(1, &wc, 1);
	else if (size <= 11)
		length = second_mask(wc, mask);
	else if (size <= 16)
		length = third_mask(wc, mask2);
	else
		length = fourth_mask(wc, mask3);
	return (length);
}
