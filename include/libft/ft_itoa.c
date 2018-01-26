/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:55:59 by dmelnyk           #+#    #+#             */
/*   Updated: 2017/11/02 14:30:13 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_fill(char *itoa, long int n1, long int del, int i)
{
	while (del != 1)
	{
		itoa[i++] = (n1 / (del /= 10)) + 48;
		n1 = n1 % del;
	}
	return (itoa);
}

char			*ft_itoa(int n)
{
	long int		del;
	long int		n1;
	int				i;
	size_t			k;
	char			*itoa;

	del = 10;
	k = 1;
	i = 0;
	n1 = (long int)n;
	if (n < 0)
	{
		n1 = n1 * -1;
		i = 1;
	}
	while (n1 / del != 0 && k++)
		del = del * 10;
	itoa = ft_strnew(k + i);
	if (itoa == NULL)
		return (NULL);
	if (i)
		itoa[0] = '-';
	return (ft_fill(itoa, n1, del, i));
}
