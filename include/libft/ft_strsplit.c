/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:08:29 by dmelnyk           #+#    #+#             */
/*   Updated: 2017/11/07 21:19:04 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_wordcount(char const *s, char c)
{
	int		i;
	int		k;
	int		flag;

	flag = 0;
	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			flag = 0;
			i++;
		}
		else if (flag++ == 0)
			k++;
		else
			i++;
	}
	return (k);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		n;
	char	**split;

	if (!s)
		return (NULL);
	if (!(split = (char**)malloc(sizeof(char*) * (ft_wordcount(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_wordcount(s, c))
	{
		while (s[j] == c)
			j++;
		n = j;
		while (s[n] != c && s[n] != '\0')
			n++;
		split[i] = ft_strsub(s, j, n - j);
		if (!split[i])
			return (NULL);
		j = n;
	}
	split[i] = 0;
	return (split);
}
