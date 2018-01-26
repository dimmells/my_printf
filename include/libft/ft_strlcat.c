/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 12:55:33 by dmelnyk           #+#    #+#             */
/*   Updated: 2017/11/05 16:03:23 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	dlen;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dlen > dstsize)
		slen += dstsize;
	else
		slen += dlen;
	dlen = dstsize - dlen - 1;
	if ((int)dlen < 0)
		dlen = 0;
	dst = ft_strncat(dst, src, dlen);
	return (slen);
}
