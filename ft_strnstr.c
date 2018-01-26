/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:13:44 by dmelnyk           #+#    #+#             */
/*   Updated: 2017/11/04 15:12:43 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hstck, const char *ndl, size_t len)
{
	size_t	i;
	size_t	j;

	if (!(*ndl))
		return ((char*)hstck);
	i = 0;
	j = 0;
	while (hstck[i] && i <= len)
	{
		while (hstck[i] == ndl[j] && i <= len)
		{
			i++;
			j++;
			if (!ndl[j] && i <= len)
				return ((char*)(hstck + (i - j)));
			if (hstck[i] != ndl[j] && i <= len)
			{
				i -= j;
				j = 0;
				break ;
			}
		}
		i++;
	}
	return (NULL);
}
