/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:45:23 by dmelnyk           #+#    #+#             */
/*   Updated: 2017/11/01 13:59:36 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*tmp1;
	unsigned char		*tmp2;
	size_t				i;

	tmp1 = (unsigned char*)s1;
	tmp2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
		if (tmp1[i] != tmp2[i])
			return (tmp1[i] - tmp2[i]);
		else
			i++;
	return (0);
}
