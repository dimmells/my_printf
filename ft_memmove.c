/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:05:05 by dmelnyk           #+#    #+#             */
/*   Updated: 2017/11/04 17:09:36 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst1;
	unsigned char	*src1;

	dst1 = (unsigned char*)dst;
	src1 = (unsigned char*)src;
	if (dst1 > src1)
		while (len--)
			dst1[len] = src1[len];
	else
		dst1 = ft_memcpy(dst1, src1, len);
	return (dst);
}
