/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:26:17 by dmelnyk           #+#    #+#             */
/*   Updated: 2017/11/05 16:00:30 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
		i++;
	}
	return (dst);
}
