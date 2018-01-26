/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:50:44 by dmelnyk           #+#    #+#             */
/*   Updated: 2017/11/05 16:04:08 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		k;

	if (!needle[0])
		return ((char*)haystack);
	i = -1;
	while (haystack[++i])
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			k = i;
			while (needle[j])
				if (haystack[k++] == needle[j++])
					if (haystack[k] != needle[j])
						break ;
			if (!needle[j])
				return ((char*)(haystack + k - j));
		}
	}
	return (NULL);
}
