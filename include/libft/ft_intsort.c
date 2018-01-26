/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:19:40 by dmelnyk           #+#    #+#             */
/*   Updated: 2017/11/07 17:16:38 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		*ft_intsort(int *arr)
{
	int		k;
	int		i;
	int		j;
	int		tmp;

	k = 0;
	while (arr[k])
		k++;
	i = -1;
	while (++i < k - 1)
	{
		j = i - 1;
		while (++j <= k - 1)
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
	}
	return (arr);
}
