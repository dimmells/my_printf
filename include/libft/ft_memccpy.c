/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:00:17 by dmelnyk           #+#    #+#             */
/*   Updated: 2017/10/31 16:57:27 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	*res;

	tmp = (unsigned char*)src;
	res = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		res[i] = tmp[i];
		if (tmp[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
