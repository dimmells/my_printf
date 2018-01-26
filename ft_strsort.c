/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 18:48:09 by dmelnyk           #+#    #+#             */
/*   Updated: 2017/11/05 19:29:07 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsort(char **strs)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;

	if (*strs == NULL)
		return (NULL);
	k = 0;
	while (strs[k])
		k++;
	i = -1;
	while (++i < k - 1)
	{
		j = i - 1;
		while (++j <= k - 1)
			if (ft_strcmp(strs[i], strs[j]) > 0)
			{
				tmp = strs[i];
				strs[i] = strs[j];
				strs[j] = tmp;
			}
	}
	return (strs);
}
